#ifndef Maze_HPP
#define Maze_HPP

#include <fstream>
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

	//std::ostream& operator<<(std::ostream &stream);

	friend std::ostream& operator<<(std::ostream &stream, const Maze &maze);

	friend std::ostream& operator<<(std::ostream &stream, const Maze *maze);
	
	void print();

	Maze* import_from_file(std::string filename);

	Maze* import_from_file(std::ifstream file);

	void export_to_file(std::string filename);

	void export_to_file(std::ofstream file);
};
#endif