
#include "stdafx.h"
#include <iostream>
#include "screen.h"

using namespace std;


const int YSIZE = 25;
const int XSIZE = 75;


void seed(bool[XSIZE][YSIZE]);
void grid(bool[XSIZE][YSIZE]);
void neighbors(bool[XSIZE][YSIZE]);


int _tmain(int argc, _TCHAR* argv[])
{

	bool worldgen[XSIZE][YSIZE];
	int gen, i = 0;

	cout << " Please enter the number of generations: " << endl;
	cin >> gen;
	
	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < XSIZE; x++)
			worldgen[x][y] = false;


	// sets up the seed
	seed(worldgen);

	while (i < gen)
	{
		grid(worldgen);
		neighbors(worldgen);

		i++;
		delay(500);
		system("cls");
	}
	return 0;
}


// The starting seed of life
void seed(bool worldgen[XSIZE][YSIZE])
{
	//spaceship
	worldgen[3][5] = true;
	worldgen[2][5] = true;
	worldgen[2][6] = true;
	worldgen[1][6] = true;
	worldgen[1][4] = true;

	//pulsar

	worldgen[7][10] = true;
	worldgen[8][10] = true;
	worldgen[9][10] = true;
	
	worldgen[10][12] = true;
	worldgen[10][13] = true;
	worldgen[10][14] = true;
	
	worldgen[9][15] = true;
	worldgen[8][15] = true;
	worldgen[7][15] = true;
	
	worldgen[5][14] = true;
	worldgen[5][13] = true;
	worldgen[5][12] = true;

	worldgen[9][17] = true;
	worldgen[8][17] = true;
	worldgen[7][17] = true;
	
	worldgen[10][18] = true;
	worldgen[10][19] = true;
	worldgen[10][20] = true;
	
	worldgen[9][22] = true;
	worldgen[8][22] = true;
	worldgen[7][22] = true;
	
	worldgen[5][20] = true;
	worldgen[5][19] = true;
	worldgen[5][18] = true;

	worldgen[12][18] = true;
	worldgen[12][19] = true;
	worldgen[12][20] = true;

	worldgen[13][17] = true;
	worldgen[14][17] = true;
	worldgen[15][17] = true;

	worldgen[17][18] = true;
	worldgen[17][19] = true;
	worldgen[17][20] = true;

	worldgen[15][22] = true;
	worldgen[14][22] = true;
	worldgen[13][22] = true;

	worldgen[13][15] = true;
	worldgen[14][15] = true;
	worldgen[15][15] = true;

	worldgen[12][14] = true;
	worldgen[12][13] = true;
	worldgen[12][12] = true;

	worldgen[13][10] = true;
	worldgen[14][10] = true;
	worldgen[15][10] = true;

	worldgen[17][12] = true;
	worldgen[17][13] = true;
	worldgen[17][14] = true;


}


// shows whats in the array
void grid(bool worldgen[XSIZE][YSIZE])
{
	for (int y = 0; y < YSIZE; y++)
	{
		cout << endl;
		for (int x = 0; x < XSIZE; x++)
		{
			if (worldgen[x][y] == true)
				cout << "*";
			else
				cout << " ";
		}
	}
}


// checks for live neighbor
void neighbors(bool worldgen[XSIZE][YSIZE])
{
	bool tempgrid[XSIZE][YSIZE];
	int live;

	// Sets grid to clear
	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < XSIZE; x++)
			tempgrid[XSIZE][YSIZE] = false;

	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < XSIZE; x++)
		{
			live = 0;
			if (worldgen[x - 1][y - 1] == true)
				live++;
			if (worldgen[x][y - 1] == true)
				live++;
			if (worldgen[x + 1][y - 1] == true)
				live++;
			if (worldgen[x - 1][y] == true)
				live++;
			if (worldgen[x + 1][y] == true)
				live++;
			if (worldgen[x - 1][y + 1] == true)
				live++;
			if (worldgen[x][y + 1] == true)
				live++;
			if (worldgen[x + 1][y + 1] == true)
				live++;

			// if a cell is true and has two live neighbors it lives
			if (worldgen[x][y] == true && live == 2)
				tempgrid[x][y] = true;
			
			// if a cell is dead and has three live neighbors is becomes alive
			if (live == 3)
				tempgrid[x][y] = true;
			
			// if a cell has neither two or three neighbors it dies
			if (live != 3 && live != 2)
				tempgrid[x][y] = false;

		}

	// clears the onlygrid
	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < XSIZE; x++)
			worldgen[x][y] = false;

	// sets new generation to old main grid
	for (int y = 0; y < YSIZE; y++)
		for (int x = 0; x < XSIZE; x++)
			worldgen[x][y] = tempgrid[x][y];

}

