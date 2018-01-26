#pragma once

#include "Vector2.h"

#include <fstream>
#include <vector>

class TXTWriter
{

public:
	static void WriteVector2(std::string path, const std::vector<Vector2> vectors)
	{
		std::ofstream file(path, std::ios::out);

		file << std::fixed << std::showpoint;
		
		for (const Vector2 v : vectors)
		{
			file << v.x << " " << v.y << "\n";
		}
	}

};