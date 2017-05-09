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

    class Exception : public std::runtime_error{
    protected:
        int line;

    public:
        virtual int LineAt() const { return line; }
        Exception(std::string str, int line) : line(line), std::runtime_error(str) {}
    };


    class NegativeFrameAfterShift : public Exception {
    public:
        NegativeFrameAfterShift(string message, int line);
    };

    class SubtitleEndBeforeStart : public Exception {
    public:
        SubtitleEndBeforeStart(string message, int line);
    };

    class InvalidSubtitleLineFormat : public Exception {
    public:
        InvalidSubtitleLineFormat(string message, int line);
    };
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
