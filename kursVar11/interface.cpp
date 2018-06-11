#include"stdafx.h"
#include "interface.h"

#define EXIT(isExit) if((isExit)){cin.get();exit(-1);}

ObjectList container;

void Interface::cls() {
	system("cls");
}

void Interface::PrintFile(int namefile, int locale, string path)
{
	ifstream fin;
	fin.exceptions(ios::failbit);
	try {
		if (path == "")
			fin.open(include_files[namefile + 2 + locale * 3]);
		else
			fin.open(path);
		string temp;
		while (!fin.eof()) {
			getline(fin, temp);
			cout << temp << endl;
		}
		fin.close();
	}
	catch (std::exception const& e) {
		if (locale == eng)
			cerr << "unable to open file" << endl;
		else if (locale == rus)
			cerr << "не удалось открыть файл" << endl;
	}
}

void Interface::Put(Range range, int locale)
{
	for (range.left; range.left <= range.right; range.left++)
		cout << langs[locale][range.left - 1] << endl;
}

bool Interface::UploadFilesMemory()
{
	string rumsg;
	string enmsg;
	ifstream ruin;
	ifstream enin;
	bool result = true;
	ruin.exceptions(ifstream::failbit);
	enin.exceptions(ifstream::failbit);

	try {
		ruin.open(include_files[0]);
		enin.open(include_files[1]);
		int now = 0;

		while (!ruin.eof() && !enin.eof() && getline(ruin, rumsg) && getline(enin, enmsg))
		{
			if (now < COUNT_STRS_TRANSLETE) {
				langs[0][now] = rumsg;
				langs[1][now++] = enmsg;
			}
		}
		ruin.close();
		enin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file with translate" << endl;
		else if (lang_now == rus)
			cerr << "не удалось открыть файл с перводом" << endl;
		result = false;
	}
	return result;
}

void MsgInit() {
	sysMsgs[rus][0] = "ОШИБКА! Файла не существует или количество строк не совпадает";
	sysMsgs[eng][0] = "ERROR! File is no exist or count str's is no correct";
	sysMsgs[rus][1] = "Введите координату Х: ";
	sysMsgs[eng][1] = "Enter the X coordinate: ";
	sysMsgs[rus][2] = "Введите координату Y: ";
	sysMsgs[eng][2] = "Enter the Y coordinate: ";
	sysMsgs[rus][3] = "Введите малый радиус: ";
	sysMsgs[eng][3] = "Enter a small radius: ";
	sysMsgs[rus][4] = "Введите большой радиус: ";
	sysMsgs[eng][4] = "Enter a large radius: ";
	sysMsgs[rus][5] = "Введите координаты центра окружности: ";
	sysMsgs[eng][5] = "Enter the coordinates of the center of the circle: ";
	sysMsgs[rus][6] = "Oкружность";
	sysMsgs[eng][6] = "Circle";
	sysMsgs[rus][7] = "Эллипс";
	sysMsgs[eng][7] = "Ellipse";
	sysMsgs[rus][8] = " малый радиус: ";
	sysMsgs[eng][8] = " small radius: ";
	sysMsgs[rus][9] = " большой радиус: ";
	sysMsgs[eng][9] = " large radius: ";
	sysMsgs[rus][10] = "Квадрат";
	sysMsgs[eng][10] = "Square";
	sysMsgs[rus][11] = "Прямоугольник";
	sysMsgs[eng][11] = "Rectangle";
	sysMsgs[rus][12] = "1. Малый радиус";
	sysMsgs[eng][12] = "1. Small radius";
	sysMsgs[rus][13] = "2. Большой радиус";
	sysMsgs[eng][13] = "2. Large radius";
	sysMsgs[rus][14] = "Incorrect value entered, try again!";
	sysMsgs[eng][14] = "Введено некоректное значение, попробуйте еще раз!";
	sysMsgs[rus][15] = "3. Координаты центра";
	sysMsgs[eng][15] = "3. The coordinates of the center";
	sysMsgs[rus][16] = "Esc. Назад";
	sysMsgs[eng][16] = "Esc. Back";
	sysMsgs[rus][17] = "1. Координаты точки A";
	sysMsgs[eng][17] = "1. The coordinates of point A";
	sysMsgs[rus][18] = "2. Координаты точки B";
	sysMsgs[eng][18] = "2. The coordinates of point B";
	sysMsgs[rus][19] = "3. Координаты точки C";
	sysMsgs[eng][19] = "3. The coordinates of point C";
	sysMsgs[rus][20] = "3. Координаты точки D";
	sysMsgs[eng][20] = "3. The coordinates of point D";
	sysMsgs[rus][21] = "Выберите поле для заполнения/редактирования: ";
	sysMsgs[eng][21] = "Select a field for filling / editing: ";
	sysMsgs[rus][22] = "Введите номер элемента: ";
	sysMsgs[eng][22] = "Enter the element number: ";
}

