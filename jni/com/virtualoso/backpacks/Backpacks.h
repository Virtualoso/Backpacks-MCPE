#pragma once

#include "com/virtualoso/nativetools-api/Mod.h"

class Backpacks : public Mod
{
public:
	Backpacks() : Mod() {};
	virtual void initItems();
	virtual void initVanillaCreativeItems();
	virtual void initCustomCreativeItems();
};