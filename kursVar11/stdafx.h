// stdafx.h: включаемый файл для стандартных системных включаемых файлов
// или включаемых файлов для конкретного проекта, которые часто используются, но
// не часто изменяются
//

#pragma once

#include "targetver.h"

#include <stdio.h>
#include <tchar.h>
#include<iostream>
#include <fstream>
#include<istream>
#include <string>
#include<vector>
#include<conio.h>

using namespace std;

#define COUNT_FILES 8
#define COUNT_STRS_TRANSLETE 97
#define COUNT_SYS_MSG 40
extern string langs[2][COUNT_STRS_TRANSLETE];
extern string sysMsgs[2][COUNT_SYS_MSG];
extern int count_strs_all[8];

extern string config_path;

extern enum lang {
	rus,
	eng
};
extern enum namefile {
	readme,
	aboutme,
	aboutprog
};
extern enum slides {
	none = -1,
	start,
	change_lang,
	menu,
	edit_config,
	demonstration,
	ellipse,
	rectangle
};

extern string include_files[COUNT_FILES];
extern int lang_now;
