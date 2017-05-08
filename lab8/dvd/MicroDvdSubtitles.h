//
// Created by xxx on 08.05.17.
//

#ifndef JIMP_EXERCISES_MOVIESUBTITLES_H
#define JIMP_EXERCISES_MOVIESUBTITLES_H


#include <vector>
#include <string>
#include <fstream>

namespace moviesubs{
class MicroDvdSubtitles {
public:
    void static ShiftAllSubtitlesBy(int delay, int frame_rate, std::stringstream *input_file,
                                    std::stringstream *output_file);
private:
    void static delay(int delay, int frame_rate, const std::string input_file, const std::string output_file);
    std::vector<std::string> static readLines(const std::string input_file);
    std::string static delayLine(const std::string line, int delay, int frame_rate);
    void static validateLineFormat(const std::string line);
    void static writeToFile(const std::string output_file, std::vector<std::string> lines);
};
}

#endif //JIMP_EXERCISES_MOVIESUBTITLES_H
