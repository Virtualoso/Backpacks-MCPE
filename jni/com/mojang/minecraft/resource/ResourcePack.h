#pragma once

#include <functional>
#include <memory>
#include "ResourceLocation.h"
class PackManifest;
class PackAccessStrategy;
class PackManifest;
class MinecraftEventing;
enum class ResourcePackLocation;
enum class PackCategory {
  FREE, ENTITLEMENT, PAID
};
enum class PackOrigin;

class ResourcePack {

public:

    /* 0x00 */ char filler[0x14];
    /* 0x14 */ std::unique_ptr<PackManifest> manifest;
    /* 0x18 */ int filler2;
    /* size = 0x1C */

    ResourcePack(std::unique_ptr<PackAccessStrategy, std::default_delete<PackAccessStrategy>>, PackCategory, PackOrigin, bool);
    ~ResourcePack();
    std::string const& getPackId() const;
    std::string const& getVersion() const;
    PackManifest* getManifest() const;
    ResourceLocation const& getResourceLocation() const;
    ResourceFileSystem getFileSystem() const;
    void* getFolderName() const;
    void* getZipFolder() const;
    bool isZipped() const;

    void* _generateIconPath();
    void* _generateTextureListIfNeeded();
    void* _generateAssetSet();
    void* getIconPath() const;
    void* getDefaultItemIconPath();
    void* getDefaultItemFileSystem();
    void* getDefaultBugItemIconPath();
    void* getDefaultBugItemFileSystem();

    bool hasResource(std::string const&) const;
    bool hasExtraResourcesForLocale(std::string const&) const;

    bool getFile(std::string const&, std::string&) const;
    bool getResource(std::string const&, std::string&) const;

    void forEachIn(std::string const&, std::function<void (std::string const&)>, bool) const;

    void setLocale(std::string const&);
    void setError();

    void gatherResourcePackTelemetry(MinecraftEventing&, int);
    void gatherBehaviorPackTelemetry(MinecraftEventing&, int);

    // static fields
    static std::string RESOURCE_PACK_ICON_PATH;

};

