#include "Analizer.h"
#include "includeKey.cpp"
#include "ifKey.cpp"

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

	int length = str.length();
	while (i < length) //
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

//Подача строки из key на обработку
string Analizer::findValue(map<string, string> mp, string str, int* p_strIndex)
{
	map<string, string>::iterator	it;
	string							editedStr;

	editedStr = findValueFromText(str, p_strIndex); //Получение содержимого в $(...)
	//Обработка содержимого
	it = mp.find(editedStr);
	processString(editedStr, mp);
	// cout << it->first << " : " << it->second << endl;
	return (it->second);
}

void Analizer::processString(const string& str, map<string, string> mp)
{
	string::size_type include_sign;
	string::size_type if_sign;
	string testStr;
	if_sign = str.find("if");
	include_sign = str.find("include");
	if ((include_sign != string::npos) && (if_sign == string::npos))
		parseFile(includeKey(str));
	else if ((include_sign == string::npos) && (if_sign != string::npos))
		testStr = varFinder(str, mp);
}
