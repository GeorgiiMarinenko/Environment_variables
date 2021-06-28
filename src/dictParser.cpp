#include "../include/dictParser.h"
#include "../include/mapObj.h"

dictParser::dictParser()
{
    dictPath = "/Users/georgijmarinenko/Desktop/Git/Environment_variables/dictionary.txt";
    isValue = false;
}

dictParser::~dictParser()
{}

map<string, string> dictParser::dctParser()
{
	char			symb;
	fstream			outFile(dictPath);
	mapArgStruct	tmp;
	mapObj			dictMap;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (dictMap.envVariablesMap);
	}
	cout << ">File is reading..." << endl;
	while (1) //убрать бесконечный цикл
	{
		symb = outFile.get();
		if (outFile.eof())
		{
			dictMap.envVariablesMap[tmp.Key] = tmp.Value;
			tmp.Value.clear();
			tmp.Key.clear();
			cout << "\n>End of file" << endl;
			break;
		}
		else
		{
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
	}
	outFile.close();
	cout << ">File closed" <<  endl;
	tmp.Key = "NULL"; //изменить на 0
	tmp.Value = "NULL";
	return (dictMap.envVariablesMap);
}
