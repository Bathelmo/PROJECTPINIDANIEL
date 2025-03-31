#pragma once
#include "DisplayManager.h"

class RenderMgr
{
public:
	RenderMgr(DisplayManager* mgr_);
	~RenderMgr();

	void init();
	void render();
	void clear();
	void cleanup();

	DisplayManager* display;
};

