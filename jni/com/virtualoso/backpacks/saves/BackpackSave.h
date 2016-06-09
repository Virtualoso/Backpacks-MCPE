#pragma once

#include "AbstractSave.h"

class ItemInstance;
class ListTag;

class BackpackSave : public AbstractSave
{
public:
	BackpackSave(const std::string&);
	BackpackSave(CompoundTag* data);
	BackpackSave(ItemInstance*);
	BackpackSave(ItemInstance*, bool);

	bool isUninitialized();
	void initialize(ItemInstance*);
	std::string getUUID();
	std::string getUUID(ItemInstance*);
	bool isIntelligent();
	void setIntelligent();
	int getSize();
	void setSize(int);
	int getSlotsPerRow();
	void setSlotsPerRow(int);
	
	ListTag* getInventory(const std::string&);
	void setInventory(const std::string&, ListTag*);
	
	virtual char getType();
	virtual void setType(char);
	virtual void save();
	virtual void load(const std::string&);
};