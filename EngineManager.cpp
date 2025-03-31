#include "EngineManager.h"

EngineManager::EngineManager() : 
	isRunning(false), fps(0), window(nullptr), logic(nullptr) {

}

EngineManager::~EngineManager() {
	if (window) {
		delete window;
		window = nullptr;
	}
}

void EngineManager::init() {
	glfwSetErrorCallback(errorCallBack);
	window = new DisplayManager();
	window->createDisplay("me gusta la papi", 800, 600);

}

void EngineManager::start() {
	if (isRunning) {
		std::cerr << "engine manager is already up!" << std::endl;
		return;
	}

	run();
}

void EngineManager::stop() {
	window->closeDisplay();
	isRunning = false;
}

void EngineManager::run() {
	isRunning = true;
	auto lastTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()).count();

	int frames = 0;
	int frameCounter = 0;
	double unprocessedTime = 0;

	while (isRunning) {
		bool canRender = false;
		auto startTime = std::chrono::duration_cast<std::chrono::nanoseconds>(
			std::chrono::high_resolution_clock::now().time_since_epoch()).count();	
		long passedTime = startTime - lastTime;
		lastTime = startTime;

		unprocessedTime += passedTime / (double)NANOSECOND;
		frameCounter += passedTime;

		input();

		// INPUT
		while (unprocessedTime > frametime) {

			canRender = true;
			unprocessedTime -= frametime;

			if (window->windowShouldClose()) {
				stop();
			}

			if (frameCounter >= NANOSECOND) {
				setFps(frames);
				frames = 0;
				frameCounter = 0;
			}

			if (canRender) {
				update();
				render();
				std::cout << "FPS: " << getFps() << std::endl;
				frames++;
			}
		}
	}
	clear();

}

void EngineManager::setLogic(ILogic* logic_) {
	logic = logic_;
}

void EngineManager::update() {
	logic->update();
	window->updateDisplay();
}

void EngineManager::input() {
	logic->input();
}

void EngineManager::render() {
	logic->render();
}

void EngineManager::clear() {
	window->closeDisplay();
	//errorCallBack.clear();
	logic->clear();
}