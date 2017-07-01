#pragma once

#include <string>
#include <vector>

#include "BlockEntityType.h"
#include "../../level/BlockPos.h"
#include "../../math/AABB.h"


class Block;
class CompoundTag;
class BlockSource;

enum class BlockEntityRendererId : int {
    DEFAULT,
    SIGN,
    //TODO: Need more research
};

class BlockEntity {

public:

    /* 0x04 */ int unknown1;
    /* 0x08 */ Block* blockOwner;
    /* 0x0C */ int unknown2;
    /* 0x10 */ char filler2[12]; // Vec3?
    /* 0x1C */ int unknown3;
    /* 0x20 */ BlockPos pos;
    /* 0x2C */ AABB aabb;
    /* 0x48 */ int data;
    /* 0x4C */ BlockEntityType type;
    /* 0x50 */ int runningId;
    /* 0x54 */ bool clientSideOnly;
    /* 0x55 */ bool movable;
    /* 0x58 */ BlockEntityRendererId rendererId;
    /* 0x5C */ bool changed;
    /* size = 0x60 */

    // virtual
    virtual ~BlockEntity();
    virtual void load(CompoundTag const&);
    virtual bool save(CompoundTag&) const;
    virtual void* saveItemInstanceData(CompoundTag&);
    virtual void* saveBlockData(CompoundTag&, BlockSource&) const;
    virtual void* loadBlockData(CompoundTag const&, BlockSource&);
    virtual void tick(BlockSource&);
    virtual bool isFinished();
    virtual void onChanged(BlockSource&);
    virtual bool isMovable();
    virtual bool isCustomNameSaved();
    virtual void* getUpdatePacket(BlockSource&);
    virtual void onPlace(BlockSource&);
    virtual void onUpdatePacket(CompoundTag const&, BlockSource&);
    virtual void onMove();
    virtual void onRemoved(BlockSource&);
    virtual void triggerEvent(int, int);
    virtual BlockEntity* clearCache();
    virtual void onNeighborChanged(BlockSource&, BlockPos const&);
    virtual int getShadowRadius(BlockSource&) const;
    virtual bool hasAlphaLayer() const;
    virtual void* getCrackEntity(BlockSource&, BlockPos const&);
    virtual std::string getDebugText(std::vector<std::string, std::allocator<std::string>>&);
    virtual std::string const& getCustomName() const;
    virtual std::string getName() const;

    // non virtual
    BlockEntity(BlockEntityType, BlockPos const&, std::string const&);
    void _destructionWobble(float&, float&, float&);
    void _resetAABB();
    float distanceToSqr(Vec3 const&);
    AABB getAABB() const;
    Block* getBlock();
    int getData() const;
    BlockPos getPosition() const;
    BlockEntityRendererId getRendererId() const;
    int getRunningId() const;
    BlockEntityType getType() const;
    bool isClientSideOnly() const;
    bool isInWorld() const;
    bool isType(BlockEntityType);
    void moveTo(BlockPos const&);
    void setBB(AABB);
    void setChanged();
    void setClientSideOnly(bool);
    void setData(int);
    void setMovable(bool);
    void setRendererId(BlockEntityRendererId);
    void setRunningId(int);
    void stopDestroy();
    void setCustomNameSaved(bool);
    bool canRenderCustomName() const;
    std::string getDisplayName() const;
    void setCustomName(std::string const&);

    // static
    static void initBlockEntities();
    static bool isType(BlockEntity&, BlockEntityType);
    static BlockEntity* loadStatic(CompoundTag const&);
    static void setId(BlockEntityType, std::string const&);

};