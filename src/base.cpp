#include "base.h"
#include "cmd.h"
#include "type_def.h"
Base* Base::base = NULL;

void test()
{

}

void init_command()
{
    Base* base = Base::get_instance();
    string command;
    Functions funcs;
    uint commands_size = (sizeof(Commands)/sizeof(Commands[0]));
    uint functions_size = (sizeof(Functions)/sizeof(fn));

    fn f = (fn)&funcs;
 

    if (commands_size != functions_size) {
        cout << "$ init_command() fail..." << endl;
        return;
    }
    for (uint i = 0; i < commands_size; ++i) {
        command = Commands[i];
        base->register_command(command, (fn)test);
        // f = f +  sizeof(fn);
    }
    
}