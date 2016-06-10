#include "BackpackSave.h"

#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"
#include "com/mojang/minecraftpe/client/nbt/ListTag.h"
#include "com/mojang/minecraftpe/world/item/ItemInstance.h"

#include "../util/NBTUtil.h"
#include "../util/NBTItemInstanceUtil.h"
#include "../misc/Constants.h"
#include "../item/BackpackItems.h"


BackpackSave::BackpackSave(const std::string& uuid) : AbstractSave(uuid) { }

BackpackSave::BackpackSave(CompoundTag* data) : AbstractSave(data)
{
	if(NBTUtil::hasTag(nbtTagCompound, Constants::NBT::UID))
		UID = NBTUtil::getString(nbtTagCompound, Constants::NBT::UID);
}

BackpackSave::BackpackSave(ItemInstance* backpack) : BackpackSave(backpack, false) { }

BackpackSave::BackpackSave(ItemInstance* backpack, bool force) : AbstractSave(new CompoundTag())
{
	if(!NBTItemInstanceUtil::hasTag(backpack, Constants::NBT::UID))
	{
		initialize(backpack);
	}
	else
	{
		if(backpack->item == BackpackItems::backpack || backpack->item == BackpackItems::workbenchBackpack)
		{
			load(NBTItemInstanceUtil::getString(backpack, Constants::NBT::UID));
			if(force)
				initialize(backpack);
		}
	}
}

bool BackpackSave::isUninitialized()
{
	return nbtTagCompound->isEmpty();
}

void BackpackSave::initialize(ItemInstance* backpack)
{
	/*if(backpack.getItem() instanceof ItemBackpackBase && BackpackUtil.isServerSide()) {
		NBTItemInstance*Util.setstd::string(backpack, Constants::NBT::NAME, backpack.getItem().getUnlocalizedName(backpack) + ".name");
		if(!NBTItemInstance*Util.hasTag(backpack, Constants::NBT::UID)) {
			UID = UUID.randomUUID().tostd::string();
			NBTItemInstance*Util.setstd::string(backpack, Constants::NBT::UID, UID);
		}

		int size = 0;
		int damage = backpack.getItemDamage();
		int tier = damage / 100 < 3 ? damage / 100 : 0;
		int meta = damage % 100;
		// TODO change BackpackUtil.getSize(tier, color) [multidimensional array build from config]
		if(meta == 99) { // ender
			size = 27;
		} else if(meta < 17 && tier == 2) { // big
			size = ConfigurationBackpack.BACKPACK_SLOTS_L;
		} else if(meta < 17 && tier == 0) { // normal
			size = ConfigurationBackpack.BACKPACK_SLOTS_S;
		} else if(meta == 17 && tier == 0) { // workbench
			size = 9;
		} else if(meta == 17 && tier == 2) { // big workbench
			size = 18;
		}

		setManualSaving();

		setSlotsPerRow(9);
		setSize(size);
		setType(BackpackUtil.getType(backpack));
		if(!NBTUtil::hasTag(nbtTagCompound, Constants::NBT::INVENTORIES))
			NBTUtil::setCompoundTag(nbtTagCompound, Constants::NBT::INVENTORIES, new CompoundTag*());

		save();
	}*/
}

std::string BackpackSave::getUUID()
{
	return UID;
}

std::string BackpackSave::getUUID(ItemInstance* backpack)
{
	if(NBTItemInstanceUtil::hasTag(backpack, Constants::NBT::UID))
		return NBTItemInstanceUtil::getString(backpack, Constants::NBT::UID);
	else
		return (new BackpackSave(backpack))->getUUID();
}

bool BackpackSave::isIntelligent()
{
	return NBTUtil::getBoolean(nbtTagCompound, Constants::NBT::INTELLIGENT);
}

void BackpackSave::setIntelligent()
{
	NBTUtil::setBoolean(nbtTagCompound, Constants::NBT::INTELLIGENT, true);

	if(!manualSaving)
		save();
}

int BackpackSave::getSize()
{
	return NBTUtil::getInteger(nbtTagCompound, Constants::NBT::SIZE);
}

void BackpackSave::setSize(int size)
{
	NBTUtil::setInteger(nbtTagCompound, Constants::NBT::SIZE, size);

	if(!manualSaving)
		save();
}

int BackpackSave::getSlotsPerRow()
{
	return NBTUtil::getInteger(nbtTagCompound, Constants::NBT::SLOTS_PER_ROW);
}

void BackpackSave::setSlotsPerRow(int slotsPerRow)
{
	NBTUtil::setInteger(nbtTagCompound, Constants::NBT::SLOTS_PER_ROW, slotsPerRow);

	if(!manualSaving)
		save();
}


ListTag* BackpackSave::getInventory(const std::string& inventory)
{
	CompoundTag* inventories = NBTUtil::getCompoundTag(nbtTagCompound, Constants::NBT::INVENTORIES);
	return NBTUtil::getTagList(inventories, inventory);
}

void BackpackSave::setInventory(const std::string& inventoryName, ListTag* inventory)
{
	CompoundTag* inventories = NBTUtil::getCompoundTag(nbtTagCompound, Constants::NBT::INVENTORIES);
	NBTUtil::setTagList(inventories, inventoryName, inventory);

	if(!manualSaving)
		save();
}


char BackpackSave::getType()
{
	return NBTUtil::getByte(nbtTagCompound, Constants::NBT::TYPE);
}

void BackpackSave::setType(char type)
{
	NBTUtil::setByte(nbtTagCompound, Constants::NBT::TYPE, type);

	if(!manualSaving)
		save();
}

void BackpackSave::save()
{
	if(!UID.empty() /*&& BackpackUtil.isServerSide()*/)
		//Backpack.saveFileHandler.saveBackpack(nbtTagCompound, UID);

	manualSaving = false;
}

void BackpackSave::load(const std::string& UUID)
{
	if(!UUID.empty() /*&& BackpackUtil.isServerSide()*/) {
		UID = UUID;
		nbtTagCompound = /*Backpack.saveFileHandler.loadBackpack(UID)*/ new CompoundTag();
	}
}