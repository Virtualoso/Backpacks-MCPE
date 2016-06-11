#include "AbstractSave.h"

#include "com/mojang/minecraftpe/client/nbt/CompoundTag.h"

AbstractSave::AbstractSave(CompoundTag* data)
{
	nbtTagCompound = data;
	if(!nbtTagCompound) {
		nbtTagCompound = new CompoundTag();
	}
	manualSaving = false;
}

AbstractSave::AbstractSave(const std::string& UUID)
{
	load(UUID);
	manualSaving = false;
}

void AbstractSave::setManualSaving()
{
	manualSaving = true;
}

char AbstractSave::getType()
{
	
}

void AbstractSave::setType(char)
{
	
}

void AbstractSave::save()
{
	
}

void AbstractSave::load(const std::string&)
{
	
}