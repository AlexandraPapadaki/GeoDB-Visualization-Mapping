//Visualization 


#include "Vector2.h"
#include "TXTReader.h"
#include "TXTWriter.h"

#include <ostream>
#include <iostream>

using namespace std;

int main()
{
	vector<Vector2> polygon = TXTReader::ReadVector2("C:/Users/Alexandra/Desktop/2nd semester/Visualization/Exercises/Exercise 4/Polygon1/Polygon1.txt");
	cout << "Amount of initial points of the polygon: " << polygon.size() - 1 << endl;

	///////////////////1st check - Distance/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Define a threshold for 1st check
	double threshold1 = 5.0;
	cout << "The threshold for the distance in the 1st check is :" << threshold1 << endl;

	//Apply test
	float distance;

	for (int i = 0; i < polygon.size(); i++)
	{
		for (int j = 0; j <polygon.size()- 1; j++)
		{
			if (i == j) continue;
			distance = sqrt(pow((polygon[i].x - polygon[j].x), 2) + pow((polygon[i].y - polygon[j].y), 2));
			if (distance < threshold1)
			{
				polygon.erase(polygon.begin() + (1 + j));
			}
		}
	}

	polygon.push_back(polygon[0]);

	cout << "Amount of points of the polygon after the distance check: " << polygon.size() - 1 << endl;

	//Save the results in a .txt file called polygon_new
	TXTWriter::WriteVector2("C:/Users/Alexandra/Desktop/2nd semester/Visualization/Exercises/Exercise 4/Polygon1/Polygon1new.txt", polygon);

	//////////////////2nd check - Perpendicular distance//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	//Define a threshold for 2nd check
	double threshold2 = 2.0;
	cout << "The threshold for the distance is :" << threshold2 << endl;

	//New polygon, after the 1st check
	vector<Vector2> polygon_final;
	polygon_final.push_back(polygon[0]);

	//Apply test
	float distance2;

	int Pbegin, Pend;
	Pbegin = 0;
	Pend = 2;

	while (Pend < polygon.size() - 1)
	{
		for (int i = Pend - 1; i > Pbegin; i--)
		{
			distance2 = abs((polygon[Pend].y - polygon[Pbegin].y)*polygon[i].x - (polygon[Pend].x - polygon[Pbegin].x)*polygon[i].y + polygon[Pend].x*polygon[Pbegin].y - polygon[Pend].y*polygon[Pbegin].x)
				/ sqrt(pow((polygon[Pend].y - polygon[Pbegin].y), 2) + pow((polygon[Pend].x - polygon[Pbegin].x), 2));

			if (distance2 > threshold2)
			{
				polygon_final.push_back(polygon[Pend - 1]);
				Pbegin = Pend - 1;
				break;
			}

		}
		Pend++;
	}
	polygon_final.push_back(polygon[0]);
	cout << "Amount of points of the polygon after the 2nd check: " << polygon_final.size() - 1 << endl;

	//Save the results in a .txt file called polygon_final
	TXTWriter::WriteVector2("C:/Users/Alexandra/Desktop/2nd semester/Visualization/Exercises/Exercise 4/Polygon1/Polygon1final.txt", polygon_final);

	std::system("PAUSE");
	return 0;
}