#pragma once

#include <string>
#include <memory>
#include <vector>

class ResourcePackManager;

class Localization {
  
public:

    enum class State : int;

    /* 0x00 */ State state;
    /* 0x04 */ unsigned char commaSeperator;
    char filler[0x23];
    /* size = 0x28 */

    // non virtual
    Localization(std::string const&);
    Localization(std::string const&, Localization*);
    std::string getLanguageCode(std::string const&);
    void* getLanguageCode() const;
    std::string getStringIdExists(std::string const&) const;
    std::string get(std::string const&, std::string&, std::vector<std::string, std::allocator<std::string>> const&) const;
    std::string _get(std::string const&, std::vector<std::string, std::allocator<std::string>> const&) const;
    void* getRegionCode(std::string const&);
    bool isFormattedString(std::string const&);
    void* _getSimple(std::string const&) const;
    void _replaceTokens(std::string&, std::vector<std::string, std::allocator<std::string>> const&) const;
    unsigned char getCommaSeperator() const;
    std::string getFullLanguageCode() const;
    void appendTranslations(std::string const&, std::vector<std::string, std::allocator<std::string>> const&, std::vector<std::string, std::allocator<std::string>> const&, std::string const&);
    void* _getStrings() const;
    void _parseFormattedString(std::string const&) const;
    void* loadFromResourcePackManager(ResourcePackManager&, std::vector<std::string, std::allocator<std::string>> const&);
    void* _getLangFilePath(std::string const&);
    void* loadFromPack(std::string const&, PackAccessStrategy&, std::vector<std::string, std::allocator<std::string>> const&);
    bool _isCommaSeperatedLanguage(std::string const&);

    // static fields
    static std::unique_ptr<Localization> fallbackLocale;
    
};