#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "globalVariables.h"

//function prototype
int computeMoves(size_t turnCounter, size_t turn, disk board[SIZE][SIZE])
{
    //i == x coordinates, j == y coordinates
    //0 == WHITE, 1 == BLACK, 2 == NONE
    //initialise arrays storing potential move co-ordinates, and variables for use
    int movesListI[20] = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
    int movesListJ[20] = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
    size_t i = 0, j = 0,
     posI, posJ, newI, newJ, counterI = 0, counterJ = 0;
    int iSum, jSum;

    //iterate through all cells of the board
    for (i=0; i<SIZE; i++)
    {
        for (j=0; j<SIZE; j++)
        {
            //check what type of disk is on this cell
            switch (board[i][j].type) {
                case WHITE:
                    //printf("!!!\n");
                    //check whose turn it currently is
                    switch (turn) {
                        //break since it's the player's disk
                        case WHITE:
                            break;
                        //it's an opponents' disk: check the cells surrounding this disk
                        case BLACK:
                            for (posI=i-1; posI<=i+1; posI++)
                            {
                                for (posJ=j-1; posJ<=j+1; posJ++)
                                {
                                    newI = i;
                                    newJ = j;

                                    if ((posJ == 0) && (posI == 0))
                                    {
                                        break;
                                    }
                                    //prevents from searching outside the board
                                    if ((posI < 0) || (posJ < 0))
                                    {
                                    }
                                    //check the type of disk on this adjacent cell
                                    else
                                    {
                                        switch (board[posI][posJ].type) {
                                            //if cell is empty, jump to the opposite side of current disk to confirm whether this is valid move
                                            case NONE:
                                                //decide where to jump to based on relative position of current and adjacent disk
                                                iSum = i - posI;
                                                jSum = j - posJ;
                                                if (iSum > 0)
                                                {
                                                    newI = i+1;
                                                    //jump to i+1 position
                                                }
                                                else if (iSum < 0)
                                                {
                                                    newI = i-1;
                                                }
                                                else
                                                {
                                                    newI = i;
                                                }

                                                if (jSum > 0)
                                                {
                                                    newJ = j+1;
                                                    //jump to j+1 position
                                                }
                                                else if (jSum < 0)
                                                {
                                                    newJ = j-1;
                                                }
                                                else
                                                {
                                                    newJ = j;
                                                }
                                                //i == current position on x
                                                //posI == current position of adjacent pointer on x etc...
                                                //as long as there is a chain of opposing player disks, continue along the chain until you reach the end
                                                while (board[newI][newJ].type == WHITE)
                                                {
                                                    if (newI > i)
                                                    {
                                                        newI++;
                                                    }
                                                    else if (newI < i)
                                                    {
                                                        newI--;
                                                    }
                                                    else
                                                    {
                                                    }

                                                    if (newJ > j)
                                                    {
                                                        newJ++;
                                                    }
                                                    else if (newJ < j)
                                                    {
                                                        newJ--;
                                                    }
                                                    else
                                                    {
                                                    }
                                                }

                                                //after reaching end of chain, check whether final cell is empty or has your disk
                                                switch (board[newI][newJ].type) {
                                                    case NONE:
                                                        //this is not a valid option - move on to the next cell
                                                        break;
                                                    case BLACK:
                                                        //this is a valid option - add this position to list of possible moves
                                                        movesListI[counterI] = posI;
                                                        movesListJ[counterJ] = posJ;
                                                        counterI++;
                                                        counterJ++;
                                                        break;
                                                    default:
                                                        break;
                                                }

                                            default:
                                                break;
                                        }
                                    }

                                }
                            }
                        default:
                            break;

                    }

                //same logic as above
                case BLACK:
                    switch (turn) {
                        case BLACK:
                            break;
                        case WHITE:
                            for (posI=i-1; posI<=i+1; posI++)
                            {
                                for (posJ=j-1; posJ<=j+1; posJ++)
                                {
                                    newI = i;
                                    newJ = j;

                                    if ((posJ == 0) && (posI == 0))
                                    {
                                        break;
                                    }

                                    if ((posI < 0) || (posJ < 0))
                                    {
                                    }
                                    else
                                    {
                                        switch (board[posI][posJ].type) {
                                            case NONE:
                                                iSum = i - posI;
                                                jSum = j - posJ;
                                                if (iSum > 0)
                                                {
                                                    newI = i+1;
                                                    //jump to i+1 position
                                                }
                                                else if (iSum < 0)
                                                {
                                                    newI = i-1;
                                                }
                                                else
                                                {
                                                }

                                                if (jSum > 0)
                                                {
                                                    newJ = j+1;
                                                    //jump to j+1 position
                                                }
                                                else if (jSum < 0)
                                                {
                                                    newJ = j-1;
                                                }
                                                else
                                                {
                                                }
                                                //i == current position on x
                                                //posI == current position of adjacent pointer on x etc...
                                                while (board[newI][newJ].type == BLACK)
                                                {
                                                    if (newI > i)
                                                    {
                                                        newI++;
                                                    }
                                                    else if (newI < i)
                                                    {
                                                        newI--;
                                                    }
                                                    else
                                                    {
                                                    }

                                                    if (newJ > j)
                                                    {
                                                        newJ++;
                                                    }
                                                    else if (newJ < j)
                                                    {
                                                        newJ--;
                                                    }
                                                    else
                                                    {
                                                    }
                                                }

                                                switch (board[newI][newJ].type) {
                                                    case NONE:
                                                        //this is not a valid option - move on to the next cell
                                                        break;
                                                    case WHITE:
                                                        //this is a valid option - add this position to list of possible moves
                                                        movesListI[counterI] = posI;
                                                        movesListJ[counterJ] = posJ;
                                                        counterI++;
                                                        counterJ++;
                                                        break;
                                                    default:
                                                        break;
                                                }

                                            default:
                                                break;
                                        }
                                    }

                                }
                            }
                        default:
                            break;

                    }

                default:
                    break;
            }
        }
    }

    int movesCounter = 0;

    //print the list of possible moves (ignore 9 entries)
    for (int k = 0; k < 20; k++)
    {
        //printf("\n(%d, %d)", movesListI[k], movesListJ[k]);
        if ((movesListI[k] < 8) && (movesListJ[k] < 8))
        {
            //movesListI[k]++;
            //movesListJ[k]++;
            gMovesListI[k] = movesListI[k];
            gMovesListJ[k] = movesListJ[k];
            movesCounter++;
        }
    }

    //if no valid moves are possible the game ends
    if (movesCounter == 0)
    {
        return 1;
    }

    //swap the x and y co-ordinates of the positions
    int tmpCount, tmp;

    if (turnCounter >= 3)
    {
        for (tmpCount = 0; tmpCount < 20; tmpCount++)
        {
           tmp = gMovesListI[tmpCount];
           gMovesListI[tmpCount] = gMovesListJ[tmpCount];
           gMovesListJ[tmpCount] = tmp;
        }
    }

    return 0;

}
