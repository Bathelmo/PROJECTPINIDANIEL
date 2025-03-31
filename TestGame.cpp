#include "TestGame.h"

TestGame::TestGame(RenderMgr* renderer) : ILogic(renderer){

}

TestGame::~TestGame() {

}

void TestGame::init() {
	renderer->init();
}

void TestGame::render() {
	if (renderer->display->isResize()) {
		glViewport(0, 0, renderer->display->getWidth(), renderer->display->getHeight());
		renderer->display->setResize(true);
	}

	glClearColor(colour, colour, colour, 1.0f);
	renderer->clear();
	//renderer->render();
}

void TestGame::update() {
	colour += direction * 0.01f;
	if (colour > 1)
		colour = 1.0f;
	else if (colour <= 0)
		colour = 0.0f;
}

void TestGame::input() {
	if (renderer->display->isKeyPressed(GLFW_KEY_UP))
		direction = 1;
	else if (renderer->display->isKeyPressed(GLFW_KEY_DOWN))
		direction = -1;
	else
		direction = 0;
}

void TestGame::clear() {
	renderer->clear();
}