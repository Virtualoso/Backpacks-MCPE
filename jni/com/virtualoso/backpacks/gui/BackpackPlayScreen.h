#pragma once

#include "com/mojang/minecraftpe/client/screen/InGamePlayScreen.h"

class ImageWithBackground;

class BackpackPlayScreen : public InGamePlayScreen
{
public:
	std::shared_ptr<ImageWithBackground> backpackButton;
	
	BackpackPlayScreen(MinecraftGame&, ClientInstance&);
	
	virtual void init();
	virtual void setupPositions();
	virtual void render(ScreenContext&);
};