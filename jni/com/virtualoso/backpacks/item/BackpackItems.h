#pragma once

#include <string>
#include <vector>

class Item;
class CreativeTab;

class BackpackItems
{
public:
	static Item* backpack;
	static Item* workbenchBackpack;
	static Item* boundLeather;
	static Item* tannedLeather;
	static CreativeTab* tabBackpacks;

	static std::string UNLOCALIZED_NAME_BACKPACK;
	static std::string UNLOCALIZED_NAME_BACKPACK_WORKBENCH;
	static std::string UNLOCALIZED_NAME_BOUND_LEATHER;
	static std::string UNLOCALIZED_NAME_TANNED_LEATHER;
	
	static int ENDERBACKPACK;
	static std::vector<std::string> BACKPACK_TIERS;
	static std::vector<std::string> BACKPACK_COLORS;
	
	static void initItems();
	static void initTabs();
	static void addVanillaCreativeItems();
};