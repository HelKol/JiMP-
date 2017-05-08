//
// Created by xxx on 08.05.17.
//
#include "Exception.h"
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
    vector<string> lines = readLines(in->str());
    for (auto &line : lines) {
        line = delayLine(line, delay, framerate);
    }
    writeToFile(out, lines);
}

void MicroDvdSubtitles::writeToFile(const string output_file, vector<string> lines) {
    std::ofstream file;
    file.open(output_file, std::ofstream::out | std::ofstream::trunc);

    if (file.fail()) {
        throw NoFileException("No output file in given path.");
    }

    for (auto & line : lines) {
        file << line << "\n";
    }
    file.close();
}
vector<string> MicroDvdSubtitles::readLines(const string input_file) {
    string line;
    vector<string> lines;
    ifstream file(input_file);

    if (file.fail()) {
        throw NoFileException("No input.");
    }

    while (getline(file, line)) {
        lines.push_back(line);
    }

    file.close();

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
        throw InvalidSequenceException("Syntax error");
    }
}
}