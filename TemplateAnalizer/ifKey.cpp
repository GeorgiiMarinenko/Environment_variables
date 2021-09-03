#include <string>
#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>
using namespace std;

int	signSkipper()
{
	int	curPos = 0;

	return (curPos);
}

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
	// cout << "varValue: " << it->second << endl;
	return (it->second);
}

string ifCase(int* p_strIndex, const string& str)
{
	int		curPos = *p_strIndex;
	string	ifCase;
	bool	wasAlpha = false;
	while (str[curPos] != '{')
		curPos++;
	while (str[curPos + 1] != '}')
	{
		curPos++;
		if ((str[curPos] == '\n') && !wasAlpha)
		{
			wasAlpha = true;
			continue;
		}
		if ((str[curPos] == ' ') || (str[curPos] == '\t'))
			continue;
		ifCase += str[curPos];
	}
	cout << "ifKeyProc " << ifCase <<  endl;
	return (ifCase);
}

string elseCase(int* p_strIndex, const string& str)
{
	string	elseCase;
	bool	wasAlpha = false;
	string::size_type start;
	int		curPos = 0;
	(void)p_strIndex;

	start = str.find("else");
	curPos = (int)start;
	while (str[curPos] != '{')
		curPos++;
	while (str[curPos + 1] != '}')
	{
		curPos++;
		if ((str[curPos] == '\n') && !wasAlpha)
		{
			wasAlpha = true;
			continue;
		}
		if ((str[curPos] == ' ') || (str[curPos] == '\t'))
			continue;
		elseCase += str[curPos];
	}
	// curPos += 3; // позиция elsE
	cout << "else: " << str[curPos] << endl;
	return (elseCase);
}

string solution(bool isEqual, int* p_strIndex, const string& str)
{
	string	res;
	if (isEqual)
		res = ifCase(p_strIndex, str);
	else if ((str.find("else") != string::npos) && (!isEqual))
		res = elseCase(p_strIndex, str);
	else
		res = '\r';
	return (res);
}
string varFinder(const string& str, map<string, string> mp)
{
	string				res;
	string				variable;
	string				varValue;
	string				origValue;
	bool				isEqual = false;
	int					curPos = 0;
	int					*p_curPos = NULL;
	int					strSize = 0;
	int					sign = -1;
	string::size_type	start;

	strSize = str.length();
	start = str.find("if");
	if (start != string::npos)
	{
		curPos = (int)start;
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
		*p_curPos = curPos;
		// Сравнение
		if (strcmp(varValue.c_str(), origValue.c_str()) == 0)
			isEqual = true;
	}
	return (solution(isEqual, p_curPos, str));
}
