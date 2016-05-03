#include "BackpackItems.h"
#include "Backpack.h"

Item* BackpackItems::backpack;

void BackpackItems::initItems()
{
	backpack = new Backpack("backpack", 1337);
}

void BackpackItems::initCreativeItems()
{
	Item::addCreativeItem(backpack, 0)
}