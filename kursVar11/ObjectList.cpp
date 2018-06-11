#include"stdafx.h"
#include"ObjectList.h"

ostream & operator<<(ostream & output, ObjectList & container)
{
	for (auto item : container.objects) {
		output << item;
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
	}
	return output;
}

size_t ObjectList::getCountCircle()
{
	for (auto item : objects)
	{
		countCircle = 0;

		if (item->type() == sysMsgs[lang_now][6])
		{
			countCircle++;
		}
	}
	return countCircle;
}

size_t ObjectList::getCountEllipse()
{
	for (auto item : objects)
	{
		countEllipse = 0;

		if (item->type() == sysMsgs[lang_now][7])
		{
			countEllipse++;
		}
	}
	return countEllipse;
}

size_t ObjectList::getCountSquare()
{
	for (auto item : objects)
	{
		countSquare = 0;

		if (item->type() == sysMsgs[lang_now][10])
		{
			countSquare++;
		}
	}
	return countSquare;
}

size_t ObjectList::getCountRectangle()
{
	for (auto item : objects)
	{
		countRectangle = 0;

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

void ObjectList::DeleteLastItemByTag(string type)
{
	for (int i = objects.size() - 1; i--; )
	{
		if (objects[i]->type() == type)
		{
			objects.erase(objects.begin() + (i - 1), objects.begin() + i);
			break;
		}
	}
}

bool ObjectList::EditItemInPos(int pos, Object *obj)
{
	string type;
	Object* temp = nullptr;

	if (obj == nullptr)
	{
		type = objects[pos]->type();
		temp = objects[pos];
	}
	else
	{
		type = obj->type();
		temp = obj;
	}

	if ((pos < 0 || pos >= objects.size()) && obj == nullptr)
	{
		return false;
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
				((Ellipse*)temp)->Set_a();
			}break;
			case '2':
			{
				((Ellipse*)temp)->Set_b();
			}break;

			case '3':
			{
				((Ellipse*)temp)->setCenter();
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
				temp = ((Rectangle*)temp)->getA();
				temp->SetX();
				temp->SetY();
			}break;
			case '2':
			{
				temp = ((Rectangle*)temp)->getB();
				temp->SetX();
				temp->SetY();
			}break;

			case '3':
			{
				temp = ((Rectangle*)temp)->getC();
				temp->SetX();
				temp->SetY();
			}break;
			case '4':
			{
				temp = ((Rectangle*)temp)->getD();
				temp->SetX();
				temp->SetY();
			}break;
			default:
				break;
			}
			system("cls");
		}
	}
}