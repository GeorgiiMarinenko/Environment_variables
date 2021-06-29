#include <iostream>
#include <map>
#include <string>
#include "StringAndDictParser.h"
#include "cpu.cpp"
using namespace std;

int main(int argc, char* argv[])
{
	//Инициализация map & string
	//
	string dictFilePath =  string(argv[1]);
	string textFilePath =  string(argv[2]);
	// cout << dictFilePath << '\n' << textFilePath << endl;
	cpu(dictFilePath, textFilePath);
	return (0);
}
