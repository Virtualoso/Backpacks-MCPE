#include "BackpackUtil.h"

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/world/level/Level.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/Minecraft.h"
#include "com/mojang/minecraftpe/client/UUID.h"
#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"

#include "NBTUtil.h"
#include "NBTItemInstanceUtil.h"
#include "../misc/Constants.h"
#include "../item/BackpackItems.h"
#include "../Backpacks.h"

bool BackpackUtil::isEnderBackpack(ItemInstance* itemStack)
{
	return itemStack != NULL && itemStack->aux == BackpackItems::ENDERBACKPACK;
}

bool BackpackUtil::isServerSide()
{
	return !Backpacks::clientInstance->getServer()->isOnlineClient();
}

bool BackpackUtil::isServerSide(Level* world)
{
	return !world->isClientSide();
}

std::string BackpackUtil::getUUID(CompoundTag* nbtTagCompound)
{
	if(NBTUtil::hasTag(nbtTagCompound, Constants::NBT::UID))
		return NBTUtil::getString(nbtTagCompound, Constants::NBT::UID);

	return NULL;
}

char BackpackUtil::getType(ItemInstance* backpack)
{
	if(backpack->item == BackpackItems::backpack)
	{
		return 1;
	}
	else if(backpack->item == BackpackItems::workbenchBackpack)
	{
		return 2;
	}
	
	return 0;
}

void BackpackUtil::pickupItem(Player* entityPlayer, ItemInstance* itemStack)
{
	/*PlayerSave playerSave = new PlayerSave(entityPlayer);
	ItemInstance* backpack = playerSave.getPersonalBackpack();
	if(backpack != NULL) {
		InventoryPickup inventoryPickup = new InventoryPickup();
		inventoryPickup.setInventoryContent(backpack);
			ContainerPickup container = new ContainerPickup(ItemBackpackBase.getInventory(backpack, entityPlayer), new BackpackSave(backpack));
		bool hasPickedUp = false;
		for(int i = 0; i < inventoryPickup.getSizeInventory(); i++) {
			ItemInstance* pickupItemInstance* = inventoryPickup.getStackInSlot(i);
			if(areStacksEqual(pickupItemStack, itemStack, true)) {
				hasPickedUp = container.pickupItem(itemStack) || hasPickedUp;
			}
		}
		
		if(hasPickedUp) {
			container.onContainerClosed(entityPlayer);
		}
	}*/
}

bool BackpackUtil::canStack(ItemInstance* stack1, ItemInstance* stack2)
{
	return 	(stack1 == NULL)
			|| (stack2 == NULL)
			|| ((stack1->item == stack2->item) && (!stack1->hasUserData() || stack1->aux == stack2->aux) && (stack1->matches(stack2)) && (stack1->isStackable()));
}

bool BackpackUtil::areStacksEqual(ItemInstance* firstStack, ItemInstance* secondStack)
{
	return areStacksEqual(firstStack, secondStack, false);
}

bool BackpackUtil::areStacksEqual(ItemInstance* firstStack, ItemInstance* secondStack, bool useOreDictionary)
{
	if(firstStack == NULL || secondStack == NULL)
		return false;

	// are items and damage the same
	if(firstStack->sameItemAndAux(secondStack))
		return true;

	// if both have no subtype only check the item
	if(!firstStack->hasUserData() && !secondStack->hasUserData()) 
	{
		if(firstStack->item == secondStack->item)
			return true;
	}
	
	if(useOreDictionary && areStacksEqualByOD(firstStack, secondStack))
		return true;

	return false;
}

bool BackpackUtil::areStacksEqualByOD(ItemInstance* firstStack, ItemInstance* secondStack)
{
	if(firstStack == NULL || secondStack == NULL)
		return false;

	/*int[] oreIdFirst = OreDictionary.getOreIDs(firstStack);
	int[] oreIdSecond = OreDictionary.getOreIDs(secondStack);
	
	for(int a : oreIdFirst) {
		for(int b : oreIdSecond) {
			if(a == b) {
				return true;
			}
		}
	}*/
	
	return false;
}

bool BackpackUtil::UUIDEquals(ItemInstance* suspicious, ItemInstance* original)
{
	if(suspicious != NULL && original != NULL)
	{
		if(NBTItemInstanceUtil::hasTag(suspicious, Constants::NBT::UID) && NBTItemInstanceUtil::hasTag(original, Constants::NBT::UID))
		{
			std::string UIDsuspicious = NBTItemInstanceUtil::getString(suspicious, Constants::NBT::UID);
			std::string UIDoriginal = NBTItemInstanceUtil::getString(original, Constants::NBT::UID);
			return UUIDEquals(UIDsuspicious, UIDoriginal);
		}
	}
	return false;
}

bool BackpackUtil::UUIDEquals(ItemInstance* suspicious, const std::string& original)
{
	if(suspicious != NULL && !original.empty())
	{
		if(NBTItemInstanceUtil::hasTag(suspicious, Constants::NBT::UID))
		{
			std::string UIDsuspicious = NBTItemInstanceUtil::getString(suspicious, Constants::NBT::UID);
			return UUIDEquals(UIDsuspicious, original);
		}
	}
	return false;
}

bool BackpackUtil::UUIDEquals(const std::string& suspicious, const std::string& original)
{
	if(!suspicious.empty() && !original.empty())
	{
		mce::UUID* UIDsuspicious = mce::UUID::fromString(suspicious);
		mce::UUID* UIDoriginal = mce::UUID::fromString(original);
		return UIDsuspicious == UIDoriginal;
	}
	return false;
}
