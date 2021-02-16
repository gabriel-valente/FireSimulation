#include <iostream>
#include <Windows.h>

using namespace std;

void ChangeCursorVisibility(bool visibility) {
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cursorInfo;

    GetConsoleCursorInfo(out, &cursorInfo);
    cursorInfo.bVisible = visibility; //Change visibility
    SetConsoleCursorInfo(out, &cursorInfo);
}

void SetCursorPosition(int x, int y) {
	//Initialize objects for cursor manipulation
	HANDLE hStdout;
	COORD destCoord;
	hStdout = GetStdHandle(STD_OUTPUT_HANDLE);

	//Position cursor at start of window
	destCoord.X = x;
	destCoord.Y = y;
	SetConsoleCursorPosition(hStdout, destCoord); //Move cursor to the location
}

void EndSimulation(int y) {
	SetCursorPosition(0, y);
	cout << "Simulation ended, press ENTER to restart with a new map";
}
