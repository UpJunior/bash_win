#ifndef _CMD_H_
#define _CMD_H_

typedef struct {
    fn *ls;
    fn *pwd;
} Functions;

std::string Commands[] = {
    "ls",
    "pwd"
};


#endif
