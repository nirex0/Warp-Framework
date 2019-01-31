// © 2019 NIREX ALL RIGHTS RESERVED

#ifndef _W_GENERATOR_H_
#define _W_GENERATOR_H_

#include "WEntity.h"
#include "WRegistry.h"
#include "WGeneratorArgs.h"

template <typename T>
//-->DOC_CLASS
// Class that represents a python-like generator (Beta) (MIGHT BE REPLACED / DELETED)
class WGenerator : public WEntity
{
public:
	WGenerator(void)
	{
		m_yield = new WRegistry();
	}

	~WGenerator(void)
	{
		delete m_yield;
	}

	//-->DOC_FUNC
	// This method is the same as Yield in python generator
	void Generate(T in = {})
	{
		WGeneratorArgs<T>* args = new WGeneratorArgs<T>(m_iterationCount, in);
		m_yield->Run(this, args);
	}

private:
	int m_iterationCount;
	WRegistry* m_yield;
};

#endif // !_W_GENERATOR_H_