#include <iostream>
#include <map>
#include <string>
#include "../include/dictParser.h"
#include "../include/mapObj.h"
#include "../include/Analizer.h"
using namespace std;

int main()
{
	mapObj		obj;
	Analizer	analize;
	std::string	template_string = "this is template. $(value). Done";
	std::map<std::string, std::string>	m;

	m["value"] = "some text";
	cout << "Возвращенное значение ключа: " << analize.findValue(m, template_string) << endl;
	// obj.setMap();
	return (0);
}
