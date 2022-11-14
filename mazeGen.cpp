#include "maze.cpp"

int main(int argc, char const *argv[])
{
	Maze* m = new Maze("Simple Maze", 20, 10);
	m->set_num_rooms(10)->set_num_traps(10)->generate()->print();
	m->export_to_file("file.txt");

	Maze* n = new Maze("Another Maze", 50, 3);
	n->set_num_rooms(5)->set_num_traps(3)->generate()->print();

	return 0;
}