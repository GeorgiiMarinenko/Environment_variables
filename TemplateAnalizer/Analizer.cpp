#include "Analizer.h"

Analizer::Analizer()
{}

Analizer::~Analizer()
{}
// Используемая функция для выделения из строки ключа $(...)
string Analizer::findValueFromText(const string& str, int* p_strIndex)
{
	string	resStr;
	bool	dollarSymb = false;
	bool	firstBracket = false;
	int		i = *p_strIndex;

	resStr.clear();
	str.c_str();

	while (str.length())
	{
		if (str[i] == '$')
			dollarSymb = true;
		else if ((dollarSymb) && (str[i] == '('))
			firstBracket = true;
		else if ((dollarSymb) && (firstBracket) && (str[i] != '(') && (str[i] != ')'))
			resStr.push_back(str[i]);
		if ((dollarSymb) && (firstBracket) && (str[i] == ')'))
		{
			dollarSymb = false;
			firstBracket = false;
			break;
		}
		i++;
	}
	*p_strIndex = i;
	return (resStr);
}

string Analizer::findValue(map<string, string> mp, string str, int* p_strIndex)
{
	map<string, string>::iterator	it;
	string							editedStr;

	editedStr = findValueFromText(str, p_strIndex);
	it = mp.find(editedStr);
	// cout << it->first << " : " << it->second << endl;
	return (it->second);
}

