#include "MapViewer.h"
#include "Console.h"

#include <iostream>
#include <random>

using namespace std;

void Draw(vector<vector<int>> map) {
	//Random generator stuff
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> treeRandom(5, 7); //Random between 5 and 6 (5=Spades ASCII Number; 6=Clubs ASCII Number)

	SetCursorPosition(0, 0);
	
	//Displays the map
	for (int i = 0; i < map.size(); ++i) { //Direction Y
		for (int j = 0; j < map[i].size(); ++j) { //Direction X
			if (map[i][j] == 1) cout << (char)treeRandom(gen) << " "; //Displays a Spade or a Clue where there is a 1 in the vector (Tree)
			else if (map[i][j] == 2) cout << (char)176 << " "; //Displays a dotted squeare where there is a 2 in the vector (Fire)
			else cout << "  "; 	//Displays an empty space where there is a 0 in the vector (Empty)
		}
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
