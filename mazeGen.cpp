#include "maze.cpp"

int main(int argc, char const *argv[])
{
	Maze* m = new Maze("Simple Maze", 20, 10);
	m->set_num_traps(30)->generate()->print();
	m->export_to_file("file.txt");

	Maze* n = new Maze("Another Maze", 50, 3);
	n->set_num_traps(3)->generate()->print();

	return 0;
}