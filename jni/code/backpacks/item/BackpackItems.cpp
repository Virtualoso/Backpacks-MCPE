#include "BackpackItems.h"
#include "Backpack.h"
#include "BigBackpack.h"
#include "Leather.h"

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
	backpack = new Backpack("backpack", 1337);
	blackbackpack = new Backpack("blackbackpack", 1338);
	bluebackpack = new Backpack("bluebackpack", 1339);
	brownbackpack = new Backpack("brownbackpack", 1340);
	cyanbackpack = new Backpack("cyanbackpack", 1341);
	enderbackpack = new Backpack("enderbackpack", 1342);
	graybackpack = new Backpack("graybackpack", 1343);
	greenbackpack = new Backpack("greenbackpack", 1344);
	lightbluebackpack = new Backpack("lightbluebackpack", 1345);
	lightgraybackpack = new Backpack("lightgraybackpack", 1346);
	limebackpack = new Backpack("limebackpack", 1347);
	magentabackpack = new Backpack("magentabackpack", 1348);
	orangebackpack = new Backpack("orangebackpack", 1349);
	pinkbackpack = new Backpack("pinkbackpack", 1350);
	purplebackpack = new Backpack("purplebackpack", 1351);
	redbackpack = new Backpack("redbackpack", 1352);
	whitebackpack = new Backpack("whitebackpack", 1353);
	workbenchbackpack = new Backpack("workbenchbackpack", 1354);
	yellowbackpack = new Backpack("yellowbackpack", 1355);
	
	bigbackpack = new BigBackpack("bigbackpack", 1356);
	bigblackbackpack = new BigBackpack("bigblackbackpack", 1357);
	bigbluebackpack = new BigBackpack("bigbluebackpack", 1358);
	bigbrownbackpack = new BigBackpack("bigbrownbackpack", 1359);
	bigcyanbackpack = new BigBackpack("bigcyanbackpack", 1360);
	biggraybackpack = new BigBackpack("biggraybackpack", 1361);
	biggreenbackpack = new BigBackpack("biggreenbackpack", 1362);
	biglightbluebackpack = new BigBackpack("biglightbluebackpack", 1363);
	biglightgraybackpack = new BigBackpack("biglightgraybackpack", 1364);
	biglimebackpack = new BigBackpack("biglimebackpack", 1365);
	bigmagentabackpack = new BigBackpack("bigmagentabackpack", 1366);
	bigorangebackpack = new BigBackpack("bigorangebackpack", 1367);
	bigpinkbackpack = new BigBackpack("bigpinkbackpack", 1368);
	bigpurplebackpack = new BigBackpack("bigpurplebackpack", 1369);
	bigredbackpack = new BigBackpack("bigredbackpack", 1370);
	bigwhitebackpack = new BigBackpack("bigwhitebackpack", 1371);
	bigworkbenchbackpack = new BigBackpack("bigworkbenchbackpack", 1372);
	bigyellowbackpack = new BigBackpack("bigyellowbackpack", 1373);
	
	boundleather = new Leather("boundleather", 1374);
	tannedleather = new Leather("tannedleather", 1375);
}

void BackpackItems::initCreativeItems()
{
	Item::addCreativeItem(backpack, 0);
	Item::addCreativeItem(blackbackpack, 0);
	Item::addCreativeItem(bluebackpack, 0);
	Item::addCreativeItem(brownbackpack, 0);
	Item::addCreativeItem(cyanbackpack, 0);
	Item::addCreativeItem(enderbackpack, 0);
	Item::addCreativeItem(graybackpack, 0);
	Item::addCreativeItem(greenbackpack, 0);
	Item::addCreativeItem(lightbluebackpack, 0);
	Item::addCreativeItem(lightgraybackpack, 0);
	Item::addCreativeItem(limebackpack, 0);
	Item::addCreativeItem(magentabackpack, 0);
	Item::addCreativeItem(orangebackpack, 0);
	Item::addCreativeItem(pinkbackpack, 0);
	Item::addCreativeItem(purplebackpack, 0);
	Item::addCreativeItem(redbackpack, 0);
	Item::addCreativeItem(whitebackpack, 0);
	Item::addCreativeItem(workbenchbackpack, 0);
	Item::addCreativeItem(yellowbackpack, 0);
	
	Item::addCreativeItem(bigbackpack, 0);
	Item::addCreativeItem(bigblackbackpack, 0);
	Item::addCreativeItem(bigbluebackpack, 0);
	Item::addCreativeItem(bigbrownbackpack, 0);
	Item::addCreativeItem(bigcyanbackpack, 0);
	Item::addCreativeItem(biggraybackpack, 0);
	Item::addCreativeItem(biggreenbackpack, 0);
	Item::addCreativeItem(biglightbluebackpack, 0);
	Item::addCreativeItem(biglightgraybackpack, 0);
	Item::addCreativeItem(biglimebackpack, 0);
	Item::addCreativeItem(bigmagentabackpack, 0);
	Item::addCreativeItem(bigorangebackpack, 0);
	Item::addCreativeItem(bigpinkbackpack, 0);
	Item::addCreativeItem(bigpurplebackpack, 0);
	Item::addCreativeItem(bigredbackpack, 0);
	Item::addCreativeItem(bigwhitebackpack, 0);
	Item::addCreativeItem(bigworkbenchbackpack, 0);
	Item::addCreativeItem(bigyellowbackpack, 0);
	
	Item::addCreativeItem(boundleather, 0);
	Item::addCreativeItem(tannedleather, 0);
	
}