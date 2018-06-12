#include"stdafx.h"
#include"ObjectList.h"

ostream & operator<<(ostream & output, ObjectList & container)
{
	int i = 0;

	for (auto item : container.objects) {
		output << ++i << ") " << item;
	}
	return output;
}

ofstream & operator<<(ofstream & output, ObjectList & container)
{
	for (auto item : container.objects) {
		output << item;
	}
	return output;
}

ifstream & operator>>(ifstream & output, ObjectList & container)
{
	string type;
	while (!output.eof()) {
		output >> type;
		if (type == "")
		{
			continue;
		}
		else if (type == sysMsgs[lang_now][6] || type == sysMsgs[lang_now][7])
		{
			auto item = new Ellipse();
			output >> item;
			container.push_back(item);
		}
		else if (type == sysMsgs[lang_now][10] || type == sysMsgs[lang_now][11])
		{
			auto item = new Rectangle();
			output >> item;
			container.objects.push_back(item);
		}
		type = "";
	}
	return output;
}

size_t ObjectList::getCountCircle()
{
	countCircle = 0;
	for (auto item : objects)
	{
		if (item->type() == sysMsgs[lang_now][6])
		{
			countCircle++;
		}
	}
	return countCircle;
}

size_t ObjectList::getCountEllipse()
{
	countEllipse = 0;
	for (auto item : objects)
	{
		if (item->type() == sysMsgs[lang_now][7])
		{
			countEllipse++;
		}
	}
	return countEllipse;
}

size_t ObjectList::getCountSquare()
{
	countSquare = 0;

	for (auto item : objects)
	{
		if (item->type() == sysMsgs[lang_now][10])
		{
			countSquare++;
		}
	}
	return countSquare;
}

size_t ObjectList::getCountRectangle()
{
	countRectangle = 0;

	for (auto item : objects)
	{
		if (item->type() == sysMsgs[lang_now][11])
		{
			countRectangle++;
		}
	}
	return countRectangle;
}

size_t ObjectList::size()
{
	return objects.size();
}

void ObjectList::push_back(Object* object)
{
	objects.push_back(object);
}

bool ObjectList::DeleteLastItemByTag(string type)
{
	for (int i = objects.size(); i--; )
	{
		if (objects[i]->type() == type)
		{
			objects.erase(objects.begin() + i, objects.begin() + (i + 1));
			cout << sysMsgs[lang_now][26] << endl;
			system("pause");
			return true;
		}
	}
	cout << sysMsgs[lang_now][27] << endl;
	system("pause");
	return false;
}

bool ObjectList::EditItemInPos(int pos, Object *obj)
{
	string type;
	Object* tempObj = nullptr;

	if (obj == nullptr)
	{
		if ((pos < 0 || pos >= objects.size()))
		{
			cout << sysMsgs[lang_now][31] << endl;
			system("pause");
			return false;
		}

		type = objects[pos]->type();
		tempObj = objects[pos];
	}
	else
	{
		type = obj->type();
		tempObj = obj;
	}

	char key = 1;
	if (type == sysMsgs[lang_now][6] || type == sysMsgs[lang_now][7])
	{
		while (key != 27)
		{
			cout << sysMsgs[lang_now][21] << endl;
			cout << sysMsgs[lang_now][12] << endl;
			cout << sysMsgs[lang_now][13] << endl;
			cout << sysMsgs[lang_now][15] << endl;
			cout << sysMsgs[lang_now][16] << endl;

			key = _getch();

			switch (key)
			{
			case '1':
			{
				((Ellipse*)tempObj)->Set_a();
			}break;
			case '2':
			{
				((Ellipse*)tempObj)->Set_b();
			}break;

			case '3':
			{
				((Ellipse*)tempObj)->setCenter();
			}break;

			default:
				break;
			}

			system("cls");
		}
	}
	else if (type == sysMsgs[lang_now][10] || type == sysMsgs[lang_now][11])
	{
		while (key != 27)
		{
			cout << sysMsgs[lang_now][21] << endl;
			cout << sysMsgs[lang_now][17] << endl;
			cout << sysMsgs[lang_now][18] << endl;
			cout << sysMsgs[lang_now][19] << endl;
			cout << sysMsgs[lang_now][20] << endl;
			cout << sysMsgs[lang_now][16] << endl;

			key = _getch();
			Point *temp = nullptr;

			switch (key)
			{
			case '1':
			{
				temp = ((Rectangle*)tempObj)->getA();
				temp->SetX();
				temp->SetY();
			}break;
			case '2':
			{
				temp = ((Rectangle*)tempObj)->getB();
				temp->SetX();
				temp->SetY();
			}break;

			case '3':
			{
				temp = ((Rectangle*)tempObj)->getC();
				temp->SetX();
				temp->SetY();
			}break;
			case '4':
			{
				temp = ((Rectangle*)tempObj)->getD();
				temp->SetX();
				temp->SetY();
			}break;
			default:
				break;
			}
			system("cls");
		}
	}

	return true;
}