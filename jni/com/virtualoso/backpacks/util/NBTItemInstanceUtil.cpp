#include "NBTItemInstanceUtil.h"

#include <memory>

#include "com/mojang/minecraftpe/world/item/ItemInstance.h"
#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"
#include "com/mojang/minecraftpe/client/nbt/ListTag.h"

void initNBTTagCompound(ItemInstance* itemStack) {
	if(itemStack->userData == NULL)
		itemStack->userData = new CompoundTag();
}


bool hasTag(ItemInstance* itemStack, const std::string& tagName) {
	if(itemStack->userData != NULL)
		return itemStack->userData->contains(tagName);

	return false;
}

void removeTag(ItemInstance* itemStack, const std::string& tagName) {
	if(itemStack->userData != NULL)
		itemStack->userData->remove(tagName);
}

std::string getString(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getString(tagName);
	
	return "";
}

void setString(ItemInstance* itemStack, const std::string& tagName, const std::string& tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putString(tagName, tagValue);
}

bool getBoolean(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getBoolean(tagName);
	
	return false;
}

void setBoolean(ItemInstance* itemStack, const std::string& tagName, bool tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putBoolean(tagName, tagValue);
}

char getByte(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getByte(tagName);
	
	return (char) 0;
}

void setByte(ItemInstance* itemStack, const std::string& tagName, char tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putByte(tagName, tagValue);
}

short getShort(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getShort(tagName);

	return (short) 0;
}

void setShort(ItemInstance* itemStack, const std::string& tagName, short tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putShort(tagName, tagValue);
}

int getInteger(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getInt(tagName);
	
	return 0;
}

void setInteger(ItemInstance* itemStack, const std::string& tagName, int tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putInt(tagName, tagValue);
}

long getLong(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getInt64(tagName);
	
	return (long) 0;
}

void setLong(ItemInstance* itemStack, const std::string& tagName, long tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putInt64(tagName, tagValue);
}

float getFloat(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getFloat(tagName);
	
	return (float) 0;
}

void setFloat(ItemInstance* itemStack, const std::string& tagName, float tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putFloat(tagName, tagValue);
}

double getDouble(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getDouble(tagName);
	
	return (double) 0;
}

void setDouble(ItemInstance* itemStack, const std::string& tagName, double tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putDouble(tagName, tagValue);
}

CompoundTag* getCompoundTag(ItemInstance* itemStack, const std::string& tagName) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getCompound(tagName);
	
	return new CompoundTag();
}

void setCompoundTag(ItemInstance* itemStack, const std::string& tagName, CompoundTag* tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->putCompound(tagName, std::unique_ptr<CompoundTag>(tagValue));
}

ListTag* getTagList(ItemInstance* itemStack, const std::string& tagName, int tagType) {
	if(hasTag(itemStack, tagName))
		return itemStack->userData->getList(tagName, tagType);
	
	return new ListTag();
}

void setTagList(ItemInstance* itemStack, const std::string& tagName, ListTag* tagValue) {
	initNBTTagCompound(itemStack);
	itemStack->userData->put(tagName, std::unique_ptr<Tag>(tagValue));
}