#include <iostream>
#include "maze.cpp"

int main(int argc, char const *argv[])
{
	std::cout << "Something" << std::endl;
	Maze* m = new Maze("New Maze");
	m->generate();
	return 0;
}