#include "NBTItemInstanceUtil.h"

#include <memory>

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"
#include "com/mojang/minecraftpe/client/nbt/ListTag.h"

void NBTItemInstanceUtil::initNBTTagCompound(ItemInstance* itemStack) {
	if(itemStack->userData == NULL)
		itemStack->userData = new CompoundTag();
}


bool NBTItemInstanceUtil::hasTag(ItemInstance* itemStack, const std::string& tagName) {
	if(itemStack->userData != NULL)
		return itemStack->userData->contains(tagName);

	return false;
}

void NBTItemInstanceUtil::removeTag(ItemInstance* itemStack, const std::string& tagName) {
	if(itemStack->userData != NULL)
		itemStack->userData->remove(tagName);
}

std::string NBTItemInstanceUtil::getString(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getString(tagName);
	
	return "";
}

void NBTItemInstanceUtil::setString(ItemInstance* itemStack, const std::string& tagName, const std::string& tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putString(tagName, tagValue);
}

bool NBTItemInstanceUtil::getBoolean(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getBoolean(tagName);
	
	return false;
}

void NBTItemInstanceUtil::setBoolean(ItemInstance* itemStack, const std::string& tagName, bool tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putBoolean(tagName, tagValue);
}

char NBTItemInstanceUtil::getByte(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getByte(tagName);
	
	return (char) 0;
}

void NBTItemInstanceUtil::setByte(ItemInstance* itemStack, const std::string& tagName, char tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putByte(tagName, tagValue);
}

short NBTItemInstanceUtil::getShort(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getShort(tagName);

	return (short) 0;
}

void NBTItemInstanceUtil::setShort(ItemInstance* itemStack, const std::string& tagName, short tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putShort(tagName, tagValue);
}

int NBTItemInstanceUtil::getInteger(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getInt(tagName);
	
	return 0;
}

void NBTItemInstanceUtil::setInteger(ItemInstance* itemStack, const std::string& tagName, int tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putInt(tagName, tagValue);
}

long NBTItemInstanceUtil::getLong(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getInt64(tagName);
	
	return (long) 0;
}

void NBTItemInstanceUtil::setLong(ItemInstance* itemStack, const std::string& tagName, long tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putInt64(tagName, tagValue);
}

float NBTItemInstanceUtil::getFloat(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getFloat(tagName);
	
	return (float) 0;
}

void NBTItemInstanceUtil::setFloat(ItemInstance* itemStack, const std::string& tagName, float tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putFloat(tagName, tagValue);
}

double NBTItemInstanceUtil::getDouble(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getDouble(tagName);
	
	return (double) 0;
}

void NBTItemInstanceUtil::setDouble(ItemInstance* itemStack, const std::string& tagName, double tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putDouble(tagName, tagValue);
}

CompoundTag* NBTItemInstanceUtil::getCompoundTag(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getCompound(tagName);
	
	return new CompoundTag();
}

void NBTItemInstanceUtil::setCompoundTag(ItemInstance* itemStack, const std::string& tagName, CompoundTag* tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putCompound(tagName, std::unique_ptr<CompoundTag>(tagValue));
}

ListTag* NBTItemInstanceUtil::getTagList(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getList(tagName);
	
	return new ListTag();
}

void NBTItemInstanceUtil::setTagList(ItemInstance* itemStack, const std::string& tagName, ListTag* tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->put(tagName, std::unique_ptr<Tag>(tagValue));
}