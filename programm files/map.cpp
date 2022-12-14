#include "map.h"
#include <iostream>


char map[20][20]{
{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}, // char is 1 byte
{'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'}, // short is 2 bytes
{'1', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1'}, // that is why the map is 
{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1'}, // made of chars and not
{'1', '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1', '1', '1', '0', '1'}, // shorts
{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
{'1', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1'},
{'1', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '2', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '2', '0', '1'},
{'1', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '0', '0', '0', '1', '1', '1', '0', '0', '1', '1', '1', '0', '0', '0', '1', '0', '1'},
{'1', '0', '1', '1', '1', '1', '1', '0', '0', '0', '0', '0', '0', '1', '1', '1', '1', '1', '0', '1'},
{'1', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '0', '0', '1'},
{'1', '0', '1', '1', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1', '1', '1', '0', '1'},
{'1', '0', '0', '0', '1', '0', '1', '0', '0', '0', '0', '0', '0', '1', '0', '1', '0', '0', '0', '1'},
{'1', '0', '0', '0', '1', '0', '1', '1', '1', '1', '1', '1', '1', '1', '0', '1', '0', '0', '0', '1'},
{'1', '0', '0', '0', '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '1', '0', '0', '0', '1'},
{'1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
};

using namespace std;

void printMap(short playerX, short playerY, int floor, float score, short playerLives)
{
	cout << "floor: " << floor << "\t\tscore: " << score << "\t\tlives: " << playerLives << endl;
	for (int i = 0; i < 20; i++) 
	{
		for (int j = 0; j < 20; j++) 
		{
			switch (map[i][j])
			{
			case FREESPACE:
			{
				cout << "\033[45m"; //purple color
				break;
			}
			case WALL:
			{
				cout << "\033[44m"; // blue color
				break;
			}
			case DOOR:
			{
				cout << "\033[46m"; //light blue color
				break;
			}
			case KEY:
			{
				cout << "\033[47m"; // white color
				break;
			}
			case BOSS:
			{
				cout << "\033[43m";//yellow color
				break;
			}
			default:
				break;
			}
			
			if (i == playerX && j == playerY)
			{
				cout << " X "; //print X to show the player
			}
			else
			{
				cout << "   ";//print some spaces with the current color
			}
		}
		cout << endl;
	}
	cout << "\033[0m"; //black color
	cout << "endter 'a' 'w' 's' 'd' to move or '1' to enter menu" << endl;
}

bool checkNoWall(short nextCoordinateX, short nextCoodinateY, bool playerHasTheKeys)
{
	//check if there is no wall or if there is no door if player has no keys
	if (map[nextCoordinateX][nextCoodinateY] == FREESPACE || map[nextCoordinateX][nextCoodinateY] == KEY || (map[nextCoordinateX][nextCoodinateY] == DOOR && playerHasTheKeys) || map[nextCoordinateX][nextCoodinateY] == BOSS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool checkBoss(short nextCoordinateX, short nextCoodinateY)
{
	//check if the next place where player is going is a boss
	if (map[nextCoordinateX][nextCoodinateY] == BOSS)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void spawnKey(short playerX, short playerY)
{
	bool keySpawned = false;
	while (!keySpawned) // going to try to spawn the key until the spawn position is diferent from player position
	{
		int randomPosition = rand() % 4;
		enum POSITIONS {
			BOTTOMRIGHT,
			BOTTTOMLEFT,
			TOPRIGHT,
			TOPLEFT
		};

		switch (randomPosition)
		{
		case BOTTOMRIGHT:
		{
			if (playerX != 17 && playerY != 17) //check if player is on bottom right corner of the map
			{
				map[17][17] = KEY; //spawn key
				keySpawned = true;
				break;
			}
		}
		case BOTTTOMLEFT:
		{
			if (playerX != 17 && playerY != 2) //check if player is on bottom left corner of the map
			{
				map[17][2] = KEY; //spawn key
				keySpawned = true;
				break;
			}
		}
		case TOPRIGHT:
		{
			if (playerX != 2 && playerY != 17) //check if player is on top right corner of the map
			{ 
				map[2][17] = KEY; //spawn key
				keySpawned = true;
				break;
			}
		}
		case TOPLEFT:
		{
			if (playerX != 2 && playerY != 2) //check if player is on top left corner of the map
			{
				map[2][2] = KEY; //spawn key
				keySpawned = true;
				break;
			}
		}
		}
	}
}

bool thereIsKey(short nextCoordinateX, short nextCoodinateY) 
{
	if (map[nextCoordinateX][nextCoodinateY] == KEY) //check if pleyer is moving to a key
	{
		map[nextCoordinateX][nextCoodinateY] = FREESPACE; //take out the key
		return true;
	}
	else
	{
		return false;
	}
}

void spawnBoss()
{
	int randonPosition = rand() % 2; //random number to define where boss is going to spawn

	if (randonPosition == 0)
	{
		map[4][10] = BOSS; //spawn boss
	}
	else
	{
		map[15][10] = BOSS; //spawn boss
	}
}