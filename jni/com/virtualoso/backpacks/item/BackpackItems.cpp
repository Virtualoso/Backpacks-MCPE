#include "BackpackItems.h"
#include "Backpack.h"
#include "BigBackpack.h"
#include "Leather.h"

#include "com/virtualoso/nativetools-api/CreativeTab.h"

Item* BackpackItems::backpack;
Item* BackpackItems::blackbackpack;
Item* BackpackItems::bluebackpack;
Item* BackpackItems::brownbackpack;
Item* BackpackItems::cyanbackpack;
Item* BackpackItems::enderbackpack;
Item* BackpackItems::graybackpack;
Item* BackpackItems::greenbackpack;
Item* BackpackItems::lightbluebackpack;
Item* BackpackItems::lightgraybackpack;
Item* BackpackItems::limebackpack;
Item* BackpackItems::magentabackpack;
Item* BackpackItems::orangebackpack;
Item* BackpackItems::pinkbackpack;
Item* BackpackItems::purplebackpack;
Item* BackpackItems::redbackpack;
Item* BackpackItems::whitebackpack;
Item* BackpackItems::workbenchbackpack;
Item* BackpackItems::yellowbackpack;
	
Item* BackpackItems::bigbackpack;
Item* BackpackItems::bigblackbackpack;
Item* BackpackItems::bigbluebackpack;
Item* BackpackItems::bigbrownbackpack;
Item* BackpackItems::bigcyanbackpack;
Item* BackpackItems::biggraybackpack;
Item* BackpackItems::biggreenbackpack;
Item* BackpackItems::biglightbluebackpack;
Item* BackpackItems::biglightgraybackpack;
Item* BackpackItems::biglimebackpack;
Item* BackpackItems::bigmagentabackpack;
Item* BackpackItems::bigorangebackpack;
Item* BackpackItems::bigpinkbackpack;
Item* BackpackItems::bigpurplebackpack;
Item* BackpackItems::bigredbackpack;
Item* BackpackItems::bigwhitebackpack;
Item* BackpackItems::bigworkbenchbackpack;
Item* BackpackItems::bigyellowbackpack;
	
Item* BackpackItems::boundleather;
Item* BackpackItems::tannedleather;

void BackpackItems::initItems()
{
	backpack = new Backpack("backpack"); //id : 4096; data : 0
	blackbackpack = new Backpack("blackbackpack"); //id : 4096; data : 1
	redbackpack = new Backpack("redbackpack"); //id : 4096; data : 2
	greenbackpack = new Backpack("greenbackpack"); //id : 4096; data : 3
	brownbackpack = new Backpack("brownbackpack"); //id : 4096; data : 4
	bluebackpack = new Backpack("bluebackpack"); //id : 4096; data : 5
	purplebackpack = new Backpack("purplebackpack"); //id : 4096; data : 6
	cyanbackpack = new Backpack("cyanbackpack"); //id : 4096; data : 7
	lightgraybackpack = new Backpack("lightgraybackpack"); //id : 4096; data : 8
	graybackpack = new Backpack("graybackpack"); //id : 4096; data : 9
	pinkbackpack = new Backpack("pinkbackpack"); //id : 4096; data : 10
	limebackpack = new Backpack("limebackpack"); //id : 4096; data : 11
	yellowbackpack = new Backpack("yellowbackpack"); //id : 4096; data : 12
	lightbluebackpack = new Backpack("lightbluebackpack"); //id : 4096; data : 13
	magentabackpack = new Backpack("magentabackpack"); //id : 4096; data : 14
	orangebackpack = new Backpack("orangebackpack"); //id : 4096; data : 15
	whitebackpack = new Backpack("whitebackpack"); //id : 4096; data : 16
	
	bigbackpack = new BigBackpack("bigbackpack"); //id : 4096; data : 200
	bigblackbackpack = new BigBackpack("bigblackbackpack"); //id : 4096; data : 201
	bigredbackpack = new BigBackpack("bigredbackpack"); //id : 4096; data : 202
	biggreenbackpack = new BigBackpack("biggreenbackpack"); //id : 4096; data : 203
	bigbrownbackpack = new BigBackpack("bigbrownbackpack"); //id : 4096; data : 204
	bigbluebackpack = new BigBackpack("bigbluebackpack"); //id : 4096; data : 205
	bigpurplebackpack = new BigBackpack("bigpurplebackpack"); //id : 4096; data : 206
	bigcyanbackpack = new BigBackpack("bigcyanbackpack"); //id : 4096; data : 207
	biglightgraybackpack = new BigBackpack("biglightgraybackpack"); //id : 4096; data : 208
	biggraybackpack = new BigBackpack("biggraybackpack"); //id : 4096; data : 209
	bigpinkbackpack = new BigBackpack("bigpinkbackpack"); //id : 4096; data : 210
	biglimebackpack = new BigBackpack("biglimebackpack"); //id : 4096; data : 211
	bigyellowbackpack = new BigBackpack("bigyellowbackpack"); //id : 4096; data : 212
	biglightbluebackpack = new BigBackpack("biglightbluebackpack"); //id : 4096; data : 213
	bigmagentabackpack = new BigBackpack("bigmagentabackpack"); //id : 4096; data : 214
	bigorangebackpack = new BigBackpack("bigorangebackpack"); //id : 4096; data : 215
	bigwhitebackpack = new BigBackpack("bigwhitebackpack"); //id : 4096; data : 216
	
	enderbackpack = new Backpack("enderbackpack"); //id : 4096; data : 31999
	
	workbenchbackpack = new Backpack("workbenchbackpack"); //id : 4097; data : 17
	bigworkbenchbackpack = new BigBackpack("bigworkbenchbackpack"); //id : 4097; data : 217
	
	boundleather = new Leather("boundleather"); //id : 4098; data : 0
	tannedleather = new Leather("tannedleather"); //id : 4099; data : 0
}

