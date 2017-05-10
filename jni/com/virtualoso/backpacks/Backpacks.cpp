#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "com/mojang/minecraftpe/locale/Localization.h"
#include "com/mojang/minecraftpe/client/MinecraftClient.h"
#include "com/mojang/minecraftpe/client/screen/ScreenChooser.h"
#include "com/mojang/minecraftpe/client/screen/AbstractScreenSetupCleanupStrategy.h"

#include "Backpacks.h"

#include "item/BackpackItems.h"
#include "gui/BackpackPlayScreen.h"

MinecraftGame* Backpacks::clientInstance;

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

static void (*_MinecraftGame$_initMinecraftGame)(MinecraftGame*);
static void MinecraftGame$_initMinecraftGame(MinecraftGame* self)
{
	_MinecraftGame$_initMinecraftGame(self);
	Backpacks::clientInstance = self;
}

static void (*_ScreenChooser$setGameplayScreen)(ScreenChooser*);
static void ScreenChooser$setGameplayScreen(ScreenChooser* self)
{
	if(!self->client.isRealityFullVRMode())
		self->_pushScreen(std::make_shared<BackpackPlayScreen>(self->client), createScreenSetupStrategy(self->client, ScreenSetupStrategyId::DEF_LEVEL), true);
	else
		_ScreenChooser$setGameplayScreen(self);
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved)
{	
	MSHookFunction((void*) &Localization::_load, (void*) &Localization$_load, (void**) &_Localization$_load);
	MSHookFunction((void*) &MinecraftGame::_initMinecraftGame, (void*) &MinecraftGame$_initMinecraftGame, (void**) &_MinecraftGame$_initMinecraftGame);
	MSHookFunction((void*) &ScreenChooser::setGameplayScreen, (void*) &ScreenChooser$setGameplayScreen, (void**) &_ScreenChooser$setGameplayScreen);

	new Backpacks();
	
	return JNI_VERSION_1_2;
}
