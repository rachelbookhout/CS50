/**
 * water.c
 *
 * calculates how many ounces of water in terms of bottles of water someone users when they shower
 */

#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // all variables are in ounces
    int ounces_per_min = 192;
    int bottle_size = 16;
    
    printf("minutes: ");
    int minutes = GetInt();
     
     // multiply together minutes and the ounces per min then divide by the size of the bottle
    int total_ounces_used = minutes * ounces_per_min / bottle_size;
    printf("bottles: %d \n", total_ounces_used);

}