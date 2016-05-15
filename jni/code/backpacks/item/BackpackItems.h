#pragma once

class Item;

class BackpackItems
{
public:

	static Item* backpack;
	static Item* bigbackpack;
	static Item* boundleather;
	
	static void initItems();
	static void initCreativeItems();
};