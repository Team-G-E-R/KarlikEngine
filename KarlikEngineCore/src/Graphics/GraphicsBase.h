#pragma once
#include <SDL3/SDL.h>
#include <memory>

class GraphicsBase {
public:
	GraphicsBase() = default;
	~GraphicsBase() = default;

	virtual void Initialize() = 0;
	virtual void Startup(SDL_Window* window) { this->window = window; }
	virtual void Render() = 0;
	virtual unsigned long long GetWindowFlag() = 0;
protected:
	SDL_Window* window = nullptr;
};
