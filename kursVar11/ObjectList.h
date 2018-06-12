#pragma once
#include"stdafx.h"
#include"Rectangle.h"

class ObjectList {
private:
	int countEllipse = 0;
	int countCircle = 0;
	int countSquare = 0;
	int countRectangle = 0;
public:

	vector<Object*> objects;
	size_t getCountCircle();
	size_t getCountEllipse();
	size_t getCountSquare();
	size_t getCountRectangle();
	size_t size();
	void push_back(Object* object);
	bool DeleteLastItemByTag(string type);
	bool EditItemInPos(int pos = -1, Object *obj = nullptr);
	ObjectList() {};
	friend ostream& operator<<(ostream& output, ObjectList&container);
	friend ofstream& operator<<(ofstream& output, ObjectList&container);
	friend ifstream& operator>>(ifstream& output, ObjectList&container);
};
