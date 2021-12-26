#include "class_factory.h"
ClassFactory* ClassFactory::factory = NULL;
void test_func()
{
    cout << "Hello, function!" << endl;
}

int main() {

    cout << "Hello, World!" << endl;
    ClassFactory* fac = ClassFactory::getInstance();
    void* func = fac->getClassByName("test_func");
    if (!func) {
        cout << "not found!" << endl;
    }
 
    fac->registerFunc("test_func", (fn)test_func);
    func = fac->getClassByName("test_func");
    if (!test_func) {
        cout << "not found!" << endl;
    } else {
        test_func;
    }
    fac->~ClassFactory();
    return 0;
}