/**********************************************************************************************************
 *  encryption.c
 *  
 * 
 * 
 * 
 **********************************************************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int password_value(char *s){
    size_t i;
    int sum = 0;
    for(i = 0; s[i] != '\0'; i++)
        sum += s[i];
    return sum;
}

void encrypt(char *s){
    size_t i, j;
    if(!(password_value(s) % 2)){
        for(i = 0, j = (sizeof(s)/4); s[i] != '\0'; i++, j += 2)
            s[i] -= j;
        s[i / 2] -= 6, s[i / 3] -= 2;
    }
    else {
        for(i = 0, j = (sizeof(s)/2); s[i] != '\0'; i++, j += 2)
            s[i] -= j;
        s[i / 2] -= 4, s[i / 3] -= 6;
    }
}

void decrypt(char *s){
    size_t i, j;
    if(!(password_value(s) % 2)){
        for(i = 0, j = (sizeof(s)/4); s[i] != '\0'; i++, j += 2)
            s[i] += j;
        s[i / 2] += 6, s[i / 3] += 2;
    }
    else {
        for(i = 0, j = (sizeof(s)/2); s[i] != '\0'; i++, j += 2)
            s[i] += j;
        s[i / 2] += 4, s[i / 3] += 6;
    }
}
/*
int main(void){
    char s[] = "abc123";
    char t[] = "qwerty";
    char u[] = "password";
    char v[] = "12345678";
    char w[] = "johnlee";

    
    printf("%d\n%d\n%d\n%d\n%d\n\n", password_value(s), password_value(t), password_value(u), password_value(v), password_value(w));
    printf("%s\n%s\n%s\n%s\n%s\n\n", s, t, u, v, w);

    
    encrypt(s); encrypt(t); encrypt(u); encrypt(v); encrypt(w);
    printf("%s\n%s\n%s\n%s\n%s\n\n", s, t, u, v, w);
    printf("%d\n%d\n%d\n%d\n%d\n\n", password_value(s), password_value(t), password_value(u), password_value(v), password_value(w));

    
    decrypt(s), decrypt(t), decrypt(u), decrypt(v), decrypt(w);
    printf("%s\n%s\n%s\n%s\n%s\n\n", s, t, u, v, w);

    return 0;
}
*/
