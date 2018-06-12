#include"stdafx.h"
#include"Point.h"

ostream & operator<<(ostream & output, Point & point)
{
	output << endl << " X: " << point.GetX() << endl << " Y: " << point.GetY() << endl;
	return output;
}

ofstream & operator<<(ofstream & output, Point & point)
{
	output << point.GetX() << endl << point.GetY() << endl;
	return output;
}

ifstream & operator>>(ifstream & output, Point& point)
{
	string X, Y;
	output >> X >> Y;

	point.X = atof(X.c_str());
	point.Y = atof(Y.c_str());
	return output;
}