#pragma once
#include"stdafx.h"
#include"Ellipse.h"

class  Rectangle : public Object
{
public:
	Rectangle() {};
	Rectangle(Point a, Point b, Point c, Point d);
	string type();
	double distance(Point &A, Point &B);
	void ToStd(std::ostream&fout);
	void read(ifstream&fin);
	void ToFile(std::ofstream&fout);
	Point* getA() { return &A; };
	Point* getB() { return &B; };
	Point* getC() { return &C; };
	Point* getD() { return &D; };
private:
	Point A;
	Point B;
	Point C;
	Point D;
};

inline Rectangle::Rectangle(Point a, Point b, Point c, Point d)
{
}

inline string Rectangle::type()
{
	double AB = distance(A, B);
	double BC = distance(B, C);
	double CD = distance(C, D);
	double DA = distance(D, A);

	if (AB == BC == CD == DA)
	{
		return sysMsgs[lang_now][10];
	}
	else
	{
		return sysMsgs[lang_now][11];
	}
}

inline double Rectangle::distance(Point & A, Point & B)
{
	return sqrt(pow(A.GetX() - B.GetX(), 2) + pow(A.GetY() - B.GetY(), 2));
}

inline void Rectangle::ToStd(std::ostream & fout)
{
	fout << type() << ":" << endl << " Точка A: " << A << "Точка B: " << B << "Точка C: " << C << "Точка D: " << D << endl;
}

inline void Rectangle::read(ifstream & fin)
{
	fin >> this->A >> this->B >> this->C >> this->D;
}

inline void Rectangle::ToFile(std::ofstream & fout)
{
	fout << type() << endl << A << B << C << D;
}
