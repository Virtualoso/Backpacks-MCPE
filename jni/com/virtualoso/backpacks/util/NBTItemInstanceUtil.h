#pragma once

#include <string>

class ItemInstance;
class CompoundTag;
class ListTag;

class NBTItemInstanceUtil {
private:
	static void initNBTTagCompound(ItemInstance*);

public:
	static bool hasTag(ItemInstance*, const std::string&);
	static void removeTag(ItemInstance*, const std::string&);
	static std::string getString(ItemInstance*, const std::string&);
	static void setString(ItemInstance*, const std::string&, const std::string& tagValue);
	static bool getBoolean(ItemInstance*, const std::string&);
	static void setBoolean(ItemInstance*, const std::string&, bool tagValue);
	static char getByte(ItemInstance*, const std::string&);
	static void setByte(ItemInstance*, const std::string&, char tagValue);
	static short getShort(ItemInstance*, const std::string&);
	static void setShort(ItemInstance*, const std::string&, short tagValue);
	static int getInteger(ItemInstance*, const std::string&);
	static void setInteger(ItemInstance*, const std::string&, int tagValue);
	static long getLong(ItemInstance*, const std::string&);
	static void setLong(ItemInstance*, const std::string&, long tagValue);
	static float getFloat(ItemInstance*, const std::string&);
	static void setFloat(ItemInstance*, const std::string&, float tagValue);
	static double getDouble(ItemInstance*, const std::string&);
	static void setDouble(ItemInstance*, const std::string&, double tagValue);
	static CompoundTag* getCompoundTag(ItemInstance*, const std::string&);
	static void setCompoundTag(ItemInstance*, const std::string&, CompoundTag* tagValue);
	static ListTag* getTagList(ItemInstance*, const std::string&, int tagType);
	static void setTagList(ItemInstance*, const std::string&, ListTag* tagValue);
};
