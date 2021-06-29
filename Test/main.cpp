#include <iostream>
#include <map>
#include <string>
#include "StringAndDictParser.h"
#include "cpu.cpp"
using namespace std;

int main(int argc, char* argv[])
{
	/// MODE 1
	// if (argc != 3)
	// {
	// 	cout << "Put down the right number of arguments:\n1. 'dictionaryFile'.txt\n2. 'textFile.txt\n";
	// 	return (-1);
	// }
	// string dictFilePath =  string(argv[1]);
	// string textFilePath =  string(argv[2]);

	/// MODE 2
	int		mode = 1;
	char	zero[2] = {"0"};
	char	one[2] = {"1"};
	if (argc != 2)
		return (-1);
	else if ( argv[1] == zero)
		mode = 0;
	else if (argv[1] == one)
		mode = 1;

	string	dictFilePath1 = "dict1.txt";
	string	textFilePath1 =  "text1.txt";
	string	res1;
	string	orig_res1 = "Hello! My name is georgijmarinenko.\nMy SHELL is located on /bin/zsh - this is the exact path!\nMy computer language: ru_RU.UTF-8\nHOME dir: /Users/georgijmarinenko\nBe like my color, I mean - truecolor\n\0";

	res1 = cpu(dictFilePath1, textFilePath1);
	if (mode == 1)
		cout << "\nreference:\n" << orig_res1 << "\n\nfunction result:\n" << res1 << endl;
	if (res1 == orig_res1)
		cout << "Test 1: OK\n\n";
	else
		cout << "Test 1: FAILED\n\n";

	string	dictFilePath2 = "dict2.txt";
	string	textFilePath2 =  "text2.txt";
	string	res2 = "0";
	string	orig_res2;
	res2 = cpu(dictFilePath2, textFilePath2);
	if (mode == 1)
		cout << "\nreference:\n" << orig_res2 << "\n\nfunction result:\n" << res2 << endl;
	if (res2 == orig_res2)
		cout << "Test 2: OK\n\n";
	else
		cout << "Test 2: FAILED\n\n";

	string dictFilePath3 = "dict3.txt";
	string textFilePath3 =  "text3.txt";
	string	res3 = "0";
	string	orig_res3;
	res3 = cpu(dictFilePath3, textFilePath3);
	if (mode == 1)
		cout << "\nreference:\n" << orig_res3 << "\n\nfunction result:\n" << res3 << endl;
	if (res3 == orig_res3)
		cout << "Test 3: OK\n\n";
	else
		cout << "Test 3: FAILED\n\n";
	return (0);
}
