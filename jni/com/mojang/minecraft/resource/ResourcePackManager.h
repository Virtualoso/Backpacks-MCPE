#pragma once

#include <string>
#include <memory>
#include <unordered_set>
#include "ResourcePackStack.h"
#include "ResourcePackListener.h"
class ResourceLocation;
class ResourcePack;
class PackSourceReport;

enum class PackType : unsigned char;
enum class ResourcePackStackType;

class ResourcePackManager {

public:

    /* 0x04 */ std::function<std::string ()> imagesPrefix;
    /* 0x14 */ std::unordered_set<ResourcePackListener*> listener;
    /* 0x30 */ std::unique_ptr<ResourcePackStack> stackInternal; // includes the skins resource pack
    /* 0x34 */ std::unique_ptr<ResourcePackStack> stack2;
    /* 0x38 */ std::unique_ptr<ResourcePackStack> stack3;
    /* 0x3C */ std::unique_ptr<ResourcePackStack> stack4;
    /* 0x40 */ std::unique_ptr<ResourcePackStack> stackMinecraft;
    /* 0x44 */ std::unique_ptr<ResourcePackStack> fullStack;
    /* 0x48 */ PackSourceReport* report;
    /* 0x4C */ std::string unknown;
    /* 0x50 */ bool unknown2, hasPendingStackChanges;
    /* size = 0x54 */

    // virtual
    virtual ~ResourcePackManager();
    virtual bool load(ResourceLocation const&, std::string&);
    virtual void* load(ResourceLocation const&, std::string&, std::vector<std::string, std::allocator<std::string>> const&);
    virtual void* loadAllVersionsOf(ResourceLocation const&);
    virtual void* loadTexture(ResourceLocation const&);
    virtual bool isInStreamableLocation(ResourceLocation const&);
    virtual bool isInStreamableLocation(ResourceLocation const&, std::vector<std::string, std::allocator<std::string>> const&);
    virtual void* getPath(ResourceLocation const&);
    virtual void* getPath(ResourceLocation const&, std::vector<std::string, std::allocator<std::string>> const&);
    virtual void* getPathContainingResource(ResourceLocation const&);
    virtual void* getPathContainingResource(ResourceLocation const&, std::vector<std::string, std::allocator<std::string>>);

    // non virtual
    ResourcePackManager(std::function<std::string ()>);
    void* _getResource(std::string const&, std::string&) const;
    void* loadText(ResourceLocation const&, std::string&);
    void* findAllTexturesInUse() const;
    void setStack(std::unique_ptr<ResourcePackStack, std::default_delete<ResourcePackStack>>, ResourcePackStackType, bool);
    void* _handleComposeStack(bool);
    void* clearStack(ResourcePackStackType, bool);
    void* getStack(ResourcePackStackType) const;
    bool _shouldRebuildStack() const;
    void _composeFullStack();
    void* composeFullStack(ResourcePackStack&, ResourcePackStack const&, ResourcePackStack const&, ResourcePackStack const&) const;
    void* _updateLanguageSubpacks();
    void* notifyActiveResourcePackChanged();
    void* registerResourcePackListener(ResourcePackListener&);
    void* unRegisterResourcePackListener(ResourcePackListener&);
    void* notifyLanguageSubpacksChanged();
    void* getResourcesOfGroup(ResourcePack*, std::string const&) const;
    void* _getPackForResource(std::string const&) const;
    void* checkHasExtraLocaleResources(std::string const&) const;
    void onLanguageChanged();
    void handlePendingStackChanges();
    void* copyPacksToNewLevel(std::string, PackType);
    void* loadAllVersionsOf(ResourceLocation const&, ResourcePackMergeStrategy&);
    void* getStackSize() const;
    void clearPackReports();
    void mergePackReports(std::vector<PackReport, std::allocator<PackReport>>&);
    void* getGlobalStackFromFullStack(ResourcePackStack&) const;
    void onVanillaPackDownloadComplete();
    PackSourceReport& getPackSourceReport() const;
    void setPackSourceReport(PackSourceReport&&);
    void* removePack(ResourcePack*);

};

