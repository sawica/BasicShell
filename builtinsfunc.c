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

#include "builtinsfunc.h"
#include "arguments.h"

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
        tokenize(line, ' ');
        tokenize(line, '|');
        tokenize(line, '$');
        tokenize(line, '>');
        tokenize(line, '#');
        function_switch(line);
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

/*
void function(char** token){
    int i=0;
    char buf;
    char* tmp = (char*)malloc(5*sizeof(char));

    


    while(buf != NULL){
        if(buf !=' '){
            read(token[i], buf, 1);
            strcat(tmp, buf);
        }
        else i++;
        function_switch(tmp);
    }


}
*/
void printHelp(){
    char* help = "These are the commands you can use in this shell:\nhelp\nexit\n";
    write(STDOUT_FILENO, help, strlen(help));
}
void function_switch(char** token){
    // switch(tmp){
    int i, command;
     char* all_commands[5];
     all_commands[0]="help";
     all_commands[1]="exit";
     all_commands[2]="cd";
     all_commands[3]="mkdir";
     all_commands[4]="ls";

     char * tok = (char*)malloc(sizeof(char)*(strlen(token[0])-1));
     tok = token[0];
     for(i=0;i<5;i++){

         if (strcmp(tok, all_commands[i]) == 0) {
             fprintf(stdout, "huhu: %s ", token[0]);
             command = i;
             break;
         }
     }
    char* tmp = "Are you sure?\n [yes/no]\n";
    char* answer = (char*)malloc(5 * sizeof(char));

     switch(command){
         case 0:
             printHelp();
         case 1:
             write(STDOUT_FILENO, tmp, strlen(tmp));
             //answer = mread();
             mread(answer);
             if(strcmp(answer,"yes")==0){
                 exit(0);
             }
             mread(answer);
             if(strcmp(answer,"no")==0){
                 break;
             }
             mread(answer);
             if(strcmp(answer,"yes")!=0 && strcmp(answer,"no")!=0){
                 char* tmp2 = "Choose between 'yes' or 'no'\n";
                 write(STDOUT_FILENO, tmp2, strlen(tmp2));
             }
     }
}
