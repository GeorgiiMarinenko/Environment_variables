#include <iostream>
#include <map>
#include <string>
#include "../include/dictParser.h"
#include "../include/mapObj.h"
using namespace std;

int main()
{
	mapObj obj;
	std::string template_string="this is template. $(value). Done";
	std::map<std::string, std::string> m;
	m["value"] = "some text";
	std::string result = obj.parse(template_string, m);

	std::cout<<result<<std::endl;
	//obj.setMap();
	return (0);
}
