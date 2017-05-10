#pragma once

#include "com/virtualoso/nativetools-api/Mod.h"

class MinecraftGame;

class Backpacks : public Mod
{
public:
	static MinecraftGame* clientInstance;

	Backpacks() : Mod() {};
	virtual void initItems();
	virtual void initVanillaCreativeItems();
	virtual void initCustomCreativeItems();
};