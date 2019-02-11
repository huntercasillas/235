#include <iostream>
#include <cstdlib>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "Pathfinder.h"

using namespace std;

Pathfinder::Pathfinder() {
		for (int c = 0; c < 5; c++) {
			for (int b = 0; b < 5; b++) {
				for (int a = 0; a < 5; a++) {
					maze[a][b][c] = 1;
				}
			}
		}
}

string Pathfinder::toString() const{
	string output;
	for (int c = 0; c < 5; c++) {
			for (int b = 0; b < 5; b++) {
				for (int a = 0; a < 5; a++) {
					if (a == 4) {
						output += to_string(maze[a][b][c]) + "\n";
					} else {
						output += to_string(maze[a][b][c]) + " ";
					}
				}
			}
			output += "\n";
		}
	output.pop_back();
	return output;
}

void Pathfinder::createRandomMaze() {
	for (int c = 0; c < 5; c++) {
			for (int b = 0; b < 5; b++) {
				for (int a = 0; a < 5; a++) {
					maze[a][b][c] = rand() % 2;
				}
			}
		}
		maze[0][0][0] = 1;
		maze[4][4][4] = 1;
}

bool Pathfinder::importMaze(string file) {
	int value = 0;
	string num;

	ifstream inFile(file);
	if (inFile.is_open())
	{
		for (int c = 0; c < 5; c++) {
				for (int b = 0; b < 5; b++) {
					for (int a = 0; a < 5; a++) {
						inFile >> num;
						if (num != "0" && num != "1") {
							return false;
						} else {
							altMaze[a][b][c] = stoi(num);
							value++;
						}
						num = "-1";
					}
				}
			}
			inFile >> num;
			if (num != "-1" || value != 125 || altMaze[0][0][0] != 1 || altMaze[4][4][4] != 1)
			{
				return false;
			}
			else
			{
					for (int c = 0; c < 5; c++) {
							for (int b = 0; b < 5; b++) {
								for (int a = 0; a < 5; a++) {
									maze[a][b][c] = altMaze[a][b][c];
								}
							}
						}
				inFile.close();
				return true;
			}
	}
	else
	{
		inFile.close();
		return false;
	}
}

vector<string> Pathfinder::solveMaze() {
	solve(0, 0, 0);
	for (int c = 0; c < 5; c++) {
			for (int b = 0; b < 5; b++) {
				for (int a = 0; a < 5; a++) {
					if (maze[a][b][c] > 0) {
						maze[a][b][c] = 1;
					}
				}
			}
		}

		vector<string> realPath;
		int pathSize = path.size();
		for (int i = 0; i < pathSize; i++) {
			realPath.push_back(path[path.size() - 1]);
			path.pop_back();
		}
		return realPath;
}

bool Pathfinder::solve(int a, int b, int c) {
	
	if (a > 4 || b > 4 || c > 4) {
		return false;
	}

	if (a < 0 || b < 0 || c < 0) {
		return false;
	}

	if (maze[a][b][c] == 0 || maze[a][b][c] != 1) {
		return false;
	}

	if (a == 4 && b == 4 && c == 4) {
		visited = "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
		path.push_back(visited);
		return true;
	}

	maze[a][b][c] = 2;

	if (solve(a+1,b,c) == true ||solve(a,b+1,c) == true ||solve(a,b,c+1) == true ||solve(a-1,b,c) == true ||solve(a,b-1,c) == true ||solve(a,b,c-1) == true) {
		visited = "(" + to_string(a) + ", " + to_string(b) + ", " + to_string(c) + ")";
		path.push_back(visited);
		return true;
	} else {
		if (path.size() != 0) {
			path.pop_back();
		}
		return false;
	}
}