#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "globalVariables.h"

int X1, Y1;

//function prototype
int askPlayer(size_t turn, player user, disk board[SIZE][SIZE])
{
    size_t current, check = 1, moveCounter = 1, input, i, j, moveI = 9, moveJ = 9;
    //check accepted possible moves so that there aren't any duplicates
    //9 acts as placeholder - is not an actual co-ordinate for the board
    for (current = 0; current < 20; current++)
    {
        for (check = current+1; check < 20; check++)
        {
            if ((gMovesListI[check] == 9) && (gMovesListJ[check] == 9))
            {
                break;
            }

            if (gMovesListI[current] == gMovesListI[check])
            {
                if (gMovesListJ[current] == gMovesListJ[check])
                {
                    gMovesListI[current] = 9;
                    gMovesListJ[current] = 9;
                }
            }
        }
    }

    //print the correct player prompt
    if ((turn%2) == 1)
    {
        printf("\n\n%s, choose your next move: \n", user.name);
    }
    else
    {
        printf("\n\n%s, choose your next move: \n", user.name);
    }

    //output all possible moves
    for (i = 0; i < 20; i++)
    {
        if ((gMovesListI[i] == 9) && (gMovesListJ[i] == 9))
        {
        }
        else
        {
            printf("%d. (%d,%d)\n", moveCounter, (gMovesListI[i]+1), (gMovesListJ[i]+1));
            moveCounter++;
        }
    }

    //take in user input
    scanf("%d", &input);
    moveCounter = 1;

    //search through array of possible moves and find corresponding move to input number
    for (j = 0; j < 20; j++)
    {
        if ((gMovesListI[j] == 9) && (gMovesListJ[j] == 9))
        {
        }
        else
        {
            if (input == moveCounter)
            {
                moveI = gMovesListI[j];
                moveJ = gMovesListJ[j];
                X1 = moveI;
                Y1 = moveJ;
                break;
            }
            else
            {
                moveCounter++;
            }
        }
    }

    //error check to ensure valid choice made
    if ((moveI == 9) && (moveJ == 9))
    {
        printf("\nInvalid choice made. Exiting program.");
        return 1;
    }

    //print the player choice
    printf("\nYou chose (%d,%d)\n", (moveI+1), (moveJ+1));

    return 0;
}
