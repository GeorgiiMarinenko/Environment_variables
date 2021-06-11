#include "../include/dictParser.h"
#include "../include/mapObj.h"

dictParser::dictParser()
{
    dictPath = "/Users/georgijmarinenko/Desktop/Programming/Vimpel/Task1-Map/dictionary.txt";
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
	else
	{
		cout << ">File is reading..." << endl;
		while (1)
		{
			// dictMap.it = dictMap.envVariables.begin();
			symb = outFile.get();
			if (outFile.eof())
			{
				// cout << tmp.Key;
				// cout << tmp.Value;
				// dictMap.envVariables.insert(make_pair(tmp.Key, tmp.Value)); ///////////////////seting map
				dictMap.envVariablesMap[tmp.Key] = tmp.Value;
				// cout << "Key: " << dictMap.it->first << "Value: " << dictMap.it->second << endl;
				// for (dictMap.it = dictMap.envVariables.begin(); dictMap.it != dictMap.envVariables.end(); dictMap.it++)
				// {
				// 	cout << dictMap.it->first << " : " << dictMap.it->second << endl;
				// }
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
					// cout << "Key: " << tmp.Key << endl;
					// cout << "Value: " << tmp.Value << endl;
					dictMap.envVariablesMap[tmp.Key] = tmp.Value;
					// cout << "Map - value: " << dictMap.envVariablesMap[tmp.Key] << endl << endl;
					tmp.Value.clear();
					tmp.Key.clear();
					continue;
				}
				!isValue ? tmp.Key += symb : tmp.Value += symb;
			}
		}
		outFile.close();
		cout << ">File closed" <<  endl;
	}
	tmp.Key = "NULL";
	tmp.Value = "NULL";
	return (dictMap.envVariablesMap);
}
