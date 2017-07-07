#pragma once

#include "../AppPlatformListener.h"

class Entity;
class Mob;
class AABB;
class ModelPart;

//this class = ModelBiped in java

class HumanoidModel : public Model {
public:

		//a filler, aka im too lazy to figure out what is what
		char filler[0x100];
		
		HumanoidModel(GeometryPtr const&);
		HumanoidModel(float, float, int, int);
		
		virtual ~Model();
		virtual void render(Entity&, float, float, float, float, float, float);
		virtual void setupAnim(float, float, float, float, float, float);
		virtual void prepareMobModel(Mob&, float, float, float);
		virtual int getHeightAdjustment() const;
		
		static ARM_ANGLE_X_USE_ITEM_INTERVAL;
		static ARM_ANGLE_X_USE_ITEM_STARTUP;
		static ARM_ANGLE_Y_USE_ITEM_STARTUP;
		static ARM_ANGLE_Z_USE_ITEM_STARTUP;
		static HAT_OVERLAY_SCALE;
		static OVERLAY_SCALE;
};