#include "MapViewer.h"

#include <iostream>
#include <random>
#include "Windows.h"

using namespace std;

void Draw(vector<vector<int>> map) {
	//Random generator stuff
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> treeRandom(5, 7); //Random between 5 and 6 (5=Spades ASCII Number; 6=Clubs ASCII Number)

	//initialize objects for cursor manipulation
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	//position cursor at start of window
	destCoord.X = 0;
	destCoord.Y = 0;
	SetConsoleCursorPosition(hStdout, destCoord);

	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO     cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = false; // set the cursor visibility
    SetConsoleCursorInfo(out, &cursorInfo);
	
	//Displays the map
	for (int i = 0; i < map.size(); ++i) {
		for (int j = 0; j < map[i].size(); ++j)
			if (map[i][j] == 1) cout << (char)treeRandom(gen) << " "; //Displays a Spade or a Clue where there is a 1 in the vector
			else if (map[i][j] == 2) cout << (char)176 << " ";
			else cout << "  "; 	//Displays an empty space where there is a 0 in the vector
		cout << endl;
	}
}

vector<vector<int>> Generate(int height, int width)
{
	//Random generator stuff
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> mapRandom(0, 2); //Random between 0 and 1 (0=No Tree; 1=Tree)

	//Map data
	vector<vector<int>> map;

	//Generate map
	for (int i = 0; i < height; ++i) {
		vector<int> row; //Each row of the map

		//Generates each row of the map and adds to the row vector
		for (int j = 0; j < width; ++j)
			row.push_back(mapRandom(gen));

		//Adds each row to the map vector
		map.push_back(row);
	}

	Draw(map);
	
	return map;
}

void Update(vector<vector<int>> map) {
	Draw(map);
}
