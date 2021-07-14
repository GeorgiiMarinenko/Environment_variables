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
	string outPath;
public:
	Analizer();
	~Analizer();
	// Сопоставление найденного ключа с содержимым map
	string	findValue(map<string, string> mp, string str, int* p_strIndex);
	// Поиск ключа в строке
	string	findValueFromText(const string& str, int* p_strIndex);
	void	processString(const string& str);
};

#endif
