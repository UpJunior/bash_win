
#include "intf.h"
#include "register.h"
#define MAIN_MAX_PWD_ARRAY_SIZE 256
Register* Register::_reg = NULL;
Register* reg = NULL;


#define SYSTEM_NAME_SIZE 65

typedef struct {
    char os_sysname[SYSTEM_NAME_SIZE];
    char pwd[MAIN_MAX_PWD_ARRAY_SIZE];
} OsSystemInfo;





int load_command_lib()
{

    func_ptr *handle = NULL;
    reg = Register::get_instance();
    int cmd_size = sizeof(CommandList)/sizeof(CommandList[0]);
    for (int i = 0; i < cmd_size; ++i) {
        string lib_name = "../build/src/lib";
#ifdef __linux__
        lib_name += CommandList[i] + ".so";
        LIBTYPE fd = OPENLIB(lib_name.c_str());
        handle = (func_ptr*)LIBFUNC(fd, CommandList[i].c_str());
#elif defined(WINVER)
        lib_name += CommandList[i] + ".dll.a";
        LIBTYPE fd = OPENLIB(lib_name);
        handle = (func_ptr*)LIBFUNC(CommandList[i].c_str());
#endif
        if (!handle) {
            cout << "load " << lib_name << " fail" << endl;
        }
        reg->regiser_func(CommandList[i], handle);
    }
    return 0;
}

void get_current_path(char* path)
{
    char* result =  getcwd(path, 
            MAIN_MAX_PWD_ARRAY_SIZE);
    if (!result) {
        cout << __FILE__ << " fail.." << endl;    
    }
}

void get_os_name(OsSystemInfo &os_sysinfo)
{
    char* result =  getcwd(os_sysinfo.pwd, 
            MAIN_MAX_PWD_ARRAY_SIZE);
    if (!result) {
        cout << __FILE__ << " fail.." << endl;    
    }
#ifdef __linux__
    struct utsname os_info;
	if(uname(&os_info)) exit(-1);
    strncpy(os_sysinfo.os_sysname, os_info.sysname, SYSTEM_NAME_SIZE);
#elif defined(WINVER)
    DWORD name_len = SYSTEM_NAME_SIZE;  
    if(GetUserName(os_sysinfo.os_sysname, &name_len)) exit(-1);
#endif

}

int main()
{

    string _exit = "exit";
    OsSystemInfo os_info;


    reg = Register::get_instance();

    // 加载命令动态库
    load_command_lib();
    // 获取命令行信息
    get_os_name(os_info);

    for (string command = ""; printf("%s@os:%s$ ", os_info.os_sysname, 
        os_info.pwd) && cin >> command;) {
        if (command.compare(_exit) == 0) {
            return 0;
        }
        func_ptr* f_ptr = reg->get_func_ptr(command);
        if (f_ptr == NULL) {
            cout << command << ": command not found" << endl;
            continue;
        }
        f_ptr();
    }
    reg = NULL;
    return 0;
}