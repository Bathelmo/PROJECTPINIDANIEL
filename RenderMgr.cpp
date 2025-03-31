#include "RenderMgr.h"

RenderMgr::RenderMgr(DisplayManager* mgr_) {
	display = mgr_;
}

RenderMgr::~RenderMgr() {
	display = nullptr;
}

void RenderMgr::init() {

}

void RenderMgr::render() {	
	
}

void RenderMgr::clear() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderMgr::cleanup() {

}