#include "../include/mapObj.h"
#include "../include/keyDetector.h"
#include "../include/Analizer.h"

mapObj::mapObj()
{}

mapObj::~mapObj()
{}

map<string, string> mapObj::setMap()
{
	mapObj				mapObject;
	string				*str;
	Analizer			Analize;
	dictParser			parser;
	mapArgStruct		currentArg;
	map<string,string> mp;

	mapObject.envVariablesMap = parser.dctParser();
	//печать содержимого в map из файла dictionary.txt
	// cout << "Key: " << currentArg.Key << "\nValue: " << currentArg.Value << endl;
	keyDetector obj1;
	cout << "\nkeys from text.txt:" << endl << endl;
	str = obj1.findKeyFromText();
	Analize.strMpAnalizer(mapObject.envVariablesMap, str);
	cout << "END" << endl;
	return (mapObject.envVariablesMap);
}
