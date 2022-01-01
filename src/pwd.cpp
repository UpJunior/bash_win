#include "base.h"
#define MAX_PWD_ARRAY_SIZE 256
extern "C" void pwd(){
    char current_path[MAX_PWD_ARRAY_SIZE];
    char* result =  getcwd(current_path, 
            MAX_PWD_ARRAY_SIZE);
    if (!result) {
        cout << __FILE__ << " fail.." << endl;    
    }
    cout << current_path << endl;
}
