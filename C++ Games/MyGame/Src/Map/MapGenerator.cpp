#include "MapGenerator.h"
#include "RNG.h"
#include "App.h"

#define NOT_INITIALISED 10000
#define GENERATING_OFFSET 2
#define MAX_ABS 30


MapGenerator::MapGenerator()
{
}

MapGenerator::~MapGenerator()
{
}

std::vector<std::vector<int> > MapGenerator::Generate(uint rows, uint columns, std::pair<int, int> interval, uint depth)
{
	std::vector<std::vector<int> > *mapMatrix = new std::vector<std::vector<int> >(rows, std::vector<int>(columns, NOT_INITIALISED));

	RandomFill(mapMatrix, interval);
	Smooth(depth, mapMatrix);

	return *mapMatrix;
}

void MapGenerator::RandomFill(std::vector<std::vector<int> > *matrix, std::pair<int, int> interval)
{
	for (uint i = 0; i < matrix->size(); ++i)
	{
		for (uint j = 0; j < matrix[0].size(); ++j)
		{
			if (i == 0 || i == matrix->size() - 1 || j == 0 || j == matrix[0].size() - 1)
			{
				matrix->at(i).at(j) = -1;
			}
			else
			{
				matrix->at(i).at(j) = RNG::Int(interval.first, interval.second);
			}
		}
	}
}

void MapGenerator::Smooth(int depth, std::vector<std::vector<int> > *matrix)
{
	if (depth == 0) return;

	for (int i = 1; i < (int)matrix->size() - 1; ++i)
	{
		for (int j = 1; j < (int)matrix[0].size() - 1; ++j)
		{
			int sum = 0;
			int count = 0;
			for (int x = i - 1; x < i + 2; ++x)
			{
				for (int y = j - 1; y < j + 2; ++y)
				{
					if (x >= 0 && x < (int)matrix->size() && y >= 0 && y < (int)matrix[0].size())
					{
						if (x != i || y != j)
						{
							sum += matrix->at(x).at(y);
							count++;
						}
					}
				}
			}
			matrix->at(i).at(j) = (matrix->at(i).at(j) + sum / count) / 2;
		}
	}

	Smooth(depth - 1, matrix);
}