#ifndef _BASE_H_
#define _BASE_H_

#include <unordered_map>
#include <iostream>
#include <string>

using std::unordered_map;
using std::string;
using std::cout;
using std::cin;
using std::endl;


typedef void* (*func_ptr)();

class Base {

private:
    Base* base;
public:
    Base(){}
    virtual ~Base() = delete;
    virtual bool run() = 0;
};

#endif