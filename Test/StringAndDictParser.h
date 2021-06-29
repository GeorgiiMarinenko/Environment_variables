#ifndef KEYDETECTOR_H
#define KEYDETECTOR_H
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;
#define ZERO 0
#define ONE 1

struct mapArgStruct
	{
		string	Key;
		string	Value;
	};

class parser
{
private:
	string	textPath;
	string	dictPath;
	bool	isValue;
public:
	parser();
	~parser();
	// string							findKeyFromText();
	string							getStringFromFile();
	int								keysCounterFromFile();
	map<string, string>				dctParser();
	string*							findKeyFromText();

	map<string, string>				envVariablesMap;
	map <string, string>::iterator	it;
};


#endif
