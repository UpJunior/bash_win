#ifndef _CLASS_FACTORY_
#define _CLASS_FACTORY_

#include <iostream>
#include <map>
#include <string>
using namespace std;

typedef void* (*fn)();

class ClassFactory{

public:

    // TODO  析构函数的作用？
    ClassFactory(){
        cout << "create factory" << endl;
    }
    ~ClassFactory() {
        cout << "delete factory" << endl;
        cout << factory << endl;
    }

    void* getClassByName(string name) {
        map<string, fn>::iterator it = funcMap.find(name);
        if (it == funcMap.end()) {
            return NULL;
        }
        fn func = it->second;
        if (!func) {return NULL;}
        return func();
    }

    void registerFunc(string name, fn func) {
        funcMap[name] = func;
    }

    static ClassFactory* getInstance() {
        if (factory == NULL) {
            factory = new ClassFactory();
            return factory;
        }
        return factory;
    }

private:

    static ClassFactory* factory;
    map<string, fn> funcMap;
};

#endif