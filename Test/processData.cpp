#include "StringAndDictParser.h"
#include "StringAndDictParser.h"
#include "../TemplateAnalizer/Analizer.h"

/*
 - Получение строки с содержимым текстового файла,
 - Чтение словаря в контейнер,
 - Начало обработки считанного текста из файла
*/
string	processData(const string &dictFilePath, const string &textFilePath)
{
	//Инициализация map & string
	map <string, string>			mp;
	map<string, string>::iterator	it;
	string							resStrFile;
	Analizer						analize; // Obj from orig. testing func
	parser							Parser;

	string							strText;
	int								i = 0;
	int								*pi;

	pi = &i;
	strText = Parser.getStringFromFile(textFilePath);
	// strText = Parser.findKeyFromText(); // Получение строки с содержимым текстового файла
	mp = Parser.dctParser(dictFilePath); // Считали словарь в контейнер
	int strSize = strText.length();
	for (int i = 0; i < strSize; i++)
	{
		if (strText[i] != '$')
			resStrFile += strText[i];
		else
			resStrFile += analize.findValue(mp, strText, &i);
	}
	return (resStrFile);
}
