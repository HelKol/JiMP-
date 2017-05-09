//
// Created by xxx on 08.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <vector>
#include <string>
#include <fstream>
#include <stdexcept>

using std::string;
namespace moviesubs{
    class MicroDvdSubtitles {
    public:
        void static ShiftAllSubtitlesBy(int delay, int frame_rate, std::stringstream *input,
                                        std::stringstream *output);
    private:
        std::vector<std::string> static readLines( std::string input);
        std::string static delayLine(const std::string line, int delay, int frame_rate);
        void static validateLineFormat(const std::string line);
    };

    class Exception{
    protected:
        int line;
        string msg;
    public:
        virtual int LineAt() const { return line; }
        Exception(std::string msg);
        string message() const;
    };


    class NegativeFrameAfterShift : public Exception {
    public:
        NegativeFrameAfterShift(std::string message);
    };

    class SubtitleEndBeforeStart : public Exception {
    public:
        SubtitleEndBeforeStart(std::string message);
    };

    class InvalidSubtitleLineFormat : public Exception {
    public:
        InvalidSubtitleLineFormat(string message);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
