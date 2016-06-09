#include "BackpackItems.h"
#include "ItemBackpack.h"
#include "ItemWorkbenchBackpack.h"
#include "ItemLeather.h"

#include "com/virtualoso/nativetools-api/CreativeTab.h"

Item* BackpackItems::backpack;
Item* BackpackItems::workbenchBackpack;
Item* BackpackItems::boundLeather;
Item* BackpackItems::tannedLeather;
CreativeTab* BackpackItems::tabBackpacks;

std::string BackpackItems::UNLOCALIZED_NAME_BACKPACK = "backpack";
std::string BackpackItems::UNLOCALIZED_NAME_BACKPACK_WORKBENCH = "workbenchbackpack";
std::string BackpackItems::UNLOCALIZED_NAME_BOUND_LEATHER = "boundLeather";
std::string BackpackItems::UNLOCALIZED_NAME_TANNED_LEATHER = "tannedLeather";
	
int BackpackItems::ENDERBACKPACK = 31999;
std::vector<std::string> BackpackItems::BACKPACK_TIERS = {
	"",
	"medium",
	"big"
};
std::vector<std::string> BackpackItems::BACKPACK_COLORS = {
	"",
	"black",
	"red",
	"green",
	"brown",
	"blue",
	"purple",
	"cyan",
	"lightGray",
	"gray",
	"pink",
	"lime",
	"yellow",
	"lightBlue",
	"magenta",
	"orange",
	"white",
	"ender"
};

void BackpackItems::initItems()
{
	backpack = new ItemBackpack();
	workbenchBackpack = new ItemWorkbenchBackpack();
	boundLeather = new ItemLeather("boundLeather");
	tannedLeather = new ItemLeather("tannedLeather");
}

void BackpackItems::initTabs()
{
	tabBackpacks = new CreativeTab(backpack, 0);
	
	for(int tier = 0; tier < 3; tier++)
	{
		if(tier == 1) continue;
		for(int i = 0; i < 17; i++)
		{
			tabBackpacks->addItem(backpack, tier * 100 + i);
		}
	}
	tabBackpacks->addItem(backpack, BackpackItems::ENDERBACKPACK);
	tabBackpacks->addItem(workbenchBackpack, 17);
	tabBackpacks->addItem(workbenchBackpack, 217);
	
	tabBackpacks->addToTabsList();
}

void BackpackItems::addVanillaCreativeItems()
{
	Item::addCreativeItem(boundLeather, 0);
	Item::addCreativeItem(tannedLeather, 0);
}