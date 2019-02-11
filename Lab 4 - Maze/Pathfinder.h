#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "PathfinderInterface.h"

using namespace std;

class Pathfinder {
public:
	Pathfinder();
	~Pathfinder() {}
	string toString() const;
	void createRandomMaze();
	bool importMaze(string file_name);
	vector<string> solveMaze();

private:
    bool solve(int a, int b, int c);
    int maze[5][5][5];
    int altMaze[5][5][5];
    vector<string> path;
    string visited;
};