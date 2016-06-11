#pragma once

#include "com/virtualoso/nativetools-api/Mod.h"

class MinecraftClient;

class Backpacks : public Mod
{
public:
	static MinecraftClient* clientInstance;

	Backpacks() : Mod() {};
	virtual void initItems();
	virtual void initVanillaCreativeItems();
	virtual void initCustomCreativeItems();
};