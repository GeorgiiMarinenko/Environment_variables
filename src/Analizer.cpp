#include "../include/Analizer.h"

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
	if(file)
	{
		for (int i = 0; str[i] != "NULL"; i++)
		{
			it = mp.find(str[i]);
			if (it == mp.end())
				continue;
			else
			{
				Analizer::recordInfo(file, it->first, it->second);
				cout << it->first << " : " << it->second << endl;
			}
		}
		return (0);
	}
	else
	{
		cout << "Recording error" << endl;
		return (-1);
	}
}

int Analizer::recordInfo(FILE *file, string key, string value)
{
	fprintf(file,key.c_str(), "%s");
	fprintf(file, " : ");
	fprintf(file, (char *)&value, "%s");
	fprintf(file, "\n");
	return (0);
}
