#include "FirePropagation.h"

#include <iostream>
#include <random>
#include <vector>

#include "Console.h"

using namespace std;

int mapNoChanges = 0;

//Sets tree on fire with 50% of probability
int SetFire() {
	//Random generator stuff
	random_device rd;
	mt19937 gen(rd());
	uniform_real_distribution<> fireRandom(1, 3); //Random between 1 and 2 (1=Tree; 2=Burning)
	return fireRandom(gen);
}

//Propagates fire to the neighbor trees
vector<vector<int>> Propagate(vector<vector<int>> map) {
	vector<vector<int>> currentMap = map;

	//Stuff not very funny
	for (int i = 0; i < map.size(); i++)
	{
		for (int j = 0; j < map[i].size(); j++) {
			if (map[i][j] == 1) {
				if (i == 0) {
					if (j == 0) {
						if (map[i+1][j] == 2 || map[i+1][j+1] == 2 || map[i][j+1] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else if (j == map[i].size() - 1) {
						if (map[i+1][j] == 2 || map[i+1][j-1] == 2 || map[i][j-1] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else {
						if (map[i][j-1] == 2 || map[i][j+1] == 2 || map[i+1][j-1] == 2 || map[i+1][j] == 2 || map[i+1][j+1] == 2) {
							currentMap[i][j] = SetFire();
						}
					}
				} else if (i == map.size() - 1) {
					if (j == 0) {
						if (map[i-1][j] == 2 || map[i-1][j+1] == 2 || map[i][j+1] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else if (j == map[i].size() - 1) {
						if (map[i-1][j] == 2 || map[i-1][j-1] == 2 || map[i][j-1] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else {
						if (map[i][j-1] == 2 || map[i][j+1] == 2 || map[i-1][j-1] == 2 || map[i-1][j] == 2 || map[i-1][j+1] == 2) {
							currentMap[i][j] = SetFire();
						}
					}
				} else {
					if (j == 0) {
						if (map[i-1][j] == 2 || map[i-1][j+1] == 2 || map[i][j+1] == 2 || map[i+1][j+1] == 2 || map[i+1][j] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else if (j == map[i].size() - 1) {
						if (map[i-1][j] == 2 || map[i-1][j-1] == 2 || map[i][j-1] == 2 || map[i+1][j-1] == 2 || map[i+1][j] == 2) {
							currentMap[i][j] = SetFire();
						}
					} else {
						if (map[i-1][j-1] == 2 || map[i-1][j] == 2 || map[i-1][j+1] == 2 || map[i][j-1] == 2 || map[i][j+1] == 2 || map[i+1][j-1] == 2 || map[i+1][j] == 2 || map[i+1][j+1] == 2) {
								currentMap[i][j] = SetFire();
						}	
					}
				}	
			}
		}
	}

	if (currentMap == map && mapNoChanges < 3) {
		mapNoChanges++;
	} else if (currentMap == map && mapNoChanges >= 3) {
		EndSimulation(map.size());		
	}

	return currentMap;
}