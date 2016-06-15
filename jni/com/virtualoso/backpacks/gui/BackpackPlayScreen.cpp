#include "BackpackPlayScreen.h"

#include "com/mojang/minecraftpe/client/renderer/texture/TextureGroup.h"

BackpackPlayScreen::BackpackPlayScreen(MinecraftClient& client) : InGamePlayScreen(client)
{
	backpackButton = NULL;
}

void BackpackPlayScreen::init()
{
	if(!backpackButton)
	{
	backpackButton = std::make_shared<ImageWithBackground>(2);
	backpackButton->init(mcClient->getTextures(), 28, 28, {49, 43, 14, 14}, {49, 43, 14, 14}, 2, 2, "gui/spritesheet.png");
	backpackButton->setImageDef({mcClient->getTextures()->getTexture("gui/spritesheet.png", TextureLocation::Default), 0, 1, 18.0F, 18.0F, {60, 0, 18, 18}, true}, true);
	}
}

void BackpackPlayScreen::setupPositions()
{
	backpackButton->xPosition = 0;
	backpackButton->yPosition = 0;
	backpackButton->setSize(5, 5);
}