/**
 * fifteen.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Implements Game of Fifteen (generalized to d x d).
 *
 * Usage: fifteen d
 *
 * whereby the board's dimensions are to be d x d,
 * where d must be in [DIM_MIN,DIM_MAX]
 *
 * Note that usleep is obsolete, but it offers more granularity than
 * sleep and is simpler to use than nanosleep; `man usleep` for more.
 */
 
#define _XOPEN_SOURCE 500

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

// constants
#define DIM_MIN 3
#define DIM_MAX 9

// board
int board[DIM_MAX][DIM_MAX];

// dimensions
int d;
int blankspace;
int x;
int y;

// prototypes
void clear(void);
void greet(void);
void init(void);
void draw(void);
bool move(int tile);
bool won(void);

int main(int argc, string argv[])
{
    // ensure proper usage
    if (argc != 2)
    {
        printf("Usage: fifteen d\n");
        return 1;
    }

    // ensure valid dimensions
    d = atoi(argv[1]);
    if (d < DIM_MIN || d > DIM_MAX)
    {
        printf("Board must be between %i x %i and %i x %i, inclusive.\n",
            DIM_MIN, DIM_MIN, DIM_MAX, DIM_MAX);
        return 2;
    }

    // open log
    FILE* file = fopen("log.txt", "w");
    if (file == NULL)
    {
        return 3;
    }

    // greet user with instructions
    greet();

    // initialize the board
    init();

    // accept moves until game is won
    while (true)
    {
        // clear the screen
        clear();

        // draw the current state of the board
        draw();

        // log the current state of the board (for testing)
        for (int i = 0; i < d; i++)
        {
            for (int j = 0; j < d; j++)
            {
                fprintf(file, "%i", board[i][j]);
                if (j < d - 1)
                {
                    fprintf(file, "|");
                }
            }
            fprintf(file, "\n");
        }
        fflush(file);

        // check for win
        if (won())
        {
            printf("ftw!\n");
            break;
        }

        // prompt for move
        printf("Tile to move: ");
        int tile = GetInt();
        
        // quit if user inputs 0 (for testing)
        if (tile == 0)
        {
            break;
        }

        // log move (for testing)
        fprintf(file, "%i\n", tile);
        fflush(file);

        // move if possible, else report illegality
        if (!move(tile))
        {
            printf("\nIllegal move.\n");
            usleep(500000);
        }

        // sleep thread for animation's sake
        usleep(500000);
    }
    
    // close log
    fclose(file);

    // success
    return 0;
}

/**
 * Clears screen using ANSI escape sequences.
 */
void clear(void)
{
    printf("\033[2J");
    printf("\033[%d;%dH", 0, 0);
}

/**
 * Greets player.
 */
void greet(void)
{
    clear();
    printf("WELCOME TO GAME OF FIFTEEN\n");
    usleep(2000000);
}

/**
 * Initializes the game's board with tiles numbered 1 through d*d - 1
 * (i.e., fills 2D array with values but does not actually print them).  
 */
void init(void)
{
    int count = (d * d);
    int n = 0;
    
    // iterates through the board, adding numbers in decreasing order
    // first number will be one less than the total of squares
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            n = n + 1;
            board[i][j] = (count - n);
        }
    }   

    // if the number of available of squares is even, need to reverse 1 & 2 in their squares
    
    if ((d % 2) == 0)
    {
        int last_value = board[d - 1][d - 2];
        board[d - 1][d - 2] = board[d - 1][d - 3];
        board[d - 1][d - 3] = last_value; 
    } 
}

/**
 * Prints the board in its current state.
 */
void draw(void)
{

    int n = 0;
 
    // iterate over the board array
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            n = (n + 1); 
 
            // print the number of the tile except for the 0 tile
            // if 0, print the space for all tiles to move
            
            if (board[i][j] > 0) 
            {
                printf("| %2d ", board[i][j]);
            }
 
            if (board[i][j] == 0) 
            {
                printf("| __ ");
            }
        }
        
        printf("|\n\n"); 
    }  
}

/**
 * If tile borders empty space, moves tile and returns true, else
 * returns false. 
 */
bool move(int tile)
{
    int blankspace = 0;
    
    //find the position of tile
    for (int i = 0; i < d; i++)
    {
        for (int j = 0; j < d; j++)
        {
            //check tile's position to blank space and swap it if possible
            if (board[i][j] == tile)
            {
              //checks above tile
              if (board[i][j-1] == blankspace && j - 1 >= 0 )
              {
                  board[i][j-1] = tile;
                  board[i][j] = blankspace;
                  return true;
              }
              //checks to the left of tile
              else if (board[i-1][j] == blankspace && i-1 >= 0)
              { 
                  board[i-1][j] = tile;
                  board[i][j] = blankspace;
                  return true;
                  
              }
              //checks below tile
              else if (board[i][j+1] == blankspace && j + 1 < d)
              {
                  board[i][j+1] = tile;
                  board[i][j] = blankspace;
                  return true;
              }
              //checks to right of tile
              else if (board[i+1][j] == blankspace && i+1 < d)
              {
                  board[i+1][j] = tile;
                  board[i][j] = blankspace;
                  return true;
              }                
            }
        }
    }
    return false;
}


/**
 * Returns true if game is won (i.e., board is in winning configuration), 
 * else false.
 */
bool won(void)
{
    //goes through the variables and checks that they are in order, starting at 1
    int counter = 1;  
    
    for (int i = 0; i < d; i++ )
    {
        for (int j = 0; j < d; j ++)
        {
            //checks to see if the final value is 0, ending the game 
            if ( i == d -1 && j == d -1 && board[i][j] == 0)
            {
                return true;
            }
            //checks to see if numbers are continuing on in order
            else if (board[i][j] != counter)
            {
                return false;
            }
            
            counter++;
        }
    }
    
   return 0;
}