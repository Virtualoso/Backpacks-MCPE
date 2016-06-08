#include "BigBackpack.h"

#include "com/virtualoso/nativetools-api/NativeToolsItems.h"

BigBackpack::BigBackpack(const std::string& name) : Item(name, NativeToolsItems::getNextItemId() - 0x100)
{
	setCategory(CreativeItemCategory::ITEMS);
	setIcon(name, 0);
	Item::mItems[itemId] = this;
}
