#ifndef _REGISTER_H_
#define _REGISTER_H_

#include "base.h"

class Register{

private:
    static Register* _reg;
public:
    unordered_map<string, func_ptr> func_list;
    Register(){}
    ~Register(){}

    static Register* get_instance() {
        if (_reg == NULL) {
            _reg = new Register();
            return _reg;
        }
        return _reg;
    }

    void regiser_func(string &name, func_ptr fn_ptr) {
        func_list[name] = fn_ptr;
        cout << "register function:" << name << endl;
    }

    func_ptr get_func_ptr(string &name) {
       func_ptr fn_ptr = func_list[name];
        if (fn_ptr == NULL) {
            return NULL;
        }
        return fn_ptr;
    }
};


#endif