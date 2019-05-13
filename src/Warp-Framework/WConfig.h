// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_CONFIG_H_
#define _W_CONFIG_H_

#include "WEntity.h"
#include <map>
#include <vector>
#include <string>

class WConfig : public WEntity
{
public:
	WConfig(void);
	~WConfig(void);

	std::map<std::string, std::string> GetConfig(void);

private:
	std::map<std::string, std::string>* configMap;
};

#endif // _W_CONFIG_H_