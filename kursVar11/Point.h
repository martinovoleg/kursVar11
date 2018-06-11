#pragma once
#include"stdafx.h"
#include"object.h"

class Point : public Object {
	float X;
	float Y;
	void ToStd(std::ostream&fout) {}
	void read(ifstream&fin) {};
	void ToFile(std::ofstream&fout) {};
	string type() { return ""; };
public:
	float GetX() {
		return X;
	}

	void SetX() {
		string number;
		bool IsNumber = false;

		while (!IsNumber)
		{
			std::cout << sysMsgs[lang_now][1];
			std::cin >> number;
			IsNumber = is_number(number);
			if (!IsNumber)
			{
				std::cout << sysMsgs[lang_now][14] << std::endl;
			}
		}

		X = stod(number);
	}

	float GetY() {
		return Y;
	}

	void SetY() {
		string number;
		bool IsNumber = false;

		while (!IsNumber)
		{
			std::cout << sysMsgs[lang_now][2];
			std::cin >> number;
			IsNumber = is_number(number);
			if (!IsNumber)
			{
				std::cout << sysMsgs[lang_now][14] << std::endl;
			}
		}
		Y = stod(number);
	}

	void SetCoordinate(float pX, float pY)
	{
		X = pX;
		Y = pY;
	}

	Point(float pX, float pY) : X(pX), Y(pY)
	{
	}

	Point() : X(0), Y(0) {};

	friend ostream& operator<<(ostream& output, Point&point);
	friend ofstream& operator<<(ofstream& output, Point&point);
	friend ifstream& operator>>(ifstream& output, Point&point);
};