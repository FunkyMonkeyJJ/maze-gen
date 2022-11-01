#ifndef Maze_HPP
#define Maze_HPP

#include <string>

class Maze
{
private:
	std::string name;
public:
	Maze(std::string name);

	~Maze();

	void generate();
};
#endif