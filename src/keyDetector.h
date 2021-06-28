#ifndef KEYDETECTOR_H
#define KEYDETECTOR_H
#include <string>
#include <cstring>
#include <iostream>
#include <map>
#include <fstream>
using namespace std;

class keyDetector
{
private:
	string	textPath;
public:
	keyDetector();
	~keyDetector();
	string	*findKeyFromText();
	string	findValueFromText(string str);
	int		keysCounterFromFile();
};


#endif
