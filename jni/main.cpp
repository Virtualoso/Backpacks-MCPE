#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "code/backpacks/item/BackpackItems.h"
#include "code/mcpe/world/item/Item.h"

#define LOG_TAG "backpacks"

#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

static void (*_Item$initItems)();
static void Item$initItems()
{
	BackpackItems::initItems();
	
	_Item$initItems();
}

static void (*_Item$initCreativeItems)();
static void Item$initCreativeItems()
{
	_Item$initCreativeItems();

	BackpackItems::initCreativeItems();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	MSHookFunction((void*) &Item::initItems, (void*) &Item$initItems, (void**) &_Item$initItems);
	MSHookFunction((void*) &Item::initCreativeItems, (void*) &Item$initCreativeItems, (void**) &_Item$initCreativeItems);
	
	return JNI_VERSION_1_2;
}
