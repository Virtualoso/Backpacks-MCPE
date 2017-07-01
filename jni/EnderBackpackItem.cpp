#include "EnderBackpackItem.h"

#include "com/mojang/minecraft/player/LocalPlayer.h"
#include "com/mojang/minecraft/client/ClientInstance.h"
#include "com/mojang/minecraft/client/ScreenChooser.h"

EnderBackpackItem::EnderBackpackItem(const std::string& name, short id) : Item(name, id - 0x100) {
	Item::mItems[id] = this;
	setIcon("backpack_ender", 0);
}

bool EnderBackpackItem::use(ItemInstance& ii, Player& p) const {
	enderon = 1;
	if(p.isLocalPlayer())
		((LocalPlayer&) p).getClientInstance()->getScreenChooser()->pushChestScreen(p, p.getBlockTarget());
}

/*void EnderBackpackItem::pushBackpackScreen(Screen* s, ClientInstance* ci) {
	self->mcClient->getScreenChooser()->_pushScreen(std::make_shared<EnderBackpackScreen>(*(s->mcClient), ci), false);
}

std::vector<Item*> EnderBackpackItem::getItems(CompoundTag* ct) {
	
}

void EnderBackpackItem::putItems(CompoundTag* ct) {
	
}*/