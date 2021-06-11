#ifndef MAP_H
#define MAP_H
#include <map>
#include <string>
#include "dictParser.h"

class mapObj
{
private:

public:
	map<string, string> envVariablesMap;
	map <string, string>::iterator it;
	mapObj();
	~mapObj();
	map<string, string>	setMap();
};

#endif
