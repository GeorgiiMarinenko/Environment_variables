#include <iostream>
#include <map>
#include <string>

#include "Analizer.h"
using namespace std;

int main()
{
	Analizer	analize;
	std::string	template_string = "this is template. $(value). Done";
	std::map<std::string, std::string>	m;
	int i = 0;
	int *pi;

	pi = &i;
	m["value"] = "some text";
	cout << "Возвращенное значение ключа: " << analize.findValue(m, template_string, pi) << endl;
	return (0);
}
