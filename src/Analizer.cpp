#include "../include/Analizer.h"
#include "../include/keyDetector.h"

Analizer::Analizer()
{
	// outPath = "/Users/georgijmarinenko/Desktop/Git/Environment_variables/Result.txt";
}

Analizer::~Analizer()
{}

int Analizer::strMpAnalizer(map<string, string> mp, string *str)
{
	FILE *file = fopen("/Users/georgijmarinenko/Desktop/Git/Environment_variables/Result.txt", "w");
	map<string, string>::iterator it;

	cout << "Analizing.. " << endl;
	if (!file)
	{
		cout << "Recording error" << endl;
		return (-1);
	}
	for (int i = 0; str[i] !=  "NULL"; i++)
	{
		it = mp.find(str[i]);
		if (it == mp.end())
			continue; //break?
		else
		{
			Analizer::recordInfo(file, it->first, it->second);
			cout << it->first << " : " << it->second << endl;
		}
	}
	return (0);
}

int Analizer::recordInfo(FILE *file, const string& key, string value)
{
	fprintf(file,key.c_str(), "%s");
	fprintf(file, " : ");
	fprintf(file, value.c_str(), "%s");
	fprintf(file, "\n");
	return (0);
}

string Analizer::findValue(map<string, string> mp, string str)
{
	map<string, string>::iterator	it;
	keyDetector						key;
	string							editedStr;

	editedStr = key.findValueFromText(str);
	it = mp.find(editedStr);
	cout << it->first << " : " << it->second << endl;
	return (it->second);
}
