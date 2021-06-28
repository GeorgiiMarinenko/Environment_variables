#include "../include/mapObj.h"
#include "../include/keyDetector.h"
#include "../include/Analizer.h"

mapObj::mapObj()
{}

mapObj::~mapObj()
{}

map<string, string> mapObj::setMap()
{
	Analizer			Analize;
	keyDetector			obj1;
	mapObj				mapObject;
	dictParser			parser;
	string				*str;
	mapArgStruct		currentArg;
	map<string,string>	mp;

	mapObject.envVariablesMap = parser.dctParser();
	cout << "\nkeys from text.txt:" << endl << endl;
	str = obj1.findKeyFromText();
	Analize.strMpAnalizer(mapObject.envVariablesMap, str);
	cout << "END" << endl;
	return (mapObject.envVariablesMap);
}
