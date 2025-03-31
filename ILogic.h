#pragma once
#include "RenderMgr.h"

class ILogic
{
public:
	ILogic(RenderMgr* renderer);
	virtual ~ILogic();
public:
	virtual void init() = 0;
	virtual void render() = 0;
	virtual void update() = 0;
	virtual void input() = 0 ;
	virtual void clear() = 0;

	RenderMgr* renderer;
};

