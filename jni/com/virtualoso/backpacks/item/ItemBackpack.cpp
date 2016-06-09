#include "ItemBackpack.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"

#include "BackpackItems.h"

ItemBackpack::ItemBackpack() : ItemBackpackBase(BackpackItems::UNLOCALIZED_NAME_BACKPACK, NativeToolsItems::getNextItemId())
{
	registerIcons();
	Item::mItems[itemId] = this;
}

const TextureUVCoordinateSet& ItemBackpack::getIcon(int data, int i2, bool b1) const
{
	int tier = data / 100;
	int meta = data % 100;
	if(tier > 2)
		return icons[51];
	return icons[tier * 17 + meta];
}

void ItemBackpack::registerIcons()
{
	std::string texName;
	for(int tier = 0; tier < 3; tier++)
	{
		// TODO remove when tier 1 added
		if(tier == 1) continue;
		for(int meta = 0; meta < 17; meta++)
		{
			texName = "backpack";
			texName += (meta == 0 ? "" : "_") + BackpackItems::BACKPACK_COLORS[meta];
			texName += (tier == 0 ? "" : "_") + BackpackItems::BACKPACK_TIERS[tier];
			icons[tier * 17 + meta] = getTextureUVCoordinateSet(texName, 0);
		}
	}
	icons[51] = getTextureUVCoordinateSet("backpack_ender", 0);
}
