#pragma once
#include "GraphicsBase.h"
#include <string_view>
#include <Runtime/Runtime.h>

class SDLWindow {
public:
	SDLWindow() = default;
	~SDLWindow() { Close(); }

	void Initialize(std::string_view name, int w, int h);
	void Startup();
	void Close();

protected:
	virtual void InitializeGraphics() = 0;
	virtual void OnUpdate() = 0;

protected:
	bool running = true;
	std::unique_ptr<GraphicsBase> graphics = nullptr;
	std::unique_ptr<Runtime> runtime = nullptr;
	SDL_Window* window = nullptr;

private:
	void Run();

};
