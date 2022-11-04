#include <iostream>
#include "maze.cpp"

int main(int argc, char const *argv[])
{
	Maze* m = new Maze("Simple Maze", 20, 10);
	m->set_num_rooms(10)->set_num_traps(10)->generate()->print();

	Maze* n = new Maze("Another Maze", 100, 3);
	n->set_num_rooms(5)->set_num_traps(3)->generate()->print();

	return 0;
}

// All Combinations of Room Openings
// N, NE, NS, NW, NES, NEW, NSW, NESW
// E, EW
// S, SE, SW, SEW
// W

// Add functionality to import/export the maze to and from a file