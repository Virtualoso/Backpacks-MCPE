#include <jni.h>
#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>
#include <string>

#include "com/mojang/minecraft/item/Item.h"

#include "EnderBackpackItem.h"

class MinecraftScreenModel;
class ClientInstance;
class BlockEntity;

#define LOG_TAG "backpack"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

EnderBackpackItem enderBackpack("hi", 14);
Item item("hi", 13);
const std::string& name = "backpack.ender";

std::string (*MinecraftScreenModel$_getVersionString)(MinecraftScreenModel*);
std::string MinecraftScreenModel$getVersionString(MinecraftScreenModel* self) {
	LOGI("Replaced Version String");
	return "Backpacks (tmp) mod";
}

int (*BlockEntity$_getType(BlockEntity*));
int BlockEntity$getType(BlockEntity* self) {
	if(enderBackpack.enderon = 0)
	{
		BlockEntity$_getType(self);
	}
	
	else {
		enderBackpack.enderon = 1;
		return 23;
	}
}

/*void (*ClientInstance$_onLevelExit)(ClientInstance*);
void ClientInstance$onLevelExit(ClientInstance* self) {
	LOGI("Checking to see if the level has been left");
	
	LOGI("Saving the items in the ender backpack");
	EnderBackpackItem::putItems(enderBackpack->tag);
	
	LOGI("Excuting the normal function");
	ClientInstance$_onLevelExit();
}*/

void (*Item$_registerItems)();
void Item$registerItems()
{
	LOGI("Init Items");
	Item::mItems[31999] = new EnderBackpackItem(name, 31999 - 256);
	
	LOGI("Items Initiated");
	
	Item$_registerItems();
}

void (*Item$_initCreativeItems)();
void Item$initCreativeItems()
{
	Item$_initCreativeItems();
	
	LOGI("Add Items to Creative");
	item.addCreativeItem(Item::mItems[31999], 0);
	LOGI("Items added to Creative");
}

JNIEXPORT jint JNI_OnLoad(JavaVM *vm, void *reserved)  {
	void* handle = dlopen("libminecraftpe.so", RTLD_LAZY);
    LOGI("loaded handle");
	
    void* getVersion = dlsym(handle, "_ZNK20MinecraftScreenModel16getVersionStringEv");
    LOGI("aquired version dlsym!");
	void* levelExit = dlsym(handle, "_ZN14ClientInstance11onLevelExitEv");
	LOGI("aquired levelexit dlsym");
	void* getType = dlsym(handle, "_ZNK11BlockEntity7getTypeEv");
	LOGI("aquired levelexit dlsym");
	
	LOGI("Loading Hooks");
	
	MSHookFunction((void*) &Item::registerItems, (void*) &Item$registerItems, (void**) &Item$_registerItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &Item$_initCreativeItems);
	MSHookFunction(getVersion, (void*) &MinecraftScreenModel$getVersionString, (void**) &MinecraftScreenModel$_getVersionString);
	//MSHookFunction(levelExit, (void*) &ClientInstance$onLevelExit, (void**) &ClientInstance$_onLevelExit);
	MSHookFunction(getType, (void*) &BlockEntity$getType, (void**) &BlockEntity$_getType);
	
	LOGI("Finished Loading Hooks");
	
    return JNI_VERSION_1_6;
}
