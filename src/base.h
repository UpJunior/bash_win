#ifndef _BASE_H_
#define _BASE_H_

#include <iostream>
#include <string>
#include <map>

using std::string;
using std::map;
using std::cout;
using std::endl;

typedef void* (*fn)();
class Base {

public:
    Base(){}
    ~Base(){}

    static Base* get_instance() {
        if (base == NULL) {
            base = new Base();
            return base;
        }
        return base;
    }
    void register_command(string name, fn func){
        func_map[name] = func;
        cout << "registe funcion: " << name<<  endl;
    }
    void* get_funcby_name(string &name) {
        fn func = func_map[name];
        if (func == NULL) {
            return NULL;
        }
        return func();
    }

private:
    static Base *base;
    static map<string, fn> func_map;

};

void init_command();






#endif