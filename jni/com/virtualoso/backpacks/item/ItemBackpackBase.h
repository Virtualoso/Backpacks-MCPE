#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"

class ItemBackpackBase : public Item
{
public:
	ItemBackpackBase(const std::string&, short);
	virtual bool requiresInteract() const;
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
	virtual const std::string getInteractText() const;
	
	std::string getUnlocalizedName(const ItemInstance&) const;
};