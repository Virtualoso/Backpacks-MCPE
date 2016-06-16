#pragma once

class AbstractScreenSetupCleanupStrategy {
public:
	virtual ~AbstractScreenSetupCleanupStrategy();
	virtual void setupScreen(ScreenContext&);
	virtual void cleanupScreen(ScreenContext&);
	virtual int getNumberOfRenderPasses() const;
};