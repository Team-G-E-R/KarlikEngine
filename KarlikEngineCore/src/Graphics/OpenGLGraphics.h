#pragma once
#include "GraphicsBase.h"

class OpenGLGraphics : public GraphicsBase {
public:
	OpenGLGraphics() {}
	~OpenGLGraphics() {}

	void Initialize() override;
	void Startup(SDL_Window* window) override;
	void Render() override;
	unsigned long long GetWindowFlag() override;

private:

};