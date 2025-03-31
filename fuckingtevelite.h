#pragma once
#include "ILogic.h"
class TestGame :
	public ILogic
{
public:
	TestGame(RenderMgr* renderer);
	~TestGame();

public:
	virtual void init();
	virtual void render();
	virtual void update();
	virtual void input();
	virtual void clear();

private:
	int direction = 0;
	float colour = 0.0f;
};

