/**
 * greedy.c
 *
 * Tells the user the least amount of coins they will receive back with their change 
 */

#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    
    int const quarter = 25;
    int const dime = 10;
    int const nickel = 5;
    int const penny = 1;
    
    //prompts users to find how much change they need
    float money;
    do
    {
        printf("O hai! How much change is owed?\n");
        money = GetFloat();
    }
    while (money < 0 );

    //convert input to cents
    int cents = (int) round(money * 100);
    
    //figure out the change starting with the coins with the largest values
    int counter = 0;
    int amount_remaining = cents;
    while (amount_remaining != 0)
    {
        counter += amount_remaining/quarter;
        amount_remaining %= quarter;
        
        counter += amount_remaining/dime;
        amount_remaining %= dime;
        
        counter += amount_remaining/nickel;
        amount_remaining %= nickel;
        
        counter += amount_remaining/penny;
        amount_remaining %= penny;
        
    }
    
    //print out the number of coins the user will get
    printf("%d\n", counter);

    
}