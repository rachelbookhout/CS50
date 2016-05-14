/**
 * vigenere.c
 *
 * takes an string input from a user and uses it to encrypt a phrase they choose
 * then returns the encrypted phrase back to them
 */


#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
 
int main(int argc, string argv[])
{
    //verifies that the user inputted a paramater and if so, only one
    if (argc != 2)
    {
        printf("Suggest format: ./vigenere <key> \n");
         return 1;
    }
    
    //verifies that the string inputted by user has only letters 
    for (int i = 0, s = strlen(argv[1]); i < s; i++)
    {
        if (!isalpha(argv[1][i]))
        {
             printf("All characters in the key needs to be alphanumeric");
             return 1;
        }
    }
    
    //switch key to integer and get input from user
    string key = argv[1]; 
    string phrase = GetString();
    int keyLength = strlen(key);
  
    //iterates through both the key and the phrase in order to encrypt the phrase
    for (int i = 0, j = 0, n = strlen(phrase); i < n; i++)
    {
        //finds what letter in the key we are using for the encrypt and getting its numerical value
        int letter_key = tolower(key[j % keyLength]) - 'a';
        
        // finds the encrypted value for an uppercase letter in phrase and returns it
        if (isupper(phrase[i]))
        {
            printf("%c", 'A' + (phrase[i] - 'A' + letter_key) % 26);
            j++;
        }
        
        //finds the encrypted value for lowercase letter in phrase and returns it
        else if (islower(phrase[i]))
        {
            printf("%c", 'a' + (phrase[i] - 'a' + letter_key) % 26);
            j++;
        }
        
        //print anything in phrase that isn't a letter    
        else
        {
            printf("%c", phrase[i]);
        }        
    }
        
    printf("\n");
    return 0;
     
 }