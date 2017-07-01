#pragma once

#include "com/mojang/minecraft/item/Item.h"

class EnderBackpackItem : public Item {
public:

		//std::vector<Item*> items;
		static int enderon;
		
		EnderBackpackItem(std::string const&, short);
		
		virtual bool use(ItemInstance&, Player&) const;
		
		/*void pushBackpackScreen(ScreenChooser*);
		std::vector<Item*> getItems(CompoundTag*);
		void putItems(CompoundTag*);*/
};