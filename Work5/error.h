#ifndef LAB5_ERROR_H
#define LAB5_ERROR_H

#include <string>

class Error {
private:
    std::string err;
    int code;
public:
    Error(std::string err, int code);
    int type();
    std::string letter();
};


#endif
