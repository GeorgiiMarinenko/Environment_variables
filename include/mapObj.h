#ifndef MAP_H
#define MAP_H
#include <map>
#include <string>
#include "dictParser.h"

class mapObj
{
private:

public:
	mapObj();
	~mapObj();
	map<string, string>				envVariablesMap;
	map <string, string>::iterator	it;
	map<string, string>				setMap();
};

#endif
