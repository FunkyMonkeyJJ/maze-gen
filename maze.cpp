#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "maze.hpp"

enum Room
{
	N, NE, NS, NW, NES, NEW, NSW, NESW,
	E, EW,
	S, SE, SW, SEW,
	W,
	NUM_ROOMS
};

enum Trap
{
	fire = 0,
	spikes = 1,
	web = 2,
	bomb = 3,
	NUM_TRAPS = 4
};

Maze::Maze(std::string name, int width, int length) {
	this->name = name;
	this->width = width;
	this->length = length;
	std::vector<std::vector<char>> new_grid(width, std::vector<char>(length));
	this->grid = new_grid;
	std::vector<std::vector<char>> new_trap_grid(width, std::vector<char>(length));
	this->trap_grid = new_trap_grid;
}

Maze* Maze::set_num_traps(int num_traps) {
	this->num_traps = num_traps;
	return this;
}

Maze* Maze::generate() {
	printf("Generating %s (%d x %d)...\n", this->name.c_str(), this->width, this->length);

	srand(time(NULL));

	for (int i = 0; i < this->length; i++)
	{
		for (int j = 0; j < this->width; j++)
		{
			grid[j][i] = '0' + (rand() % Room::NUM_ROOMS);
		}
	}
	int area = this->width * this->length;
	if (this->num_traps > area)
	{
		std::cerr << "Cannot add more traps than there is space." << std::endl;
		std::cerr << "Tried adding " << this->num_traps << " traps but only " << area << " is available." << std::endl;
		return this;
	}

	// set random traps
	while (this->num_traps > 0) {
		int x = rand() % this->length;
		int y = rand() % this->width;

		if (trap_grid[y][x] == '\0')
		{
			int trap = rand() % Trap::NUM_TRAPS;
			switch (trap) {
				case Trap::fire:
					trap_grid[y][x] = '$';
					break;
				case Trap::spikes:
					trap_grid[y][x] = '^';
					break;
				case Trap::web:
					trap_grid[y][x] = '#';
					break;
				case Trap::bomb:
					trap_grid[y][x] = 'X';
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
  	stream << "╔"; // North Wall
	for (int i = 0; i < maze->width * 3; i++) stream << "═";
	stream << "╗" << std::endl;

	for (int i = 0; i < maze->length; i++) {
		int row = 0;
		for (int j = 0; j < maze->width; j++) {
			if (j == 0) {
				stream << "║"; // West Wall
			}

			char room = maze->grid[j][i];
			std::string openings = "";
			switch (room - '0') {
				case Room::N:
					openings = "N";
					break;
				case Room::NE:
					openings = "NE";
					break;
				case Room::NS:
					openings = "NS";
					break;
				case Room::NW:
					openings = "NW";
					break;
				case Room::NES:
					openings = "NES";
					break;
				case Room::NEW:
					openings = "NEW";
					break;
				case Room::NSW:
					openings = "NSW";
					break;
				case Room::NESW:
					openings = "NESW";
					break;
				case Room::E:
					openings = "E";
					break;
				case Room::EW:
					openings = "EW";
					break;
				case Room::S:
					openings = "S";
					break;
				case Room::SE:
					openings = "SE";
					break;
				case Room::SW:
					openings = "SW";
					break;
				case Room::SEW:
					openings = "SEW";
					break;
				case Room::W:
					openings = "W";
					break;
			}

			if (row == 0) {
				// Print North wall of each room in the row
				if (j == 0 && i == 0) {
					stream << "╔";
				} else {
					stream << "╦";
				}

				if (openings.find('N') == std::string::npos) {
					stream << "═";
				} else {
					stream << ' ';
				}

				if (j == maze->width - 1 && i == 0) {
					stream << "╗";
				} else {
					stream << "╦";
				}
			} else if (row == 1) {
				// Print West wall of each room in the row
				if (openings.find('W') == std::string::npos) {
					stream << "║";
				} else {
					stream << ' ';
				}

				// Prints the trap that exists there, if one exists
				char trap = maze->trap_grid[j][i];
				stream << (trap == '\0' ? ' ' : trap);

				// Print East wall of each room in the row
				if (openings.find('E') == std::string::npos) {
					stream << "║";
				} else {
					stream << ' ';
				}
			} else {
				// Print South wall of each room in the row
				if (j == 0 && i == maze->length - 1) {
					stream << "╚";
				} else {
					stream << "╩";
				}

				if (openings.find('S') == std::string::npos) {
					stream << "═";
				} else {
					stream << ' ';
				}

				if (j == maze->width - 1 && i == maze->length - 1) {
					stream << "╝";
				} else {
					stream << "╩";
				}
			}

			if (j == maze->width - 1 && row < 2) {
				row++;
				j = -1;
				stream << "║" << std::endl; // East Wall
			}
		}
		
		stream << "║" << std::endl; // East Wall
	}

	stream << "╚"; // South Wall
	for (int i = 0; i < maze->width * 3; i++) stream << "═";
	stream << "╝" << std::endl;
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
		ofile << this << std::endl;
}