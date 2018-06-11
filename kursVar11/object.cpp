#include"stdafx.h"
#include"object.h"

std::ofstream& operator<<(std::ofstream&fout, Object* obj) {
	obj->ToFile(fout);
	return fout;
}

std::ifstream & operator>>(std::ifstream & fin, Object * o)
{
	o->read(fin);
	return fin;
}

std::ostream & operator<<(std::ostream & out, Object * obj)
{
	obj->ToStd(out);
	return out;
}

bool Object::is_number(string & s, bool isMark)
{
	double number;
	try
	{
		number = std::stod(s);
	}
	catch (...)
	{
		return false;
	}
	if (isMark == false && number < 0)
	{
		return false;
	}
	return true;
}