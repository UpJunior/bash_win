#include "intf.h"
#include "register.h"




void run()
{
    string command = "pwd";
    Register::get_instance()->regiser_func(command, (func_ptr)pwd);
}


void pwd(){
    cout << "ls cmd" << endl; 
}
