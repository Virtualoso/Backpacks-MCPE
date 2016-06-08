#include "Leather.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"

Leather::Leather(const std::string& name) : Item(name, NativeToolsItems::getNextItemId() - 0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon(name, 0);
	Item::mItems[itemId] = this;
}
