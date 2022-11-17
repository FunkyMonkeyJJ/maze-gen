#include "maze.cpp"

int main(int argc, char const *argv[])
{
	Maze* m = new Maze("Simple Maze", 20, 10);
	m->set_num_traps(30)->generate()->print();
	m->export_to_file("file.txt");

	Maze* n = new Maze("Another Maze", 50, 3);
	n->set_num_traps(3)->generate()->print();

	Maze* o = new Maze("Huge Maze", 50, 400);
	o->set_num_traps(20000)->generate();
	o->export_to_file("file.txt");

	return 0;
}