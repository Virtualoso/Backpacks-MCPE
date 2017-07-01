#pragma once

#include <string>
#include <vector>
#include <memory>

class Localization;
class ResourcePackManager;

class I18n {
  
public:

    // static
    static void getLocaleFor(std::string const&);
    static void chooseLanguage(std::string const&);
    static std::string get(std::string const&);
    static void _getKeyExists(std::string const&);
    static void loadLanguages(ResourcePackManager&);
    static void chooseLanguage(Localization const&);
    static void getCurrentLanguage();
    static void getSupportedLocales();
    static void languageSupportsHypenSplitting();
    static void _setLanguageSupportsHypenSplitting(Localization const&);
    static void* findAvailableLanguages(ResourcePackManager&);
    static void appendLanguageStrings(PackAccessStrategy*);
    static void* _getLocaleFor(std::string const&);
    static std::string get(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
    static void* _getFormatParmas(std::string const&, std::vector<std::string, std::allocator<std::string>>&);
    static void* getLocalizedAssetFileWithFallback(std::string const&, std::string const&);
    static void* _addFormatToDictionary(std::string const&, std::vector<std::string, std::allocator<std::string>> const&);
    static void* _findAvailableLanguages(Json::Value const&, std::vector<std::string, std::allocator<std::string>>&);
    static void* _generatePackKeyPrefix(PackManifest const&);
    static void* loadLanguages(ResourcePackManager&, ResourceLoadManager&, SkinRepository*, std::string const&);
    static void* getLocaleCodeFor(std::string const&);
    static void* loadLanguageKeywordsFromPack(PackManifest const&, PackAccessStrategy&);
    static void* _getPackKeywordLocale(std::string const&);
    static void* _getLocaleCodeFor(std::string const&);
    static void* getPackKeywordValue(PackManifest const&, std::string const&);
    static bool hasPackKeyEntry(PackManifest const&, std::string const&);
    static bool isLanguagesLoaded();
    static bool isPackKeyword(std::string const&);

    // static fields
    static std::vector<std::unique_ptr<Localization>> mLanguages;
    static std::unique_ptr<Localization> mCurrentLanguage;
    static void* mFormatDictionary;

};