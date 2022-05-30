#ifndef CONVERT_H
#define CONVERT_H
#include <string>

class Convert {
    public:
        std::string do_prefix(std::string s);
    private:
        int do_operate(std::string op, int a, int b);
};

#endif

