#include "NBTUtil.h"

#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"
#include "com/mojang/minecraftpe/client/nbt/ListTag.h"

CompoundTag* NBTUtil::initCompoundTag(CompoundTag* nbtTagCompound)
{
	if(nbtTagCompound == NULL)
		return new CompoundTag();

	return nbtTagCompound;
}

bool NBTUtil::hasTag(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(nbtTagCompound != NULL)
		return nbtTagCompound->contains(tagName);
	
	return false;
}

void NBTUtil::removeTag(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(nbtTagCompound != NULL)
		nbtTagCompound->remove(tagName);
}

std::string NBTUtil::getString(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getString(tagName);

	return "";
}

void NBTUtil::setString(CompoundTag* nbtTagCompound, const std::string& tagName, const std::string& tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putString(tagName, tagValue);
}

bool NBTUtil::getBoolean(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getBoolean(tagName);

	return false;
}

void NBTUtil::setBoolean(CompoundTag* nbtTagCompound, const std::string& tagName, bool tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putBoolean(tagName, tagValue);
}

char NBTUtil::getByte(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getByte(tagName);
	
	return (char) 0;
}

void NBTUtil::setByte(CompoundTag* nbtTagCompound, const std::string& tagName, char tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putByte(tagName, tagValue);
}
	
short NBTUtil::getShort(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getShort(tagName);

	return (short) 0;
}

void NBTUtil::setShort(CompoundTag* nbtTagCompound, const std::string& tagName, short tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putShort(tagName, tagValue);
}

int NBTUtil::getInteger(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getInt(tagName);

	return 0;
}

void NBTUtil::setInteger(CompoundTag* nbtTagCompound, const std::string& tagName, int tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putInt(tagName, tagValue);
}

long NBTUtil::getLong(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getInt64(tagName);

	return (long) 0;
}

void NBTUtil::setLong(CompoundTag* nbtTagCompound, const std::string& tagName, long tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putInt64(tagName, tagValue);
}

float NBTUtil::getFloat(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getFloat(tagName);

	return (float) 0;
}

void NBTUtil::setFloat(CompoundTag* nbtTagCompound, const std::string& tagName, float tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putFloat(tagName, tagValue);
}

double NBTUtil::getDouble(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getDouble(tagName);
	
	return (double) 0;
}

void NBTUtil::setDouble(CompoundTag* nbtTagCompound, const std::string& tagName, double tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putDouble(tagName, tagValue);
}

CompoundTag* NBTUtil::getCompoundTag(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getCompound(tagName);
	
	return new CompoundTag();
}

void NBTUtil::setCompoundTag(CompoundTag* nbtTagCompound, const std::string& tagName, CompoundTag* tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->putCompound(tagName, std::unique_ptr<CompoundTag>(tagValue));
}

ListTag* NBTUtil::getTagList(CompoundTag* nbtTagCompound, const std::string& tagName)
{
	if(hasTag(nbtTagCompound, tagName))
		return nbtTagCompound->getList(tagName);
	
	return new ListTag();
}

void NBTUtil::setTagList(CompoundTag* nbtTagCompound, const std::string& tagName, ListTag* tagValue)
{
	nbtTagCompound = initCompoundTag(nbtTagCompound);
	nbtTagCompound->put(tagName, std::unique_ptr<Tag>(tagValue));
}