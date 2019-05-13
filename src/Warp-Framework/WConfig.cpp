// © 2019 NIREX ALL RIGHTS RESERVED

#include "WConfig.h"
#include "WFile.h"
#include "WString.h"

WConfig::WConfig(void)
{
	WFile* wf = new WFile();
	std::vector<std::string> configVector = wf->ReadAllLines("config.cfg");
	delete wf;

	configMap = new std::map<std::string, std::string>();

	for (auto& configLine : configVector)
	{
		// Trim
		configLine = WString::FullTrim(configLine);

		// Check if line is comment
		if (configLine[0] != ';' && WString::Contains(configLine, ":") != -1)
		{
			std::vector<std::string> splitted = WString::Split(configLine, ":");
			
			splitted[0] = WString::ToLower(splitted[0]);
			splitted[1] = WString::ToLower(splitted[1]);

			// Check to see if key exists
			if (configMap->find(WString::FullTrim(splitted[0])) == configMap->end()) {
				configMap->emplace(WString::FullTrim(splitted[0]), WString::FullTrim(splitted[1]));
			}
			else {
				configMap->erase(WString::FullTrim(splitted[0]));
				configMap->emplace(WString::FullTrim(splitted[0]), WString::FullTrim(splitted[1]));
			}
		}
	}
}

WConfig::~WConfig(void)
{
	delete configMap;
}

std::map<std::string, std::string> WConfig::GetConfig(void)
{
	return *configMap;
}