void Interface::Init(std::string config) {
	static int firstrun = 1;
	Interface::UseConfig(config);
	if (firstrun) {
		firstrun = 0;
		system("chcp 1251>nul");
		setlocale(0, "rus");
		MsgInit();
	}
	bool isExit = !Interface::CheckIncludeFiles();//если недостаточно файлов или кол-во строк не совпадают
	EXIT(isExit);
	isExit = !Interface::UploadFilesMemory();//если не смог открыть файл с переводом
	EXIT(isExit);
}

void Interface::UseConfig(std::string config) {
	fstream fin;
	fin.exceptions(ios::failbit);
	try {
		fin.open(config);
		for (int i = 0; i < COUNT_FILES; i++) {
			getline(fin, include_files[i]);
		}

		fin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file with config" << endl;
		else if (lang_now == rus)
			cerr << "не удалось открыть файл с конфигом" << endl;
	}
}

int NumStrs(string file) {
	ifstream inp(file);
	string s;
	int count = 0;
	while (getline(inp, s))
		count++;
	return count;
}

bool Interface::CheckIncludeFiles(string file) {
	bool result = true;
	int now = 0;
	if (file == "")
		for (auto file : include_files)
		{
			if (!fopen(file.c_str(), "r")) {
				if (NumStrs(file) < count_strs_all[now++]) {
					result = false;
					cout << file << endl;
					Interface::SystemPut(1, lang_now, ' ');
					cout << "(" << NumStrs(file) << " < " << count_strs_all[now - 1] << ")";
				}
			}
		}
	else
		if (!fopen(file.c_str(), "r"))
			result = false;

	return result;
}

void Interface::Put(int num, int locale, char end) {
	cout << langs[locale][num - 1] << end;
}

void Interface::SystemPut(int num, int locale, char end) {
	cout << sysMsgs[locale][num - 1] << end;
}

