#pragma once

#include "com/mojang/minecraftpe/client/gui/screen/InGamePlayScreen.h"

class ImageWithBackground;

class BackpackPlayScreen : public InGamePlayScreen
{
public:
	std::shared_ptr<ImageWithBackground> backpackButton;
	
	BackpackPlayScreen(MinecraftClient&);
	
	virtual void init();
	virtual void setupPositions();
};