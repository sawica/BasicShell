//
// Created by Magdalena Sawicka on 25.04.2021.
//

#include "arguments.h"

char* mread(char* ustring) {
    char buf[2] = { 0, 0 };
    while (buf[0] != '\n') {
        read(STDIN_FILENO, buf, 1);

        if (buf[0] != '\n') {
            strcat(ustring, buf);
        }
    }
    return ustring;
}
void introduction(char* user) {

    clear();
    char* hello="Hello ";
    char* hello2 = " ! Welcome to our BasicShell\n\n";

    write(STDOUT_FILENO, hello, strlen(hello));
    write(STDOUT_FILENO, user, strlen(user));
    write(STDOUT_FILENO, hello2, strlen(hello2));

    char* help = "*If you need more informations about how to use this shell just write 'help' in command line. \n";
    write(STDOUT_FILENO, help, strlen(help));
    // sleep(3);
    clear();
}

void showUserName_and_Dir(char* user){
    char* dir= malloc(100 * sizeof(char));
    getcwd(dir, 100*sizeof(char));

    char* space= " :~ ";
    write(STDOUT_FILENO, user, strlen(user));
    write(STDOUT_FILENO, space, strlen(space));
    write(STDOUT_FILENO, dir, strlen(dir));
    write(STDOUT_FILENO, " ", 1);


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

void write_token (char **token){
    char buf[2] = { 0, 0 };
    int i=0;

    while (buf != NULL ){
        read(token[i], buf, 1);
        write(STDOUT_FILENO, buf, 1);
        if(buf == '\n') i++;
    }
}


char** tokenize(char** old_tokens, char delimeter) {
    char** token=(char**)malloc(50*sizeof(char*));
    for(int i=0; i<50;i++){
        token[i]=(char*)malloc(20*sizeof(char));
    }
    char buf[2] = { 0, 0 };
    int tmp=0;
    for(int j=0; j<50; j++){
        if(buf == NULL) j++;
        read(old_tokens[j], buf, 1);
        if (buf[0] != delimeter) {
            strcat(token[tmp], buf);
        }
        else {
            strcat(token[tmp++], buf);
            tmp++;
        }
    }
    return token;
    // delimeter = ' ', old_tokens = ["ls -1 | grep .c|xargs wc -l|sort >>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c|xargs", " ", "wc",  " ","-l|sort", " ", ">>file.txt"]
    //
    // delimeter = '|', old_tokens = ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c|xargs", " ", "wc",  " ","-l|sort", " ", ">>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">>file.txt"]
    //
    // delimeter = '>', old_tokens = ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">>file.txt"]
    // return ["ls", " ", "-1", " ", "|", " ", "grep", " ", ".c", "|", "xargs", " ", "wc",  " ","-l", "|", "sort", " ", ">", ">", "file.txt"]
}