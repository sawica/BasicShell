//
// Created by Magdalena Sawicka on 25.04.2021.
//

#ifndef BASICSHELL_ARGUMENTS_H
#define BASICSHELL_ARGUMENTS_H

void mread(char* mstring);
void introduction(char* user);
void showUserName_and_Dir(char* user);
char** readLine();
void write_token (char **token);
char** tokenize(char** old_tokens, char delimeter);


#endif //BASICSHELL_ARGUMENTS_H
