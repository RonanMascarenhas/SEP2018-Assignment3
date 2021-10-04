#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "globalVariables.h"

//initialise arrays to hold move positions
int gMovesListI[20] = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
int gMovesListJ[20] = {9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9};
int X1, Y1;

int main()
{
    // Variables declaration
    player player1= {"player1", NONE,0};
    player player2= {"player2", NONE,0};
    disk board[SIZE][SIZE];

    //turnCounter to 64, turn is black or white
    size_t turn = 1;
    size_t turnCounter = 1;
    int returnValue;

    //start game with initialisation
		initializePlayers(player1, player2);

		initializeBoard(board);

		printBoard(board);

		//continue game until end condition met
	while(turnCounter != 60)
       	{
       	    //function to compute possible moves
            computeMoves(turnCounter, turn, board);

            //depends on whose turn it is
            if ((turn%2 == 1))
            {
                returnValue = askPlayer(turn, player1, board);
                if (returnValue == 1)
                {
                    return 0;
                }
            }
            else
            {
                returnValue = askPlayer(turn, player2, board);
                if (returnValue == 1)
                {
                    return 0;
                }
            }

            //flip relevant disks and print the updated board
            diskflip(turn, board);

            printBoard(board);

            //change the turn to the other player
            if (turn == 0)
            {
                turn = 1;
            }
            else if (turn == 1)
            {
                turn = 0;
            }

            //reinitialise the array
            for (int q = 0; q < 20; q++)
            {
                gMovesListI[q] = 9;
                gMovesListJ[q] = 9;
            }

            //update the turn number
            turnCounter++;
        }

        //print the final result
		printResult(player1, player2, board);

		return 0;
}
