#include "StringAndDictParser.h"
#include "StringAndDictParser.h"
#include "../TemplateAnalizer/Analizer.h"

string	cpu(const string &dictFilePath, const string &textFilePath)
{
	//Инициализация map & string
	map <string, string>			mp;
	map<string, string>::iterator	it;
	string							resStrFile;
	Analizer						analize; // Obj from orig. testing func
	parser							Parser;

	string							strText;
	size_t							foundIndex;
	int								i = 0;
	int								*pi;

	pi = &i;
	strText = Parser.getStringFromFile();
	// strText = Parser.findKeyFromText(); // Получение строки с содержимым текстового файла
	mp = Parser.dctParser(); // Считали словарь в контейнер
	int strSize = strText.length();
	for (int i = 0; i < strSize; i++)
	{
		// cout << "i = " << i << endl;
		if (strText[i] != '$')
			resStrFile += strText[i];
		else
			resStrFile += analize.findValue(mp, strText, &i);
	}
	// cout << "res = " << resStrFile << endl;
	return (resStrFile);
}
