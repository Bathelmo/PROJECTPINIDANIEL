#pragma once

#include "RenderMgr.h"
#include "ILogic.h"
#include "DisplayManager.h"
#include <chrono>

const static long NANOSECOND = 1000000000L;
const static int FRAMERATE = 144;

class EngineManager
{
public:
	EngineManager();
	~EngineManager();

	void init();

	void start();

	void stop();

	void run();

	void update();

	void input();

	void render();

	void clear();

	void setLogic(ILogic* logic);

	int getFps() {
		return fps;
	}

	void setFps(int fps_) {
		fps = fps_;
	}

	DisplayManager* window;


private:
	int fps;
	float frametime = 1.0 / FRAMERATE;

	bool isRunning;

	ILogic *logic;
	RenderMgr* renderer;

	GLFWerrorfun errorCallBack;
};

