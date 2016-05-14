/**
 * caesar.c
 *
 * takes an int from the user and uses it to encrypt a phrase from the user
 * then returns the encrypted phrase
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
        printf("Usage: ./caesar <key> \n");
        return 1;    
    }
    
    //checks to make sure the integer entered by user is not negative
    if (atoi(argv[1]) < 0)
    {
        printf("Key must be a non-negative integer. \n");
        return 1;
    }
    
    //switch key to integer and get input from user
    int key = atoi(argv[1]);
    string phrase = GetString();
    
    //iterate through the phrase and encrypt the text
    for (int i = 0, n = strlen(phrase); i < n; i++)
    {
        //for upper case letters
        if (isupper(phrase[i]))
        {
            printf("%c", 'A' + (phrase[i] - 'A' + key) % 26);
        }
        
        // for lower case letters
        else if (islower(phrase[i]))
        {
            printf("%c", 'a' + (phrase[i] - 'a' + key) % 26);
        }
        
        //for all characters that aren't alphnumberic     
        else
        {
            printf("%c", phrase[i]);
        }
    }
    
    printf("\n");
    return 0;
}