#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "globalVariables.h"

//function prototype
void printResult(player player1, player player2, disk board[SIZE][SIZE])
{
    FILE *fp;

    int i,j;

    //iterate through file and count points for each player
    for(i=0; i< SIZE; i++)
    {
        for(j=0;j<SIZE; j++)
        {
            switch(board[i][j].type)
            {
                case BLACK:
                    player1.points++;
                    break;
                case WHITE:
                    player2.points++;
                    break;
                case NONE:
                    break;
                default:
                    break;
            }
        }
    }

    //print the results to the screen
    printf("\nPlayer1 points: %d", player1.points);
    printf("\nPlayer2 points: %d", player2.points);

    //open a txt file and output the same results
    fp = fopen("reversiResults.txt", "w+");
    fprintf(fp, "\nPlayer1 points: %d\nPlayer2 points: %d\n", player1.points, player2.points);

    //print the winner or if draw
    if (player1.points > player2.points)
    {
        printf("\nThe winner is %s!", player1.name);
        fprintf(fp, "\nThe winner is %s!", player1.name);
    }
    else if (player2.points > player1.points)
    {
        printf("\nThe winner is %s!", player2.name);
        fprintf(fp, "\nThe winner is %s!", player2.name);
    }
    else
    {
        printf("\nThe game is a draw.");
        fprintf(fp, "\nThe game is a draw.");
    }

    fclose(fp);
}

