#pragma once

#include <string>

class ScreenContext;

class AbstractScreenSetupCleanupStrategy {
public:

	void cleanupScreen(ScreenContext);
	int getNumberOfRenderPasses() const;
};