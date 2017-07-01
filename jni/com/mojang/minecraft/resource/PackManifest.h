#pragma once

#include <string>

class ResourceLocation;
class ResourceMetadata;
class PackIdVersion;
class SemVersion;
class ResourceInformation;
class LegacyPackIdVersion;
enum class PackType : unsigned char;
enum class PackCategory;
enum class PackOrigin;
enum class ManifestType : unsigned char;
enum class ManifestOrigin : unsigned char;

class PackManifest {

public:

    char filler[0xB0];

    PackManifest(ManifestType);
    PackManifest(PackManifest const&);

    PackManifest& operator=(PackManifest&&);

    ResourceLocation const& getLocation() const;
    void setLocation(ResourceLocation const&);

    std::string getDescription() const;
    std::string const& getDescriptionRaw() const;
    void setDescription(std::string const&);

    std::string getName() const;
    std::string const& getNameRaw() const;
    void setName(std::string const&);

    ResourceMetadata const& getMetaData() const;
    void setMetadata(ResourceMetadata const&);

    PackType getPackType() const;
    void setPackType(PackType);
    PackCategory getPackCategory() const;
    void setPackCategory(PackCategory);
    PackOrigin getPackOrigin() const;
    void setPackOrigin(PackOrigin);

    PackIdVersion const& getIdentity() const;
    void setIdentity(PackIdVersion const&);

    bool isHidden() const;
    void setHidden(bool);

    bool isPremium() const;

    ManifestOrigin getManifestOrigin() const;
    void setManifestOrigin(ManifestOrigin const&);
    ManifestType getManifestType() const;
    void setManifestType(ManifestType const&);

    ResourceLocation const& getPackIconLocation() const;
    void setPackIconLocation(ResourceLocation const&);

    bool hasModule(PackIdVersion const&) const;
    //bool hasModuleType(ResourceInformation::ResourceType) const;
    void addModule(ResourceInformation const&);
    void* getModules() const;
    void clearModules();

    void* getDependentPackIdentities() const;
    void addPackDependency(PackIdVersion const&);
    void clearPackDependencies();
    void addLegacyModuleDependency(LegacyPackIdVersion const&);
    void* getLegacyModuleDependencies() const;
    bool hasLegacyModuleDependencies() const;
    void clearLegacyModuleDependencies();

    unsigned long long getPackSize() const;
    void setPackSize(unsigned long long);

    std::string const& getContentKey() const;
    void setContentKey(std::string const&);

    void* serialize(int, Json::Value&);
    void* _serializeHeader(Json::Value&);
    void* _serializeModules(Json::Value&);
    void* _serializeDependencies(Json::Value&);
    void* _serializeMeta(Json::Value&);
    void* _serailizeLegacyModuleDependencies(Json::Value&);
    void* _serializeVersion(Json::Value&, SemVersion const&);

    long getLastModifiedDate() const;
    void setLastModifiedDate(long);
    void setLastModifiedDate(std::string const&);

    int getFormatVersion() const;
    void setFormatVersion(int);
    int getOriginalFormatVersion() const;
    void setOriginalFormatVersion(int);

    void* generateBaseIconPath() const;
    void* getFileSystemFromOrigin() const;
    void* getZipFolderPath() const;
    void* generateIconPath() const;

};
