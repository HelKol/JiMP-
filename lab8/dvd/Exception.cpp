#include "Exception.h"

Exception::Exception(string message) : message_(message){}
string Exception::message() const {
    return message_;
}
InvalidSequenceException::InvalidSequenceException(string message) : Exception(message){}
NoFileException::NoFileException(string message) : Exception(message){}