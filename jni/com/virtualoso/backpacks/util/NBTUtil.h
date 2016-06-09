#pragma once

#include <string>

class CompoundTag;
class ListTag;

class NBTUtil {
private:
	static CompoundTag* initCompoundTag(CompoundTag*);

public:
	static bool hasTag(CompoundTag*, const std::string&);
	static void removeTag(CompoundTag*, const std::string&);
	static std::string getString(CompoundTag*, const std::string&);
	static void setString(CompoundTag*, const std::string&, const std::string&);
	static bool getBoolean(CompoundTag*, const std::string&);
	static void setBoolean(CompoundTag*, const std::string&, bool);
	static char getByte(CompoundTag*, const std::string&);
	static void setByte(CompoundTag*, const std::string&, char);
	static short getShort(CompoundTag*, const std::string&);
	static void setShort(CompoundTag*, const std::string&, short);
	static int getInteger(CompoundTag*, const std::string&);
	static void setInteger(CompoundTag*, const std::string&, int);
	static long getLong(CompoundTag*, const std::string&);
	static void setLong(CompoundTag*, const std::string&, long);
	static float getFloat(CompoundTag*, const std::string&);
	static void setFloat(CompoundTag*, const std::string&, float);
	static double getDouble(CompoundTag*, const std::string&);
	static void setDouble(CompoundTag*, const std::string&, double);
	static CompoundTag* getCompoundTag(CompoundTag*, const std::string&);
	static void setCompoundTag(CompoundTag*, const std::string&, CompoundTag*);
	static ListTag* getTagList(CompoundTag*, const std::string&);
	static void setTagList(CompoundTag*, const std::string&, ListTag*);
};