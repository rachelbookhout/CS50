/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"


bool binary_search(int, int[], int, int);


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    if ( n < 0)
    {
        return false;
    }
    
    bool result = binary_search(value, values, 0, n-1);
    return result;

    
}

bool binary_search(int value, int values[], int min, int max)
{
   
    int mid = (min+max)/2;
    
    //return false if the max number in the array is less than the minimum
    if (min > max)
    { 
        return false;
    }
    
    else
    {
        // if value is less than the middle, search the left portion of the array
        if (value < values[mid])
        {
            return binary_search(value, values, min, mid - 1);        
        }
        
        // if value is more than the middle, search the right portion of the array
        else if (value > values[mid])
        {
            return binary_search(value, values, mid + 1, max); 
        }
        
        // check to see if we found the value
        else if (value == values[mid])
        {
            return true;
        }
        
        //if none of these conditions are correct, the number isn't in the array
        else
        {
            return false;
        }
    }

}


/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    // TODO: implement an O(n^2) sorting algorithm
    
    // iterates through the values, doing selection sort
    
    for (int i = 0; i < n ; i++)
    {
        //compares the value of i to j
        for (int j = i + 1; j < n; j++)
        {
            int min = i;
            
            //if j is less than i, j becomes the min
            if (values[j] < values[min])
            {
                min = j;
            }
            
            //if i is no longer the min, swap the indexs
            if (min != i)
            {
                int swap = values[i];
                values[i] = values[min];
                values[min] = swap;
            }
        }  
    }
    return;
}