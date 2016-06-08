#include "Backpack.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"

Backpack::Backpack(const std::string& name) : Item(name, NativeToolsItems::getNextItemId() - 0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon(name, 0);
	Item::mItems[itemId] = this;
}
