#pragma once

#include "com/mojang/minecraftpe/world/item/Item.h"

class ItemBackpackBase : public Item
{
public:
	ItemBackpackBase(const std::string&, short);
	virtual const std::string buildDescriptionName(const ItemInstance&) const;
};