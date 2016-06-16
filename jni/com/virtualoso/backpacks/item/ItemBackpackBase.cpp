#include "ItemBackpackBase.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/locale/I18n.h"

#include "BackpackItems.h"
#include "../saves/BackpackSave.h"

ItemBackpackBase::ItemBackpackBase(const std::string& name, short id) : Item(name, id - 0x100)
{
	setMaxStackSize(1);
	setStackedByData(true);
	setCategory(CreativeItemCategory::ITEMS);
}

bool ItemBackpackBase::requiresInteract() const
{
	return true;
}

bool ItemBackpackBase::use(ItemInstance& item, Player& player)
{
	return Item::use(item, player); //TODO
}
	
const std::string ItemBackpackBase::buildDescriptionName(const ItemInstance& item) const
{
	return I18n::get(getUnlocalizedName(item) + ".name");
}

void ItemBackpackBase::onCraftedBy(ItemInstance& item, Level& level, Player& player)
{
	new BackpackSave(&item, true);
}

const std::string ItemBackpackBase::getInteractText() const
{
	return I18n::get("action.interact.opencontainer");
}

std::string ItemBackpackBase::getUnlocalizedName(const ItemInstance& item) const
{
	std::string nameId = name;
	
	int damage = item.aux;
	int tier = damage / 100 < 3 ? damage / 100 : 0;
	int meta = damage % 100;
	nameId += (tier == 0 ? "" : ".") + BackpackItems::BACKPACK_TIERS[tier];
	if(meta > 0 && meta < 17) // add color
		nameId += (tier == 0 ? "." : "_") + BackpackItems::BACKPACK_COLORS[damage % 100];
	if(meta == 99) // ender backpack
		nameId += (tier == 0 ? "." : "_") + BackpackItems::BACKPACK_COLORS[17];
	return nameId;
}