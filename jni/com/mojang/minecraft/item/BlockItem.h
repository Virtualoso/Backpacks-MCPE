#pragma once

#include "Item.h"

class BlockItem : public Item {

public:

    virtual ~BlockItem();
    virtual bool isDestructive(int) const;
    virtual bool isValidAuxValue(int) const;
    virtual std::string buildDescriptionName(ItemInstance const&) const;
    virtual bool isEmissive(int) const;
    virtual TextureUVCoordinateSet const& getIcon(int, int, bool) const;
    virtual int getIconYOffset() const;
    virtual bool _calculatePlacePos(ItemInstance&, Entity&, signed char&, BlockPos&) const;
    virtual bool _useOn(ItemInstance&, Entity&, BlockPos, signed char, float, float, float) const;

    BlockItem(std::string const&, int);

};

