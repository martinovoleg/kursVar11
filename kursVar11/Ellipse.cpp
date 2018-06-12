#include"stdafx.h"
#include"Ellipse.h"

void Ellipse::ToStd(std::ostream & fout)
{
	fout << type() << ": " << endl << sysMsgs[lang_now][8] << a << endl << sysMsgs[lang_now][9] << b << endl << sysMsgs[lang_now][28] << *Center << endl;
}

void Ellipse::read(ifstream & fin)
{
	string a, b;

	fin >> a >> b;
	fin >> *Center;

	this->a = atof(a.c_str());
	this->b = atof(b.c_str());
}

void Ellipse::ToFile(std::ofstream & fout)
{
	fout << type() << endl << a << endl << b << endl;
	fout << *Center;
}