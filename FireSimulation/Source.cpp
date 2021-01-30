#include <iostream>

#include "MapViewer.h"
#include "FirePropagation.h"

void main() {
	vector<vector<int>> map = Generate(62,118);

	cout << "Press Enter to set fire to the first tree";
	getchar();

	map[0][0] = 2;
	Update(map);
	
	while (true) {
		cout << "Press Enter to move to the next iteration";
		getchar();

		map = Propagate(map);
		Update(map);
	}
}