#ifndef JIMP_EXERCISES_EXCEPTION_H
#define JIMP_EXERCISES_EXCEPTION_H

#include <string>

using std::string;

class Exception{
protected:
    string message_;
public:
    Exception(string message);
    string message() const;
};

class InvalidSequenceException : public Exception{
public:
    InvalidSequenceException(string message);
};
class NoFileException : public Exception {
public:
    NoFileException(string message);
};

#endif //JIMP_EXERCISES_EXCEPTION_H