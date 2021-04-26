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

#define clear() printf("\033[H\033[J")

void mread(char* mstring) {
    char buf[2] = {0,0};
    while (buf[0] != '\n') {
        read(STDIN_FILENO, &buf, 1);

        if (buf[0] != '\n') {
            strcat(mstring, buf);
        }
    }
    //return mstring;
}
void introduction(char* user) {
    char* hello="\nHello ";
    char* hello2 = " ! Welcome to our BasicShell\n\n";

    write(STDOUT_FILENO, hello, strlen(hello));
    write(STDOUT_FILENO, user, strlen(user));
    write(STDOUT_FILENO, hello2, strlen(hello2));

    char* help = "*If you need more informations about how to use this shell just write 'help' in command line. \n\n\n";
    write(STDOUT_FILENO, help, strlen(help));
    // sleep(3);
}

void showUserName_and_Dir(char* user){
    char* dir= malloc(100 * sizeof(char));
    getcwd(dir, 100*sizeof(char));

    char* space= " :~ ";
    write(STDOUT_FILENO, user, strlen(user));
    write(STDOUT_FILENO, space, strlen(space));
    write(STDOUT_FILENO, dir, strlen(dir));
    write(STDOUT_FILENO, " ", 1);

    free(dir);


}

char** readLine(){

    size_t line_size = 2;
    char** line = (char**)malloc(line_size * sizeof(char*));
    line[0]=(char*)malloc(1000*sizeof(char));

    size_t temp = getline(&line[0], &line_size, stdin);
    // zrbic obsluge bledu
    char* temp_line = line[0];
    write(STDOUT_FILENO,temp_line, strlen(temp_line));

    return line;
}

char** tokenize(char** old_tokens, char delimeter) {
    char** tokens = malloc(50 * sizeof(char*));
    for(int i = 0; i < 50; i++){
        tokens[i] = NULL;
    }

    char *buf;
    int tmp = 0;
    for(int j = 0; j < 50 && old_tokens[j] != NULL; j++){
        buf = old_tokens[j];
        tokens[tmp] = malloc(sizeof(char) * strlen(buf));
        memset(tokens[tmp], '\0', strlen(buf));
        fprintf(stdout, "`%s`, ", tokens[0]);
        for(int i = 0; i < strlen(buf); i++){
            if (buf[i] != delimeter) {
                tokens[tmp][strlen(tokens[tmp])] = buf[i];
                fprintf(stdout, "`%s`, ", tokens[tmp]);
            } else {
                tokens[++tmp] = malloc(sizeof(char) * 2);
                tokens[tmp][0] = buf[i];
                tokens[tmp++][1] = '\0';
            }
        }

        // ekhem, same sprobojcie naprawic... a nie czekacie na zbawienie
    }   //probowalysmy wczoraj pol dnia i nocy xd troche zwatpilysmy
            // to nie ma cos ie smiac. teraz to robcie

    fprintf(stdout, "tokenize: ");
    for (int i = 0; i < 50 && tokens[i] != NULL; ++i) {
        fprintf(stdout, "`%s`, ", tokens[i]);
    }

    return tokens;
    //   return token;
    // delimeter = ' ', old_tokens = ["ls -1 | grep .c|xargs wc -l|sort >>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c|xargs", " ", "wc",  " ","-l|sort", " ", ">>file.txt"]
    //
    // delimeter = '|', old_tokens = ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c|xargs", " ", "wc",  " ","-l|sort", " ", ">>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">>file.txt"]
    //
    // delimeter = '>', old_tokens = ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">", ">", "file.txt"]
}