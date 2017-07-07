#pragma once

#include "com/mojang/minecraftpe/client/model/HumanoidModel.h"
#include "com/mojang/minecraftpe/client/model/ModelPart.h"

class ModelBackpack : public HumanoidModel {
public:
		
		ModelPart bagTop;
		ModelPart bagMain;
		ModelPart pocketLeft;
		ModelPart pocketRight;
		ModelPart pocketFront;
		ModelPart ledgeFront1;
		ModelPart ledgeFront2;
		ModelPart ledgeFront3;
		ModelPart stringTopLeft;
		ModelPart stringTopRight;
		ModelPart stringBackLeft;
		ModelPart stringBackRight;
		ModelPart stringBottomLeft;
		ModelPart stringBottomRight;
		
		int check = 0;
		
		ModelBackpack();
		ModelBackpack(float);
		ModelBackpack(float, float, int, int);
		
		virtual void render(Entity&, float, float, float, float, float, float);
		virtual void setupAnim(float, float, float, float, float, float);
		
private:
		
		void setRotation(ModelPart, Vec3);
};