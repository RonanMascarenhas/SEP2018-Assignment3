#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "disksAndPlayers.h"
#include "globalVariables.h"

/*Disk flipping */
int X1, Y1;

void diskflip(size_t turn, disk board[SIZE][SIZE])
{
	int m, n, i, j, newI, newJ;
	/*(m,n) coordiantes of placed disc*/
	n = X1;
	m = Y1;
	if ((turn%2 == 1)) /*Blacks turn*/
    {
		board[m][n].type = BLACK; /*placed disc*/

		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=1;j++)
			{ /*These loops are for reading all the adjacent cells to the placed disk*/
				if(i==0 && j==0)
				{
					/*placed disks location, no modification needed*/
				}
				else
				{
					switch (board[m+i][n+j].type)
                    {
                        case NONE: /*no disk so no possible chain*/
						break;

						case BLACK: /*Already a black disc so no possible chain */
						break;

						case WHITE: /*Opponents disk found, possible chain*/
							newI = m+i;
							newJ = n+j;

							while (board[newI][newJ].type == WHITE)
							{
								/*follows the chain until a black disk or and empty space is reached*/
								if (newI > m)
								{
									newI++;
								}
								else if (newI < m)
								{
									newI--;
								}
								else
								{
								}
								if (newJ > n)
								{
									newJ++;
								}
								else if (newJ < n)
								{
									newJ--;
								}
								else
								{
								}
							}

					   switch (board[newI][newJ].type)
                        {
                            case NONE:
                            /*Chain ends in an empty cell not a possible move*/
                            break;
                            case BLACK: /*Chain ends in one of your disks, valid move*/
                            newI = m+i;
							newJ = n+j;

								while (board[newI][newJ].type == WHITE)
								{ /*follows chain until black disk is reached*/

									board[newI][newJ].type = BLACK; /*Changes current disk to black */

									if (newI > m) /*moves newI to next disk*/
									{
										newI++;
									}
									else if (newI < m)
									{
										newI--;
									}
									else
									{
									}
									if (newJ > n) /*moves newJ to next disk*/
									{
										newJ++;
									}
									else if (newJ < n)
									{
										newJ--;
									}
									else
									{
									}
								}
							default:
							break;

						}
					}
				}
			}
		}
	}

	else
	{
		board[m][n].type = WHITE; /*placed disc*/

		for(i=-1;i<=1;i++)
		{
			for(j=-1;j<=1;j++)
			{ /*These loops are for reading all the adjacent cells to the placed disk*/
				if(i==0 && j==0)
				{
					/*placed disks location, no modification needed*/
				}
				else
				{
					switch (board[m+i][n+j].type)
                    {
                        case NONE: /*no disk so no possible chain*/
						break;

						case WHITE: /*Already a black disc so no possible chain */
						break;

						case BLACK: /*Opponents disk found, possible chain*/
							newI = m+i;
							newJ = n+j;

							while (board[newI][newJ].type == BLACK)
							{
								/*follows the chain until a black disk or and empty space is reached*/
								if (newI > m)
								{
									newI++;
								}
								else if (newI < m)
								{
									newI--;
								}
								else
								{
								}
								if (newJ > n)
								{
									newJ++;
								}
								else if (newJ < n)
								{
									newJ--;
								}
								else
								{
								}
							}

					   switch (board[newI][newJ].type)
                        {
                            case NONE:
                            /*Chain ends in an empty cell not a possible move*/
                            break;
                            case WHITE: /*Chain ends in one of your disks, valid move*/
                            newI = m+i;
							newJ = n+j;

								while (board[newI][newJ].type == BLACK)
								{ /*follows chain until black disk is reached*/

									board[newI][newJ].type = WHITE; /*Changes current disk to black */

									if (newI > m) /*moves newI to next disk*/
									{
										newI++;
									}
									else if (newI < m)
									{
										newI--;
									}
									else
									{
									}
									if (newJ > n) /*moves newJ to next disk*/
									{
										newJ++;
									}
									else if (newJ < n)
									{
										newJ--;
									}
									else
									{
									}
								}
							default:
							break;

						}
					}
				}
			}
		}
	}
}
