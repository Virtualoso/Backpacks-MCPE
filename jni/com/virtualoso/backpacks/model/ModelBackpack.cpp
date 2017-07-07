#include "ModelBackpack.h"

ModelPart ModelBackpack::bagTop;
ModelPart ModelBackpack::bagMain;
ModelPart ModelBackpack::pocketLeft;
ModelPart ModelBackpack::pocketRight;
ModelPart ModelBackpack::pocketFront;
ModelPart ModelBackpack::ledgeFront1;
ModelPart ModelBackpack::ledgeFront2;
ModelPart ModelBackpack::ledgeFront3;
ModelPart ModelBackpack::stringTopLeft;
ModelPart ModelBackpack::stringTopRight;
ModelPart ModelBackpack::stringBackLeft;
ModelPart ModelBackpack::stringBackRight;
ModelPart ModelBackpack::stringBottomLeft;
ModelPart ModelBackpack::stringBottomRight;

ModelBackpack::index;

ModelBackpack::ModelBackpack() {
	ModelBackpack(0.0F);
}

ModelBackpack::ModelBackpack(float f) {
	ModelBackpack(f, 0.0F, 64, 32);
}

ModelBackpack::ModelBackpack(float enlargement, float yShift, int textureWidth, int textureHeight) : HumanoidModel(enlargement, yShift, textureWidth, textureHeight) {
	//im assuming texture width and height are predefined
	
	bagTop = new ModelPart(44, 0, textureWidth, textureHeight);
	bagTop.addBox({-3.0F, -0.5F + yShift, 2.0F}, {6, 1, 4}, enlargement);
	setRoatation(bagTop, {0.0F, 0.0F, 0.0F});
	
	bagMain.addChild(bagTop);
}

void ModelBackpack::render(Entity& entity, float f, float f1, float f2, float f3, float f4, float f5){
	if((entity != NULL) && (entity.isSneaking())){
		check = 1;
	}
	else {
		check = 0;
	}
	
	setupAnim(f, f1, f2, f3, f4, f5);
	badMain.render(this, f5);
}

void ModelBackpack::setRotation(ModelPart model, Vec3 vec){
	//model.rotateAngleX = vec.x
	//model.rotateAngleY = vec.y
	//model.rotateAngleZ = vec.z
}

void ModelBackpack::setupAnim(float f, float f1, float f2, float f3, float f4, float f5){
	((HumanoidModel*) this)->setupAnim(f, f1, f2, f3, f4, f5);
	if(check == 1) {
		//set rotateAngleX to 0.5F
	}
	
	else {
		//set rotateAngleX to 0.0F
	}
}