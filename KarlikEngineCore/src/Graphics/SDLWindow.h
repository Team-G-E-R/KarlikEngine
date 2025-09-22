#pragma once
#include "SDL3/SDL.h"
#include "GraphicsBase.h"

class SDLWindow {
public:
	SDLWindow(std::unique_ptr<GraphicsBase> graphics) { this->graphics = std::move(graphics); }
	~SDLWindow() { Close(); }

	void Initialize(std::string_view name, int w, int h);
	void Startup();
	void Close();

protected:
	bool running = true;

private:
	void Run();

private:	
	std::unique_ptr<GraphicsBase> graphics;
	SDL_Window* window = nullptr;
};