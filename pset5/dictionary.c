/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */

#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include "dictionary.h"

//set up our global variables
int wordcount;
node* root;


/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
    //create a variable to track which node we need to go to within the children
    int nodeLocation;
    struct node* cursor = root;
    
    //iterate through each word so we can compare the letters
    for (int i = 0; word[i] != '\0'; i++)
    {
        if (isalpha(word[i]))
        {
            //check for uppercase so we can match it to the right children node
            if (isupper(word[i]))
            {
                nodeLocation = word[i] - 'A';
            }
            else
            {
                nodeLocation = word[i] - 'a';
            }
        }
        //if it's not a letter, it's a ' and will go to the last node
        else
        {
            nodeLocation = 26;
        }
        
        //go to the node and check if it exists
        //if null, we didn't find the word. otherwise, move to that node and restart the process
        if (cursor->children[nodeLocation] == NULL)
        {
            return false;
        }
        else
        {
            cursor = cursor->children[nodeLocation];
        }
    }
    
    //final check to see that our path of letters equals a real word as defined by the dictionary
    if (cursor->is_word == true)
    {
        return true;
    }
    
    return false;
}

/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
 
bool load(const char* dictionary)
{
    char word[LENGTH + 1];
    int index = 0;
    wordcount = 0;
    root = (struct node*) malloc(sizeof(node));
    FILE* fp = fopen(dictionary, "r");
    
    //iterate through each character in the file
    for (int c = fgetc(fp); c != EOF; c = fgetc(fp))
    {
        //if we have reached the end of a word
        if (c == '\n')
        {
           //add the character to word array and add to wordcount
            word[index] = c;
            wordcount++;
            //set the cursor to the start of the word
            struct node* cursor = root;
            //iterate through the word
            for (int i = 0; i <= index; i++)
            {
                //check if its a letter
                if (isalpha(word[i]))
                {
                    // check to see if we have a children node for it yet
                    if (cursor->children[word[i] - 'a'] == NULL)
                    {
                        //if we don't, allocate memory for it
                        cursor->children[word[i]- 'a'] = (struct node*) malloc(sizeof(node));
                    }
                    //move our cursor to the children node for that letter
                    cursor = cursor->children[word[i] - 'a'];
                }
                //check if it's '
                else if (word[i] == '\'')
                {
                    //check if we have a children node for it yet
                    if (cursor->children[26] == NULL)
                    {
                        //if we don't, allocate memory for it
                        cursor->children[26] = (struct node*) malloc(sizeof(node));
                    }
                    //move our cursor to to the ' childen node
                    cursor = cursor->children[26];
                }
                // check if we reached the end of the word
                else if (word[i]== '\n')
                {
                    //if we have, add the is_word boolean to indicate the word is done
                    cursor->is_word = true;
                }
            }
            //reset the index for the next word we need to iterate through
            index = 0;
        }
        //if we haven't found the /n character yet to indicate we reached the end of the word
        else
        {
            //add the character to our word array and up our index value
            word[index] = c;
            index++;
        }
    }
    //close the file
    fclose(fp);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return wordcount;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
   if (freeNode(root))
   {
       return true;
   }
    return false;
}

bool freeNode(struct node* node)
{
    //goes through each node and frees all of its children
    for (int i=0; i<27; i++)
    {
        if (node->children[i] != NULL)
        {
            freeNode(node->children[i]);
        }
    }
    free(node);
    return true;
}
