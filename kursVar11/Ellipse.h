#pragma once
#include"Point.h"

class Ellipse : public Object {
private:
	float a;
	float b;
	Point* Center;
public:
	void ToStd(std::ostream&fout);
	void read(ifstream&fin);
	void ToFile(std::ofstream&fout);

	float Get_a() {
		return a;
	}

	void Set_a()
	{
		string number;
		bool IsNumber = false;

		while (!IsNumber)
		{
			std::cout << sysMsgs[lang_now][3];
			std::cin >> number;
			IsNumber = is_number(number, true);
			if (!IsNumber)
			{
				std::cout << sysMsgs[lang_now][14] << endl;
			}
		}

		a = stod(number);
	}

	void Set_b()
	{
		string number;
		bool IsNumber = false;

		while (!IsNumber)
		{
			std::cout << sysMsgs[lang_now][4];
			std::cin >> number;
			IsNumber = is_number(number, true);
			if (!IsNumber)
			{
				std::cout << sysMsgs[lang_now][14] << endl;
			}
		}

		b = stod(number);
	}

	float Get_b() {
		return b;
	}

	Point* GetCenter() {
		return Center;
	}

	void setCenter()
	{
		std::cout << sysMsgs[lang_now][5] << endl;
		Center->SetX();
		Center->SetY();
	}

	string type() {
		if (a == b) {
			return sysMsgs[lang_now][6];
		}
		else {
			return sysMsgs[lang_now][7];
		}
	}

	Ellipse() : a(0), b(0)
	{
		Center = new Point();
	}

	Ellipse(Point* pCenter, float pA, float pB) : a(pA), b(pB)
	{
		Center = new Point();
		*Center = *pCenter;
	}

	friend float operator-(Ellipse &pEllipse1, Ellipse &pEllipse2)
	{
		float result = pow(pEllipse2.Center->GetX() - pEllipse1.Center->GetX(), 2);
		result += pow(pEllipse2.Center->GetY() - pEllipse1.Center->GetY(), 2);
		result = sqrt(result);
		return result;
	}

	~Ellipse() {
		delete Center;
	}
};
