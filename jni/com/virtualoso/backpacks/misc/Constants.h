#pragma once

#include <string>

class Constants
{
	static std::string MOD_ID;
	static std::string MOD_NAME;
	static std::string MOD_VERSION;
	static std::string FINGERPRINT;

	static std::string DOMAIN;

	static std::string RECIPE_ENHANCE;
	static std::string RECIPE_INTELLIGENT;
	static std::string RECIPE_RECOLOR;

	static std::string UPDATE_FILE;

	class Guis
	{
    	static char OPEN_PERSONAL_BACKPACK;
    	static char OPEN_PERSONAL_SLOT;
    };

	class GuiCommands 
	{
    	static char CLEAR;
    	static char SAVE;
    	static char PREV;
    	static char NEXT;
    };

	class NBT
	{
    	static std::string INVENTORIES;
    	static std::string INVENTORY_BACKPACK;
    	static std::string INVENTORY_PERSONAL_BACKPACK;
    	static std::string INVENTORY_PICKUP_ITEMS;
    	static std::string INVENTORY_CRAFTING_GRID;
    	static std::string INVENTORY_RECIPES;
    	static std::string INVENTORY_RECIPE;
    	static std::string UID;
    	static std::string NAME;
    	static std::string CUSTOM_NAME;
    	static std::string SIZE;
    	static std::string SLOT;
    	static std::string SLOTS_PER_ROW;
    	static std::string INTELLIGENT;
    	static std::string TYPE;
    	static std::string PERSONAL_BACKPACK_OPEN;
    };

};
