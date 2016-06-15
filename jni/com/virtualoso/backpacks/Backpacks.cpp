#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/locale/Localization.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/gui/screen/ScreenChooser.h"

#include "Backpacks.h"

#include "item/BackpackItems.h"
#include "gui/BackpackPlayScreen.h"

MinecraftClient* Backpacks::clientInstance;

void Backpacks::initItems()
{
	BackpackItems::initItems();
}

void Backpacks::initVanillaCreativeItems()
{
	BackpackItems::addVanillaCreativeItems();
}

void Backpacks::initCustomCreativeItems()
{
	BackpackItems::initTabs();
}

static void (*_Localization$_load)(Localization*, const std::string&);
static void Localization$_load(Localization* self, const std::string& langCode)
{
	_Localization$_load(self, langCode);
	self->_appendTranslations("loc/backpacks/" + langCode + ".lang");
}

static void (*_MinecraftClient$_initMinecraftClient)(MinecraftClient*);
static void MinecraftClient$_initMinecraftClient(MinecraftClient* self)
{
	_MinecraftClient$_initMinecraftClient(self);
	Backpacks::clientInstance = self;
}

static void (*_ScreenChooser$setGameplayScreen)(ScreenChooser*);
static void ScreenChooser$setGameplayScreen(ScreenChooser* self)
{
	_ScreenChooser$setGameplayScreen(self);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{	
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction((void*) &MinecraftClient::_initMinecraftClient, (void*) &MinecraftClient$_initMinecraftClient, (void**) &_MinecraftClient$_initMinecraftClient);
	MSHookFunction((void*) &ScreenChooser::setGameplayScreen, (void*) &ScreenChooser$setGameplayScreen, (void**) &_ScreenChooser$setGameplayScreen);

	new Backpacks();
	
	return JNI_VERSION_1_2;
}
