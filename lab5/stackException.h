#ifndef PRG_5_STACKEXCEPTION_H
#define PRG_5_STACKEXCEPTION_H

#include <string>

class StackException :public std::exception {
public:
    StackException(std::string msg):std::exception() {
        message = msg;
    }
    void what() {
        std::cerr << message << std::endl;
    }
private:
    std::string message;
};
#endif
