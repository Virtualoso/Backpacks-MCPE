#include "ItemWorkbenchBackpack.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"
#include "BackpackItems.h"

ItemWorkbenchBackpack::ItemWorkbenchBackpack() : ItemBackpackBase(BackpackItems::UNLOCALIZED_NAME_BACKPACK_WORKBENCH, NativeToolsItems::getNextItemId())
{
	registerIcons();
	Item::mItems[itemId] = this;
}

const TextureUVCoordinateSet& ItemWorkbenchBackpack::getIcon(int data, int i2, bool b1) const
{
	if(data == 17)
		return icons[0];
	if(data == 217)
		return icons[1];
	return icons[0];
}

void ItemWorkbenchBackpack::registerIcons()
{
	icons[0] = getTextureUVCoordinateSet("backpack_workbench", 0);
	icons[1] = getTextureUVCoordinateSet("backpack_workbench_big", 0);
}
