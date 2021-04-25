#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define clear() printf("\033[H\033[J")


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
    sleep(3);
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

int parse_commands(char* line, char** commands){
    int count_of_commands=5;
    //while(!=eol) SPRAWDZIC!   
    for(int i=0;i<count_of_commands;i++){
        //podział po "|", ">", "#", "&", " "
        //jesli koniec linii to zlicza ile komend i przekazuje returnem
    }
}

void handle_commands(char* user//, char** first_command, char** second_command
){
    //tu deklaracje
    char** line;
    char* commands[4];
    int one_or_two = 0;
    int sum=0;
    showUserName_and_Dir(user);
    while(1){
        showUserName_and_Dir(user);
        line = readLine();
        char** tok = (char**)malloc(50*sizeof(char*));
        for(int i=0; i<50;i++){
            tok[i]=(char*)malloc(20*sizeof(char));
        }
        tok =tokenize(line, ' ');
        write_token(tok);
/*
        one_or_two = parse_commands(line, commands); //return 0 lub 2
        while(counter!=0){
           split(commands[counter], commands[counter][0]);
           counter--;
       }
       
        if(one_or_two==2){
            split(commands[1],second_command);
        }
        split(commands[0],first_command);

        while()

//assert <- sprawdzic
        for(int i=0;i<2;i++){
            sum+=Library_of_Commands(/*komenda którą będziemy sprawdzać); //moze te pierwsze wyrazy z komend przechowywac 
            //tez w tablicy wtedy bedzie mozna wiecej komend pisac w jednej sciezce?
        }
        how_many_commands(sum); // i tu podział na to ile execow trzeba zrobic w zaleznosci od sumy
*/   
    }
   
    
}

int main(){
    char* user = malloc(16 * sizeof(char));

    write(STDOUT_FILENO, "Your user name: ", 15);
    mread(user);
    introduction(user);
    //handle_commands(user);
    showUserName_and_Dir(user);
    char** line = readLine();
   // char** tok = (char**)malloc(50*sizeof(char*));
   // for(int i=0; i<50;i++){
   // tok[i]=(char*)malloc(20*sizeof(char));
   // }
   // tok =tokenize(line, ' ');
   // write_token(tok);
}