void Interface::DrawSlide(int slide, int back_slide) {
	char key;
	string temp;
	if (slide == start) {
		Put(Range(2, 30));
		do {
			key = _getch();
			if (key == '1') {
				Interface::DrawSlide(change_lang, start);
				return;
			}
		} while (key != '2');
	}
	else if (slide == change_lang) {
		Interface::cls();
		/*for (int phrase = 31; phrase <= 33; phrase++)
		Interface::Put(phrase);*/
		Put(Range(31, 33));
		do {
			key = _getch();
			switch (key) {
			case '1':
				lang_now = rus;
				Interface::cls();
				break;
			case '2':
				lang_now = eng;
				Interface::cls();
				break;
			}
		} while (key != '1'&&key != '2');

		Interface::DrawSlide(back_slide, menu);
	}
	else if (slide == menu) {
		Interface::cls();

		Put(Range(34, 42));
		do {
			key = _getch();
			switch (key)
			{
			case '1':
				Interface::DrawSlide(edit_config, menu);
				return;
				break;
			case '2':
				Interface::SaveData();
				break;
			case '3':
				Interface::DrawSlide(change_lang, menu);
				return;
			case '4':
				Interface::DrawSlide(demonstration, menu);
				return;
			case '5':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(readme);
				cout << "---------------------------------" << endl;
				break;
			case'6':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(aboutme);
				cout << "---------------------------------" << endl;
				break;
			case'7':
				cout << endl << "---------------------------------" << endl;
				Interface::PrintFile(aboutprog);
				cout << "---------------------------------" << endl;
				break;
			case '8':
				Interface::LoadData();
				break;
			case 'r':
			case 'к'://refresh
				Interface::DrawSlide(menu);
				return;
				break;
			}
		} while (key != 27);
	}
	else if (slide == edit_config) {
		Interface::cls();

		Put(Range(43, 56));
		do {
			key = _getch();
			if (key >= '1' && key <= '8') {
				cout << endl << endl;
				Put(57, lang_now, ' '); //name:
				getline(cin, temp);

				if (fopen(temp.c_str(), "r")) {
					if (NumStrs(temp) < count_strs_all[key - 49]) {
						SystemPut(1, lang_now, ' ');
						cout << "(" << NumStrs(temp) << "<" << count_strs_all[key - 49] << ")\n";
					}
					else {
						include_files[key - 49] = temp;
						cout << "+" << endl;
						if (key == '1' || key == '2')
							EXIT(!UploadFilesMemory());
					}
				}
				else Interface::Put(1);
			}
			else if (key == 's' || key == 'ы')
				Interface::SaveConfig();

			else if (key == 'c' || key == 'с') {
				Interface::DrawSlide(change_lang, edit_config);
				return;
			}
		} while (key != 'd' && key != 'в');

		Interface::DrawSlide(back_slide, menu);
	}
	else if (slide == demonstration) {
		Interface::cls();

		Put(Range(59, 61));
		Put(65);
		Put(Range(74, 77));

		do {
			key = _getch();

			if (key == '1') {
				Interface::DrawSlide(ellipse, demonstration);
				return;
			}
			else if (key == '2') {
				Interface::DrawSlide(rectangle, demonstration);
				return;
			}

			else if (key == 'w' || key == 'ц') {
				string number;
				Object *obj = nullptr;
				bool isNumber = false;
				while (!isNumber) {
					cout << sysMsgs[rus][22];
					cin >> number;
					isNumber = obj->is_number(number);

					if (!isNumber)
					{
						std::cout << sysMsgs[lang_now][14] << std::endl;
					}
				}

				int pos = stod(number);

				if (!container.EditItemInPos(pos)) {
					Interface::DrawSlide(demonstration, menu);
				}
			}
			else if (key == 's' || key == 'ы') {
				cout << endl << container;
			}
			else if (key == 'c' || key == 'с') {
				Interface::DrawSlide(change_lang, demonstration);
			}
			else if (key == 'o' || key == 'щ') {
				Interface::Put(88, lang_now, ' ');

				cout << sysMsgs[lang_now][6] << ": " << container.getCountCircle() << endl;
				cout << sysMsgs[lang_now][7] << ": " << container.getCountEllipse() << endl;
				cout << sysMsgs[lang_now][10] << ": " << container.getCountSquare() << endl;
				cout << sysMsgs[lang_now][11] << ": " << container.getCountRectangle() << endl;
			}
		} while (key != 'b' && key != 'и');

		Interface::DrawSlide(menu, menu);
		return;
	}
	else if (slide == ellipse) {
		do {
			Interface::cls();
			Interface::Put(68);
			Interface::Put(69);
			Interface::Put(74);
			Interface::Put(75);

			key = _getch();

			if (key == '1') {
				Object*obj = new Ellipse();
				container.EditItemInPos(-1, obj);
				container.push_back(obj);
			}
			else if (key == '2') {
				string tag;
				char key = 1;

				while (key != '27')
				{
					cout << "1." + sysMsgs[lang_now][6] << endl;
					cout << "2." + sysMsgs[lang_now][7] << endl;

					key = _getch();

					if (key == '1')
					{
						container.DeleteLastItemByTag(sysMsgs[lang_now][6]);
					}
					else if (key == '2')
					{
						container.DeleteLastItemByTag(sysMsgs[lang_now][7]);
					}
				}
			}
			else if (key == 'c' || key == 'с') {
				Interface::DrawSlide(change_lang, demonstration);
			}
		} while (key != 'b'&&key != 'и');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
	else if (slide == rectangle) {
		do {
			Interface::cls();
			Interface::Put(71);
			Interface::Put(72);
			Interface::Put(74);
			Interface::Put(75);
			key = _getch();

			if (key == '1') {
				Object*obj = new Rectangle();
				container.EditItemInPos(-1, obj);
				container.push_back(obj);
			}
			else if (key == '2') {
				char key = 1;

				while (key != '27')
				{
					cout << "1." + sysMsgs[lang_now][10] << endl;
					cout << "2." + sysMsgs[lang_now][11] << endl;

					key = _getch();

					if (key == '1')
					{
						container.DeleteLastItemByTag(sysMsgs[lang_now][10]);
					}
					else if (key == '2')
					{
						container.DeleteLastItemByTag(sysMsgs[lang_now][11]);
					}
				}
			}
			else if (key == 'c' || key == 'с') {
				Interface::DrawSlide(change_lang, demonstration);
			}
		} while (key != 'b'&&key != 'и');
		Interface::DrawSlide(demonstration, back_slide);
		return;
	}
}

void Interface::LoadData()
{
	ifstream fin;
	fin.exceptions(ios::badbit);
	try {
		fin.open("data/data.txt");
		fin >> container;

		Interface::Put(58);
		//cout << endl;
		//cout << container;
		fin.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << endl << "unable to found last session" << endl;
		else if (lang_now == rus)
			cerr << endl << "не удалось найти последнюю сессию" << endl;
	}
}

void Interface::SaveData()
{
	if (container.size()) {
		ofstream fout("data/data.txt");
		fout << container;
		fout.close();
		if (lang_now == eng)
			cout << endl << "session saved" << endl;
		else if (lang_now == rus)
			cout << endl << "сессия сохранена" << endl;
	}
	else {
		if (lang_now == eng)
			cerr << endl << "session is clear" << endl;
		else if (lang_now == rus)
			cerr << endl << "сессия пуста" << endl;
	}
}

void Interface::SaveConfig() {
	ofstream fout;
	try {
		fout.exceptions(ios::badbit);
		fout.open(config_path);
		for (auto file : include_files)
		{
			fout << file << endl;
		}
		fout.close();
	}
	catch (std::exception const& e) {
		if (lang_now == eng)
			cerr << "unable to open file" << endl;
		else if (lang_now == rus)
			cerr << "не удалось открыть файл" << endl;
	}
}