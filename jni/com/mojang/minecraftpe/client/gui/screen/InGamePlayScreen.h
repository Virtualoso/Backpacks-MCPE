#pragma once

#include "Screen.h"

class InGamePlayScreen : public Screen
{
public:

		InGamePlayScreen(MinecraftClient&);
		
		virtual ~InGamePlayScreen();
		virtual void _init(int, int);
		virtual void onFocusGained();
		virtual void tick(int, int);
		virtual void applyInput(float);
		virtual void render(ScreenContext&);
		virtual void handleDirection(DirectionId, float, float);
		virtual void renderGameBehind() const;
		virtual void isModal() const;
		virtual void isShowingMenu() const;
		virtual void shouldStealMouse() const;
		virtual void renderOnlyWhenTopMost() const;
		virtual void getScreenName();
		virtual void getSendTelemetry();
		virtual void _renderLevelPrep(float);
		virtual void _renderLevel(float);
		virtual void _preLevelRender(ScreenContext&);
		virtual void _postLevelRender(ScreenContext&);
		virtual void _renderedFramedItems(Vec3, LevelRenderer&, Entity&, float);
		virtual void _updateFreeformPickDirection(float, Vec3&, Vec3&);
		virtual void _saveMatrices();
		virtual void _renderFirstPerson3DObjects(LevelRenderer&, float);
		virtual void _renderTransparentFirstPerson3DObjects(LevelRenderer&, float);
		virtual void _renderItemInHand(Player&, float);
		virtual void _shouldClipLiquids() const;
		virtual void _getThirdPersonSetting();
		virtual void _isHoloViewer() const;
		virtual void _prepareCuller(FrustumData&, FrustumData&);
		virtual void _localPlayerTurned(float);
		virtual void _getPickRange();
		virtual void _shouldPushHUD();
};