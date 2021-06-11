#include "../include/mapObj.h"
#include "../include/keyDetector.h"

mapObj::mapObj()
{}

mapObj::~mapObj()
{}

map<string, string> mapObj::setMap()
{
	mapObj				mapObject;
	dictParser			parser;
	mapArgStruct		currentArg;

	mapObject.envVariablesMap = parser.dctParser();
	//печать содержимого в map из файла dictionary.txt
	for (mapObject.it = mapObject.envVariablesMap.begin(); mapObject.it != mapObject.envVariablesMap.end(); mapObject.it++)
	{
		cout << mapObject.it->first << " : " << mapObject.it->second << endl;
	}
	// cout << "Key: " << currentArg.Key << "\nValue: " << currentArg.Value << endl;
	keyDetector obj1;
	cout << "\nkeys from text.txt:" << endl << endl;
	obj1.findKeyFromText();
	return (mapObject.envVariablesMap);
}
