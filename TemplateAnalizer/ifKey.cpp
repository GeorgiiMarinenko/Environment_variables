#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string varFinder(const string& str)
{
	string	res;
	string	variable;
	int		i = 0;
	// bool	ifFound = false;
	int		strSize = 0;
	// int		length = 0;
	// int		finish = 0;
	string::size_type start;

	strSize = str.length();
	start = str.find("if");
	if (start != string::npos)
	{
		i = (int)start;
		while (i < strSize)
		{
			i++;
			while (i < strSize)
			{
				i++;
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
				while ((str[i - 1] != '[') && (i < strSize))
					i++;
				// cout << "!" << str[i];
				while ((str[i] == ' ') && (i < strSize))
					i++;
				while ((str[i] >= 'a') && (str[i] <= 'z'))
				{
					variable += str[i];
					i++;
				}
				if (str[i] == ']')
					break;
			}
		}
	}
	return variable;
}

/*
/ == - 0
/ != - 1
/ < - 2
/ > - 3
/ <= - 4
/ >= - 5
*/
int signDetector()
{
	int sign = -1;

	return (sign);
}

int keyValueAnalizer()
{
	return (0);
}

int ifKeyProccess()
{
	return (0);
}
