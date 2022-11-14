#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.hpp"

Maze::Maze(std::string name, int width, int length) {
	this->name = name;
	this->width = width;
	this->length = length;
	std::vector<std::vector<char>> new_grid(width, std::vector<char>(length));
	this->grid = new_grid;
}

Maze* Maze::set_num_rooms(int num_rooms) {
	this->num_rooms = num_rooms;
	return this;
}

Maze* Maze::set_num_traps(int num_traps) {
	this->num_traps = num_traps;
	return this;
}

Maze* Maze::generate() {
	printf("Generating %s (%d x %d)...\n", this->name.c_str(), this->width, this->length);

	srand(time(NULL));

	int area = this->width * this->length;
	if (area < this->num_rooms)
	{
		std::cerr << "Cannot add more rooms than there is space." << std::endl;
		std::cerr << "Tried adding " << this->num_rooms << " rooms but only " << area << " is available." << std::endl;
		return this;
	}

	// TODO: Create Enum for all combinations of room openings
	// N, NE, NS, NW, NES, NEW, NSW, NESW
	// E, EW
	// S, SE, SW, SEW
	// W

	// TODO: Based on Enum above, store different letters in grid
	// TODO: Print different 3x3 based on Enum above (center spot is trap)
		// This will remove the need for num_rooms

	// set random rooms
	while (this->num_rooms > 0) {
		int y = rand() % this->width;
		int x = rand() % this->length;

 		if (grid[y][x] == '\0')
		{
			grid[y][x] = 'o';
			num_rooms--;
		}
	}

	enum Trap
	{
		fire = 0,
		spikes = 1,
		web = 2,
		bomb = 3,
		NUM_TRAPS = 4
	};

	area = (this->width * this->length) - this->num_rooms;
	if (area < this->num_traps)
	{
		std::cerr << "Cannot add more traps than there is space." << std::endl;
		std::cerr << "Tried adding " << this->num_traps << " traps but only " << area << " is available." << std::endl;
		return this;
	}

	// set random traps
	while (this->num_traps > 0) {
		int x = rand() % this->length;
		int y = rand() % this->width;

		if (grid[y][x] == '\0')
		{
			int trap = rand() % Trap::NUM_TRAPS;
			switch (trap) {
				case Trap::fire:
					grid[y][x] = '$';
					break;
				case Trap::spikes:
					grid[y][x] = '^';
					break;
				case Trap::web:
					grid[y][x] = '#';
					break;
				case Trap::bomb:
					grid[y][x] = 'X';
					break;
			}
			num_traps--;
		}
	}

	return this;
}

std::ostream& operator<<(std::ostream &stream, const Maze &maze) {
	return stream << &maze;
}

std::ostream& operator<<(std::ostream &stream, const Maze *maze) {
  	stream << "⌈"; // North Wall
	for (int i = 0; i < maze->width; i++) stream << "—";
	stream << "⌉" << std::endl;

	for (int i = 0; i < maze->length; i++)
	{
		stream << '|'; // West Wall
		for (int j = 0; j < maze->width; j++)
		{
			// Prints space for empty space in the maze
			// Otherwise prints the room, trap, etc. that exists there
			stream << (maze->grid[j][i] == '\0' ? ' ' : maze->grid[j][i]);
		}
		stream << '|' << std::endl; // East Wall
	}

	stream << "⌊"; // South Wall
	for (int i = 0; i < maze->width; i++) stream << "—";
	stream << "⌋" << std::endl;
  	return stream;
}

void Maze::print() {
	std::cout << this << std::endl;
}

// TODO
Maze* Maze::import_from_file(std::string filename) {
	return this;
}

void Maze::export_to_file(std::string filename) {
	std::ofstream ofile { filename };
	if (ofile)
	{
		ofile << this << std::endl;
	}
}