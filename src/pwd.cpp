#include "base.h"

#ifdef __cplusplus
extern "C" {
#endif

#define MAX_PWD_ARRAY_SIZE 256
void pwd(){
    char current_path[MAX_PWD_ARRAY_SIZE];
    char* result =  getcwd(current_path, 
            MAX_PWD_ARRAY_SIZE);
    if (!result) {
        cout << __FILE__ << " fail.." << endl;    
    }
    cout << current_path << endl;
}

#ifdef __cplusplus
}
#endif
