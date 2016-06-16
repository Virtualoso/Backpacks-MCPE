#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"

class ItemBackpackBase : public Item
{
public:
	ItemBackpackBase(const std::string&, short);
	virtual bool requiresInteract() const;
	virtual bool use(ItemInstance&, Player&);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual void onCraftedBy(ItemInstance&, Level&, Player&);
	virtual const std::string getInteractText() const;
	
	std::string getUnlocalizedName(const ItemInstance&) const;
};