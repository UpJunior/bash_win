
#include "intf.h"
#include "register.h"

Register* Register::_reg = NULL;

int load_lib()
{
    func_ptr *handle = NULL;
    int cmd_size = sizeof(CommandList)/sizeof(CommandList[0]);
    for (int i = 0; i < cmd_size; ++i) {
        string lib_name = "./lib" + CommandList[i] + ".so";
        void* fd = OPENLIB(lib_name.c_str());
        handle = (func_ptr*)LIBFUNC(fd, CommandList[i].c_str());
        if (!handle) {
            cout << "load " << lib_name << " fail" << endl;
        }
        Register::get_instance()->regiser_func(CommandList[i], handle);
    }
    return 0;
}


int main()
{
    string command = "";
    string _exit = "exit";

    load_lib();

    for (; cout << "$ " && cin >> command ;) {
        if (command.compare(_exit) == 0) {
            return 0;
        }
        func_ptr* f_ptr = Register::get_instance()->get_func_ptr(command);
        if (f_ptr == NULL) {
            cout << "not found this command!" << endl;
            continue;
        }
        f_ptr();
    }
    return 0;
}