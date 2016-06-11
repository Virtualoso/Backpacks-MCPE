#pragma once

#include <string>

class ItemInstance;
class Level;
class CompoundTag;
class Player;

class BackpackUtil
{
public:
	static bool isEnderBackpack(ItemInstance*);
	static bool isServerSide();
	static bool isServerSide(Level*);
	static std::string getUUID(CompoundTag*);
	static char getType(ItemInstance*);
	static void pickupItem(Player*, ItemInstance*);
	static bool canStack(ItemInstance*, ItemInstance*);
	static bool areStacksEqual(ItemInstance*, ItemInstance*);
	static bool areStacksEqual(ItemInstance*, ItemInstance*, bool);
	static bool areStacksEqualByOD(ItemInstance*, ItemInstance*);
	static bool UUIDEquals(ItemInstance*, ItemInstance*);
	static bool UUIDEquals(ItemInstance*, const std::string&);
	static bool UUIDEquals(const std::string&, const std::string&);
};
