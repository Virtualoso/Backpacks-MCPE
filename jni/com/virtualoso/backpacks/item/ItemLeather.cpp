#include "ItemLeather.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"

ItemLeather::ItemLeather(const std::string& name) : Item(name, NativeToolsItems::getNextItemId() - 0x100)
{
	setMaxStackSize(64);
	setCategory(CreativeItemCategory::ITEMS);
	setIcon(name, 0);
	Item::mItems[itemId] = this;
}