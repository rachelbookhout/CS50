/**
 * recover.c
 *
 * Computer Science 50
 * Problem Set 4
 *
 * Recovers JPEGs from a forensic image.
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#define JPEGSIZE 512

typedef uint8_t BYTE;
BYTE buffer[JPEGSIZE];
char filename[4];


int main(int argc, char* argv[])
{
    // open the memory card
     FILE* memoryCard = fopen("card.raw", "r");
    
    //error handling if the memoryCard can't open
    if (memoryCard == NULL)
    {
        printf("Could not open %s.\n", "card.raw");
        return 2;
    }
    
    //create our image files and counter for the number of photos we will create
    int photoNum = 0; 
    FILE* img;
    
    //starting the while loop to move over the contents of memoryCard
    while(!feof(memoryCard))
    {
        //check if we have reached the end of memoryCard
        if (fread(buffer, sizeof(BYTE), JPEGSIZE, memoryCard) == JPEGSIZE)
        {
            //check the first bytes within buffer to see if we have a jpeg        
            if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] == 0xe0 || buffer[3] == 0xe1))
            {
                //if yes and this is our first image, open img and write buffer to it
                if (img == NULL)
                {
                    sprintf(filename,"%03d.jpg", photoNum);
                    img = fopen(filename,"w");
                    fwrite(buffer,sizeof(BYTE),JPEGSIZE,img);
                    photoNum++;
                }
                
                //if yes and we have other images, close previous image then write buffer
                else
                {
                    fclose(img);
                    sprintf(filename,"%03d.jpg", photoNum);
                    img = fopen(filename,"a");
                    fwrite(buffer,sizeof(BYTE),JPEGSIZE,img);
                    photoNum++;
                }
            }
            
            // we don't have a jpeg image yet
            else
            {
                //if there have been no images written yet
                if (photoNum == 0)
                {
                    continue;
                }
                 else
                 {
                     fwrite(buffer,sizeof(BYTE),JPEGSIZE,img); 
                 }    
             
            }
        }
        else
        {
            break;
        }
    }
    
    fclose(img);
    fclose(memoryCard);
    return 0;
}
