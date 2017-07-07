#pragma once

#include "../AppPlatformListener.h"

class Entity;
class Mob;
class AABB;
class ModelPart;

class Model : public AppPlatformListener {
public:

		//a filler, aka im too lazy to figure out what is what
		char filler[0x100];
		
		virtual ~Model();
		virtual void onAppSuspended();
		virtual void clear();
		virtual void render();
		virtual void render(Entity&, float, float, float, float, float, float);
		virtual void setupAnim(float, float, float, float, float, float);
		virtual void prepareMobModel(Mob&, float, float, float);
		virtual int getLeashOffsetPosition() const;
		virtual int getHeightAdjustment() const;
		
		AABB* buildAABB() const;
		ModelPart* copyModelPart(ModelPart const&, ModelPart const&);
		void registerParts(ModelPart&);
};