#pragma once
#include "GraphicsBase.h"

class OpenGLGraphics : public GraphicsBase {
public:
	OpenGLGraphics() : GraphicsBase(RendererType::OpenGL) {}
	~OpenGLGraphics() {}

	void Initialize() override;
	void Startup() override;
	void ProcessEvents(SDL_Event event) override;
	unsigned long long GetWindowFlag() override;

	SDL_GLContext GetContext() { return context; }

protected:
	virtual void PreRender() override;
	virtual void RenderObjects() override;
	virtual void PostRender() override;

protected:
	SDL_GLContext context = nullptr;
};