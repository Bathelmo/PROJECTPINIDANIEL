#include "EngineManager.h"
#include "TestGame.h"

int main() {
	
	EngineManager* engine = new EngineManager();

	engine->init();

	RenderMgr* renderer = new RenderMgr(engine->window);
	ILogic* logic = new TestGame(renderer);

	engine->setLogic(logic);
	engine->start();

	delete logic;
	delete engine;

	return 0;
}