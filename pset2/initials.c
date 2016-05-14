/**
 * intials.c
 *
 * prints out the intials of a inputed name
 */

#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
  // get string from user
  string name = GetString();
  //print out the first letter since that is the start of their name/an intial
  printf("%c", toupper(name[0]));
    
  // iterate over the string the user gave and print & capitalize the first letter
  // in each word in the string
  for (int i = 1, n = strlen(name); i < n; i++)
  {
    while (name[i] == ' ')
      {
        i++;
        if (name[i] != ' ')
        {
          printf("%c", toupper(name[i]));
        }
      }
    }
    
    printf("\n");
}