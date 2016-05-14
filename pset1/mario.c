/**
 * mario.c
 *
 * creates the pyrmid that Mario will have to jump over
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
  // prompt user for height of pyrmid. It can not be bigger than 23 or smaller than 0
   int height;
    do
    {
        printf("Height: ");
        height = GetInt();
         
    }
    while (height > 23 || height < 0);
    
  // print out the pyrmid with i representing the number of hashes needed and y representing the spaces needed
  for (int i = 2; i <= height + 1 ; i++)
  {
    int spaces = height - i;
    for (int y = 0; y < spaces + 1 ; y++)
    {
        printf("%s", " ");
    }
    for (int x  = 0; x < i; x++)
    {
        printf("#");
    }
    printf("\n");
  } 
}