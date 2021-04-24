#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define clear() printf("\033[H\033[J")

void introduction(char* user){

    // clear();
    char* hello="***Hello ";
    char* hello2 = " !***\n Welcome to our BasicShell\n";
   
    write(STDOUT_FILENO, hello, strlen(hello));
    write(STDOUT_FILENO, user, strlen(user));
    write(STDOUT_FILENO, hello2, strlen(hello2));
    // fflush(stdout);
    
    /*fwrite(hello, sizeof(hello), sizeof(char), *stdout);
    fwrite(user, sizeof(user), sizeof(char), stdout);
    fwrite(hello2, sizeof(hello2), sizeof(char), stdout);
    *///write(STDOUT_FILENO,"***Hello %s !***\n Welcome to our BasicShell\n", user, sizeof(user+42));
    printf("If you need more informations about how to use this shell just write 'help' in command line. \n");
    sleep(5);
    // clear();
}

void showUserName_and_Dir(char* user){
    char* dir;
    getcwd(dir, sizeof(dir));
  //  write(STDOUT_FILENO,"\n %s :~ %s", user, dir, 7+sizeof(user)+sizeof(dir));
}

char* readLine(){


    // return line;
}

char** tokenize(char** old_tokens, char delimeter) {
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

void handle_commands(char* user, char** first_command, char** second_command){
    //tu deklaracje
    char* line;
    char* commands[4];
    int one_or_two = 0;
    int sum=0;
    while(1){
        showUserName_and_Dir(user);
        line = readLine();
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


    char buf[2] = { 0, 0 };
    while (buf[0] != '\n') {
      read(STDIN_FILENO, buf, 1);

      if (buf[0] != '\n') {
      	strcat(user, buf);
      }
    }
    // fscanf(stdin, "%s", user);
    introduction(user);
   // handle_commands(user);
}
