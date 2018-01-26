#pragma once

#include "Vector2.h"

#include <fstream>
#include <sstream>
#include <vector>

class TXTReader
{

public:
	static std::vector<Vector2> ReadVector2(const std::string path)
	{
		std::vector<Vector2> result;
		std::ifstream file(path, std::ios::in);

		std::string coord;

		while (file && !file.eof())
		{
			std::getline(file, coord);
			if (!coord.empty())
			{
				int delim_pos = coord.find(" ");
				result.push_back(Vector2(atof(coord.substr(0, delim_pos).c_str()), atof(coord.substr(delim_pos+1, coord.size()-delim_pos-1).c_str())));
			}				
		}

		return result;
	}

};