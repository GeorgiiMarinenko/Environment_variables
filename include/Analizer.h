#ifndef ANALIZER_H
#define ANALIZER_H
#include <string>
#include <iostream>
#include <fstream>
#include <map>
using namespace std;

class Analizer
{
private:
	// char outPath;
public:
	Analizer();
	~Analizer();
	int strMpAnalizer(map<string, string> mp, string *str);
	int recordInfo(FILE * file, string key, string value);
};

#endif
