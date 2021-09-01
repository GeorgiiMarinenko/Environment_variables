#include <string>
#include <iostream>
#include <fstream>
#include <map>
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
	return (sign);
}
string findValue()
{
	string value;

	return (value);
}
string varFinder(const string& str, map<string, string> mp)
{
	string	res;
	string	variable;
	string	value;
	int		curPos = 0;
	int		*p_curPos = NULL;
	int		strSize = 0;
	int		sign = -1;
	(void)mp;
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
				p_curPos = &curPos;
				sign = signDetector(strSize, p_curPos, str);
				cout << "sign: " << sign << endl;
				break;
			}
		}
	}
	return variable;
}

int keyValueAnalizer()
{
	return (0);
}

int ifKeyProccess()
{
	return (0);
}
