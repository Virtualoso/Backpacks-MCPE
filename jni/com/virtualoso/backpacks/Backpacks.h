#pragma once

#include "com/virtualoso/nativetools-api/Mod.h"

class Backpacks : public Mod
{
public:
	ExampleMod() : Mod() {};
	virtual void initItems();
	virtual void initCustomCreativeItems();
};