// kursVar11.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include"interface.h"

int main()
{
	setlocale(LC_ALL, ".1251");
	Interface::Init(config_path);

	Interface::DrawSlide(start);
	Interface::DrawSlide(menu);
	system("pause");
	return 0;
}