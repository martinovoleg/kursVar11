// stdafx.cpp: исходный файл, содержащий только стандартные включаемые модули
// kursVar11.pch будет использоваться в качестве предкомпилированного заголовка
// stdafx.obj будет содержать предварительно откомпилированные сведения о типе

#include "stdafx.h"

// TODO: Установите ссылки на любые требующиеся дополнительные заголовки в файле STDAFX.H
// , а не в данном файле

int lang_now = rus;
std::string include_files[COUNT_FILES];
std::string config_path = "config.txt";
string langs[2][COUNT_STRS_TRANSLETE];
int count_strs_all[8] = { COUNT_STRS_TRANSLETE, COUNT_STRS_TRANSLETE,13,3,28,22,3,32 };
string sysMsgs[2][COUNT_SYS_MSG];