void BackpackItems::initTabs()
{
	CreativeTab* backpackTab = new CreativeTab(backpack, 0);
	
	backpackTab->addItem(backpack, 0);
	backpackTab->addItem(blackbackpack, 0);
	backpackTab->addItem(redbackpack, 0);
	backpackTab->addItem(greenbackpack, 0);
	backpackTab->addItem(brownbackpack, 0);
	backpackTab->addItem(bluebackpack, 0);
	backpackTab->addItem(purplebackpack, 0);
	backpackTab->addItem(cyanbackpack, 0);
	backpackTab->addItem(lightgraybackpack, 0);
	backpackTab->addItem(graybackpack, 0);
	backpackTab->addItem(pinkbackpack, 0);
	backpackTab->addItem(limebackpack, 0);
	backpackTab->addItem(yellowbackpack, 0);
	backpackTab->addItem(lightbluebackpack, 0);
	backpackTab->addItem(magentabackpack, 0);
	backpackTab->addItem(orangebackpack, 0);
	backpackTab->addItem(whitebackpack, 0);
	
	backpackTab->addItem(bigbackpack, 0);
	backpackTab->addItem(bigblackbackpack, 0);
	backpackTab->addItem(bigredbackpack, 0);
	backpackTab->addItem(biggreenbackpack, 0);
	backpackTab->addItem(bigbrownbackpack, 0);
	backpackTab->addItem(bigbluebackpack, 0);
	backpackTab->addItem(bigpurplebackpack, 0);
	backpackTab->addItem(bigcyanbackpack, 0);
	backpackTab->addItem(biglightgraybackpack, 0);
	backpackTab->addItem(biggraybackpack, 0);
	backpackTab->addItem(bigpinkbackpack, 0);
	backpackTab->addItem(biglimebackpack, 0);
	backpackTab->addItem(bigyellowbackpack, 0);
	backpackTab->addItem(biglightbluebackpack, 0);
	backpackTab->addItem(bigmagentabackpack, 0);
	backpackTab->addItem(bigorangebackpack, 0);
	backpackTab->addItem(bigwhitebackpack, 0);
	
	backpackTab->addItem(enderbackpack, 0);
	
	backpackTab->addItem(workbenchbackpack, 0);
	backpackTab->addItem(bigworkbenchbackpack, 0);
	
	backpackTab->addItem(boundleather, 0);
	backpackTab->addItem(tannedleather, 0);
	
	backpackTab->addToTabsList();
}