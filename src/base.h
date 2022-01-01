#ifndef _BASE_H_
#define _BASE_H_

#include <cstdio>
#include <unistd.h>
#include <unordered_map>
#include <iostream>
#include <string>
#include <string.h>


using std::unordered_map;
using std::string;
using std::cout;
using std::cin;
using std::endl;

#ifdef __linux__
    #include <dlfcn.h>
    #include <sys/utsname.h>
    #define LIBTYPE void*
    #define OPENLIB(libname) dlopen((libname), RTLD_LAZY)
    #define LIBFUNC(lib, fn) dlsym((lib), (fn))
#elif defined(WINVER)
    #include <windows.h>
    #define LIBTYPE HINSTANCE
    #define OPENLIB(libname) LoadLibraryW(L ## libname)
    #define LIBFUNC(lib, fn) GetProcAddress((lib), (fn))
#endif

typedef int func_ptr();

class Base {

private:
    static Base* base;
public:
    Base(){}
    ~Base(){}
    static Base* gen_instance() {
        if (base == NULL) {
            base = new Base();
            return base;
        }   
        return base;
    }
};

#endif