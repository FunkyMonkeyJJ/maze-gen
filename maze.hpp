#ifndef Maze_HPP
#define Maze_HPP

#include <string>
#include <vector>

class Maze
{
private:
	std::string name;
	int length;
	int width;

	std::vector<std::vector<char>> grid;
	int num_rooms;
	int num_traps;
public:
	Maze(std::string name, int length, int width);

	Maze* set_num_rooms(int num_rooms);

	Maze* set_num_traps(int num_traps);

	Maze* generate();
	
	void print();

	Maze* import_from_file(std::string filename);

	void export_to_file(std::string filename);
};
#endif