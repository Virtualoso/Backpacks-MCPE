#pragma once

#include "ItemBackpackBase.h"

#include "com/mojang/minecraftpe/client/renderer/texture/TextureUVCoordinateSet.h"

class ItemWorkbenchBackpack : public ItemBackpackBase
{
public:
	ItemWorkbenchBackpack();
	virtual const TextureUVCoordinateSet& getIcon(int, int, bool) const;
	
	void registerIcons();
	
private:
	TextureUVCoordinateSet icons[2];
};
