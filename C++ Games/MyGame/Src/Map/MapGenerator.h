#pragma once

#include "stdincl.h"

class MapGenerator
{
public:

	MapGenerator();
	~MapGenerator();

	std::vector<std::vector<int> >				Generate(uint rows, uint columns, std::pair<int, int> interval, uint depth);
	void										RandomFill(std::vector<std::vector<int> >* matrix, std::pair<int, int> interval);
	void										Smooth(int depth, std::vector<std::vector<int> >* matrix);
	

private:

};

