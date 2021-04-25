//
// Created by Magdalena Sawicka on 25.04.2021.
//
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <signal.h>
#include <errno.h>

#include "arguments.h"
#include "builtinsfunc.h.h"
#include "execute.h"
#include "history.h"

#define clear() printf("\033[H\033[J")

int main(){
    char* user = malloc(16 * sizeof(char));

    write(STDOUT_FILENO, "Your user name: ", 15);
    mread(user);
    introduction(user);
    //handle_commands(user);
    showUserName_and_Dir(user);
    char** line = (char**)malloc(50*sizeof(char*));
    for(int i=0; i<50;i++){
        line[i]=(char*)malloc(20*sizeof(char));
    }
    line = readLine();
    showUserName_and_Dir(user);
    char** tok = (char**)malloc(50*sizeof(char*));
    for(int i=0; i<50;i++){
        tok[i]=(char*)malloc(20*sizeof(char));
    }
    tok =tokenize(line, ' ');
    write_token(tok);
}
