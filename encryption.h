/**********************************************************************************************************
 *  encryption.h
 *  
 *  Header file.
 * 
 * 
 **********************************************************************************************************/


#ifndef ENCRYPTION_H
#define ENCRYPTION_H

/* 
 * Function to find the total sum of the characters in a password based on the value of the ASCII code of
 * each letter.
 */
int password_value(char *s);

/* 
 * Encryption of password.
 * Two methods, depending on the value of the sum of a password being odd or even.
 * Odd valued password stays odd after encryption.
 * Even valued password stays even after encryption.
 */
void encrypt(char *s);

/* 
 * Decryption of password.
 */
void decrypt(char *s);

#endif
