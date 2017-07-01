#pragma once

#include "../util/Util.h"
#include "ResourceFileSystem.h"

class ResourceLocation {

public:

    std::string path;
    ResourceFileSystem fileSystem;

    ResourceLocation(std::string const& path, ResourceFileSystem fileSystem) : path(path), fileSystem(fileSystem) { }
    ResourceLocation(std::string const& path) : ResourceLocation(path, ResourceFileSystem::InUserPackage) { }
    ResourceLocation() : ResourceLocation(Util::EMPTY_STRING) { }

    std::string getFullPath() const;

    void serialize(Json::Value&) const;
    void deserialize(Json::Value const&);

};
