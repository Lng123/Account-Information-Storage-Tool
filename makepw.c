#include <stdio.h>
#include <ctype.h> 
#include <string.h>
#include <stdlib.h>
 #include "makepw.h" 
#define BUFSIZE 256
#define ISIZE 50
int menu(const char *choices[], const char *prompt);
int makepw();

int main(void) {
    int length;
    while(1){
        printf("Enter the length of the password");
        scanf( "%d", &length);
        if(isdigit(length))
            break;
    }
    makepw(length);
    return 0;
}



/* number,caps,specialcharacters*/
int makepw(int length) {
    int number,caps,specialchar;
    int modes[] = {0,0,0};
    const char *choices1[] = { "Include Number", "No Number", 0};
    const char *choices2[] = { "Include caps", "No Number", 0};
    const char *choices3[] = { "Include specialchar", "No Number", 0};
    caps = menu(choices2, "> Enter your choice");
    if(caps == 'y' || caps == 'Y')
        modes[0] = 1;
    number = menu(choices1, "> Enter your choice");
    if(number == 'y' || number == 'Y')
        modes[1] = 1;
    specialchar = menu(choices3, "> Enter your choice");
    if(specialchar == 'y' || specialchar == 'Y')
        modes[2] = 1;
    
    if (modes[0] == 0 && modes[1] == 0 && modes[2] == 0)
        return 0;
    if (modes[0] == 0 && modes[1] == 0 && modes[2] == 1)
        return 1;
    if (modes[0] == 0 && modes[1] == 1 && modes[2] == 0)
        return 2;
    if (modes[0] == 0 && modes[1] == 1 && modes[2] == 1)
        return 3;
    if (modes[0] == 1 && modes[1] == 0 && modes[2] == 0)
        return 4;
    if (modes[0] == 1 && modes[1] == 0 && modes[2] == 1)
        return 5;
    if (modes[0] == 1 && modes[1] == 1 && modes[2] == 0)
        return 6;
    if (modes[0] == 1 && modes[1] == 1 && modes[2] == 1)
        return 7;
    return 0;

}

int menu(const char *choices[], const char *prompt){
    int c;
  while(1){  
    size_t i;
    for(i=0;choices[i]!=0;i++){
        printf("%ld : %s\n",i+1,choices[i]);
    }
    printf("%s\n", prompt);
    c = fgetc(stdin);
     if(c == 'y' || c == 'Y' || c == 'N' || c == 'n')        
        return c;       
  }
  return 0;
}


