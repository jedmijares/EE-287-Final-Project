#include "structs.h"

void randomPlaceShip(struct Ship ship, struct Square board[8][8])
{
	ship.isVertical = (Random32()%(2));
	ship.hits = 0;
	ship.xpos = (Random32()%(8-ship.length+1));
	ship.ypos = (Random32()%(8-ship.length+1));
	
	for(int i = ship.xpos; (i-ship.xpos) < ship.length; i++) // checking if this ship will overlap with another ship
	{
		if(!ship.isVertical)
		{
			if(board[i][ship.ypos].shipID >= 0) // if a ship already occupies one of this ship's squares
			{
				randomPlaceShip(ship, board); // place the ship somewhere else
				return; // and stop
			}
		}
		else
		{
			if(board[ship.xpos][i].shipID >= 0)
			{
				randomPlaceShip(ship, board);
				return;
			}
		}
	}
	
	for(int i = ship.xpos; (i-ship.xpos) < ship.length; i++)
	{
		if(!ship.isVertical)
		{
			board[i][ship.ypos].shipID = ship.ID;
		}
		else
		{
			board[ship.xpos][i].shipID = ship.ID;
		}
	}
}
