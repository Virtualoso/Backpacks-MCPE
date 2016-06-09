#pragma once

#include <string>

class CompoundTag;

class AbstractSave {
protected:
	std::string UID;
	CompoundTag* nbtTagCompound;
	bool manualSaving;

public:
	AbstractSave(CompoundTag*);
	AbstractSave(const std::string&);
	void setManualSaving();
	virtual char getType();
	virtual void setType(char);
	virtual void save();
	virtual void load(const std::string&);
};
