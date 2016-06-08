#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <Substrate.h>

#include "Backpacks.h"

#include "item/BackpackItems.h"


void Mod::initItems()
{
	BackpackItems::initItems();
}

void Mod::initCustomCreativeItems()
{
	BackpackItems::initTabs();
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {

	new Backpacks();
	
	return JNI_VERSION_1_2;
}
