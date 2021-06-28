#ifndef DICTPARSER_H
#define DICTPARSER_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

struct mapArgStruct
	{
		string	Key;
		string	Value;
	};

class dictParser
{
private:
	string	dictPath;
	string	textPath;
	bool	isValue;

public:
	dictParser();
	~dictParser();
	map<string, string>	dctParser();
};

#endif
