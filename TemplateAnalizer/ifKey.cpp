#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
using namespace std;

/*
/ == - 0
/ != - 1
/ <= - 2
/ >= - 3
/ < - 4
/ > - 5
*/
int signDetector(int strSize, int* p_strIndex, const string& str)
{
	int	sign = -1;
	int	curPos = *p_strIndex;

	while ((str[curPos] == ' ') && (curPos < strSize))
		curPos++;
	while (((str[curPos] >= '<') && (str[curPos] <= '>')) || (str[curPos] == '!'))
	{
		if (str[curPos] == '=' && str[curPos + 1] == '=')
		{
			sign = 0;
			curPos += 2;
		}
		else if (str[curPos] == '!' && str[curPos + 1] == '=')
		{
			sign = 1;
			curPos += 2;
		}
		else if (str[curPos] == '<' && str[curPos + 1] == '=')
		{
			sign = 2;
			curPos += 2;
		}
		else if (str[curPos] == '>' && str[curPos + 1] == '=')
		{
			sign = 3;
			curPos += 2;
		}
		else if (str[curPos] == '<')
		{
			sign = 4;
			curPos++;;
		}
		else if (str[curPos] == '>')
		{
			sign = 5;
			curPos++;;
		}
	}
	*p_strIndex = curPos;
	return (sign);
}
string findKeyValue(map<string, string> mp, const string& variable)
{
	map<string, string>::iterator	it;

	it = mp.find(variable);
	if (it == mp.end())
	{
		cout << "Значение переменной " << variable << " не найдено" << endl;
		return ("----------->Incorrect value");
	}
	cout << "varValue: " << it->second << endl;
	return (it->second);
}
string varFinder(const string& str, map<string, string> mp)
{
	string	res;
	string	variable;
	string	varValue;
	string	origValue;
	bool	isEqual = false;
	int		curPos = 0;
	int		*p_curPos = NULL;
	int		strSize = 0;
	int		sign = -1;
	// int		length = 0;
	// int		finish = 0;
	string::size_type start;

	strSize = str.length();
	start = str.find("if");
	if (start != string::npos)
	{
		curPos = (int)start;
		while (curPos < strSize)
		{
			curPos++;
			while (curPos < strSize)
			{
				curPos++;
				/*
				if [var == val]
				{
					...
				}
				else
				{
					...
				}
				*/
				while ((str[curPos - 1] != '[') && (curPos < strSize))
					curPos++;
				while ((str[curPos] == ' ') && (curPos < strSize))
					curPos++;
				while ((str[curPos] >= 'a') && (str[curPos] <= 'z'))
				{
					variable += str[curPos];
					curPos++;
				}
				varValue = findKeyValue(mp, variable); // Определение значения переменной
				p_curPos = &curPos;
				sign = signDetector(strSize, p_curPos, str); // Определение кода знака сравнения
				// cout << "-- " << str[*p_curPos] << endl;
				curPos = *p_curPos;
				while ((str[curPos] == ' ') && (curPos < strSize))
					curPos++;
				// Получение правой величины для сравнения из if []
				while (((str[curPos] >= ' ') && (str[curPos] <= '~') && (str[curPos] != ']'))
				&& (curPos < strSize))
				{
					origValue += str[curPos];
					curPos++;
				}
				// cout << "Orig value: " << origValue << endl;
				// Сравнение
				if (strcmp(varValue.c_str(), origValue.c_str()) == 0)
					isEqual = true;
				// cout << "compar: " << isEqual << endl;

				break;
			}
			break;
		}
	}
	return variable;
}

int ifKeyProccess()
{
	return (0);
}
