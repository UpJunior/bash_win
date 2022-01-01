#include "register.h"
#include "intf.h"
#include "cmd.h"

Register* Register::_reg = NULL;
Register* reg;

void register_func(string &name, func_ptr f_ptr)
{
    reg = Register::get_instance();
    cout <<"reg addr:"<< reg << endl;
    reg->regiser_func(name, f_ptr);
    reg = NULL;
}

func_ptr get_funcby_name(string &name) {
    reg = Register::get_instance();
    return reg->get_func_ptr(name);
}

int main()
{
    func_ptr f_ptr;
    string command = "";

    reg = Register::get_instance();
    for (int i = 0; i < reg->func_list.size(); ++i ){ {

    }
    

    string _exit = "exit";
    for (printf("$"); cin >> command && !command.compare(_exit);) {
        f_ptr = get_funcby_name(command);
        if (f_ptr == NULL) {
            cout << "not found this cmd!" << endl;
            continue;
        } 
        f_ptr();
    }
    delete reg;
    return 0;
}