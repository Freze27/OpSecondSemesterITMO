#include "error.h"

Error::Error(std::string err, int code) : err(err), code(code) {}

int Error::type() {
    return code;
}

std::string Error::letter() {
    return err;
}