#include <string>
#include <iostream>
#include <fstream>
using namespace std;

string includeKey(const string& str)
{
	int		i = 0;
	bool	includeFound = false;
	string	fileName = "\0";
	string::size_type start;
	int		finish = 0;
	int 	length = 0;
	int		strSize = 0;

	strSize = str.length();
	start = str.find("include");
	if (start != string::npos)
	{
		i = (int)start;
		while (i < strSize)
		{
			i++;
			if (!includeFound)
			{
				includeFound = true;
				while ((str[i-1] != '<') && (i < strSize))
					i++;
				start = i;
				while ((str[i] != '>') && (i < strSize))
					i++;
				finish = i;
				length = finish - start;
				fileName = str.substr(start, length);
			}
			else
				break;
		}
	}
	return (fileName);
}

string parseFile(const string& fileName)
{
	fstream	outFile(fileName);
	string	text;
	char	ch;

	if (!outFile.is_open())
	{
		cout << ">Reading error" << endl;
		return (0);
	}
	else
	{
		while (!outFile.eof())
		{
			outFile.get(ch);
			text += ch;
		}
		// cout << "\nFrom file: " << text << endl;
	}
	return (text);
}
