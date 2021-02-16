#include <iostream>
#include <Windows.h>


#include "Console.h"
#include "MapViewer.h"
#include "FirePropagation.h"
#include "Messages.h"

void main() {
	vector<vector<int>> map = Generate(21,21); //Max 62, 118
	Messages msg = Messages();

	
	ChangeCursorVisibility(false);
	
	cout << msg.SetFire;
	getchar();

	map[10][10] = 2;
	Draw(map);
	
	while (true) {
		cout << msg.MoveIteration;
		getchar();

		map = Propagate(map);
		Draw(map);
	}
}