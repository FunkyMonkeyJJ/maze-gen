#include <iostream>
#include <string>
#include "maze.hpp"

Maze::Maze(std::string name) {
	this->name = name;
}

Maze::~Maze() {
	this->name = "";
}

void Maze::generate() {
	std::cout << "Generating maze..." << std::endl;
}