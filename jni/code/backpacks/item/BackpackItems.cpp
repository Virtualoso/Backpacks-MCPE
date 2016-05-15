#include "BackpackItems.h"
#include "Backpack.h"
#include "BigBackpack.h"
#include "Leather.h"

Item* BackpackItems::backpack;
Item* BackpackItems::bigbackpack;
Item* BackpackItems::boundleather;

void BackpackItems::initItems()
{
	backpack = new Backpack("backpack", 1337);
	bigbackpack = new BigBackpack("bigbackpack", 1338);
	boundleather = new Leather("boundleather", 1339);
}

void BackpackItems::initCreativeItems()
{
	Item::addCreativeItem(backpack, 0);
	Item::addCreativeItem(bigbackpack, 0);
	Item::addCreativeItem(boundleather, 0);
}