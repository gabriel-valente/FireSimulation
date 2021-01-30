#ifndef MAPVIEWER_H
#define MAPVIEWER_H
#include <vector>

using namespace std;

vector<vector<int>> Generate(int height, int width);
void Update(vector<vector<int>> map);

#endif