#pragma once

#include "BlockEntity.h"
#include "../BlockID.h"

class BlockEntityFactory {
  
public:

    std::unique_ptr<BlockEntity> createBlockEntity(BlockEntityType, BlockPos const&, BlockID);
    
};