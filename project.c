#include <stdio.h> 
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
#define BUFSIZE 256
#define ISIZE 50




typedef struct {
    char username[ISIZE];
    char password[ISIZE];
    char site[ISIZE];
}password;



int menu(const char *choices[], const char *prompt);
int main(void) {

    int choice;
    const char *choices[] = { "Save a password", "Find a password", "Password Generator","Quit", 0};
    choice = menu(choices, "> Enter your choice");
    printf("%d", choice);

    return 0;
}


int menu(const char *choices[], const char *prompt){
  char line[BUFSIZE];
  int n;
  while(1){  
    size_t i;
    for(i=0;choices[i]!=0;i++){
        printf("%ld : %s\n",i+1,choices[i]);
    }
    printf("%s\n", prompt);
    if(!fgets(line, BUFSIZE,stdin)){
        clearerr(stdin);
        fprintf(stderr,"No Input\n");
        return 0;
    } 
    if(sscanf(line, " %d", &n)==1 && n>0 && n <=(int)i)
        return n;       
  }
  return 0;
}
