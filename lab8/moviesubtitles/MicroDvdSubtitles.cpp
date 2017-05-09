//
// Created by xxx on 08.05.17.
//
#include "MicroDvdSubtitles.h"

#include <fstream>
#include <regex>
#include <sstream>
#include <cmath>

using std::vector;
using std::string;
using std::ifstream;
using std::getline;
using std::regex;
using std::to_string;
using std::stringstream;

    namespace moviesubs{
    void MicroDvdSubtitles::ShiftAllSubtitlesBy(int delay, int framerate, stringstream *in, stringstream *out){
        vector<string> lines= readLines(in->str());
        string result;
        for (auto &line : lines){
            line = delayLine(line, delay, framerate);
            result+=line+"\n";
        }
        *out<<result;

    }

    vector<string> MicroDvdSubtitles::readLines(const string input) {
        vector<string> lines;
        string buff="";
        for(int i=0; i<input.length();i++){
            if(input[i]=='\n'){
                lines.push_back(buff);
                buff="";
            }else{
                buff+=input[i];
            }
        }
        if(buff!=""){
            lines.push_back(buff);
        }
        return lines;
    }
    string MicroDvdSubtitles::delayLine(const string line, int delay, int frame_rate) {
        validateLineFormat(line);

        stringstream new_line(line);
        string text;
        int start;
        int end;

        new_line.ignore(1, '{');
        new_line>> start;
        new_line.ignore(1, '}');
        new_line.ignore(1, '{');
        new_line>> end;
        new_line.ignore(1, '}');
        getline(new_line, text);

        const int c = (int)floor(frame_rate * ((double)delay/1000));

        return "{"+to_string(start + c)+"}{"+to_string(end + c)+"}"+text;
    }
    void MicroDvdSubtitles::validateLineFormat(const string line) {
        regex expression("^(\\{\\d+\\}\\{\\d+\\}).+$");
        if (!regex_match(line, expression)) {
//            throw InvalidSubtitleLineFormat("Syntax error");
        }
    }

    Exception::Exception(string message) : msg(message){};
    string Exception::message() const {
        return msg;}

    NegativeFrameAfterShift::NegativeFrameAfterShift(string msg) : Exception(msg){};

    SubtitleEndBeforeStart::SubtitleEndBeforeStart(string msg) : Exception(msg){};

    InvalidSubtitleLineFormat::InvalidSubtitleLineFormat(string msg) : Exception(msg){};
}