#include "StringAndDictParser.h"

parser::parser()
{
	isValue = false;
}

parser::~parser()
{}

int		parser::keysCounterFromFile()
{
	fstream	outFile(textPath);
	char	symb;
	bool	dollarSymb = false;
	bool	firstBracket = false;
	bool	insideKey = false; //внутри самой переменной
	bool	firstEntry = true;
	int		keyCounter = 0;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (0);
	}
	else
	{
		while (!outFile.eof())
		{
			symb = outFile.get();
			if (symb == '$')
				dollarSymb = true;
			else if ((dollarSymb) && (symb == '('))
				firstBracket = true;
			else if ((dollarSymb) && (firstBracket) && symb != ')')
				insideKey = true;
			else if ((dollarSymb) && (firstBracket) && (insideKey) && (firstEntry))
				firstEntry = false;
			if ((dollarSymb) && (firstBracket) && (symb == ')'))
			{
				firstEntry = true;
				dollarSymb = false;
				firstBracket = false;
				insideKey = false;
				keyCounter++;
			}
		}
	}
	keyCounter++; //Для дополнительной строки окончания массива
	cout << "Counter: " << keyCounter <<  endl;
	return (keyCounter);
}

string	*parser::findKeyFromText()
{
	string	*dictKeyStr = new string[parser::keysCounterFromFile()];
	int		keyCounter = 0;
	fstream	outFile(textPath);
	char	symb;
	bool	dollarSymb = false;
	bool	firstBracket = false;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (0);
	}
	// cout << ">Searching keys..." << endl;
	while (!outFile.eof())
	{
		symb = outFile.get();
		if (symb == '$')
			dollarSymb = true;
		else if ((dollarSymb) && (symb == '('))
			firstBracket = true;
		else if ((dollarSymb) && (firstBracket) && (symb != '(') && (symb != ')'))
			dictKeyStr[keyCounter] += symb;
		if ((dollarSymb) && (firstBracket) && (symb == ')'))
		{
			dollarSymb = false;
			firstBracket = false;
			keyCounter++;
		}
	}
	outFile.close();
	// cout << ">File closed" << endl;
	dictKeyStr[keyCounter] = "NULL";
	return (dictKeyStr);
}

string parser::getStringFromFile(const string &textFilePath)
{
	fstream	outFile(textFilePath);
	string	fileStr;
	char	buffer[4096];

	while (outFile.read(buffer, sizeof(buffer)))
		fileStr.append(buffer, sizeof(buffer));
	fileStr.append(buffer, outFile.gcount());
	return (fileStr);
}

map<string, string> parser::dctParser(const string &dictFilePath)
{
	char			symb;
	fstream			outFile(dictFilePath);
	mapArgStruct	tmp;
	parser		dictMap;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (dictMap.envVariablesMap);
	}
	// cout << ">File is reading..." << endl;
	while (!outFile.eof()) // while (1)
	{
		symb = outFile.get();
		// if (outFile.eof())
		// {
		// 	// dictMap.envVariablesMap[tmp.Key] = tmp.Value; активен только в том случае, если файл ключей и значений не генерирует последней строкой пустую строку
		// 	// dictMap.envVariablesMap[tmp.Key] = tmp.Value;
		// 	tmp.Value.clear();
		// 	tmp.Key.clear();
		// 	cout << ">End of file" << endl;
		// 	break;
		// }

		if (symb == '=')
		{
			isValue = true;
			continue;
		}
		else if (symb == '\n')
		{
			isValue = false;
			dictMap.envVariablesMap[tmp.Key] = tmp.Value;
			tmp.Value.clear();
			tmp.Key.clear();
			continue;
		}
		!isValue ? tmp.Key += symb : tmp.Value += symb;
	}
	outFile.close();
	// cout << ">File closed" <<  endl;
	return (dictMap.envVariablesMap);
}
