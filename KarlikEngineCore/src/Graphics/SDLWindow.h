#pragma once
#include "GraphicsBase.h"
#include <string_view>
#include <Runtime/Runtime.h>
#include <Scripting/Scripting.h>

class SDLWindow {
public:
	SDLWindow() = default;
	~SDLWindow() { Close(); }

	void Initialize(std::string_view name, int w, int h);
	void Startup();
	void Close();

protected:
	virtual void PostInitialize() = 0;
	virtual void OnUpdate() = 0;

protected:
	bool running = true;
	std::unique_ptr<GraphicsBase> graphics = nullptr;
	std::unique_ptr<Runtime> runtime = nullptr;
	std::unique_ptr<Scripting> scripting = nullptr;
	SDL_Window* window = nullptr;

private:
	void Run();

};
