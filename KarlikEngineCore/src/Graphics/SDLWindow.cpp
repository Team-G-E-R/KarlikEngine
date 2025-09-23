#include "SDLWindow.h"

void SDLWindow::Initialize(std::string_view name, int w, int h)
{
	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s", SDL_GetError());
		return;
	}

	graphics->Initialize();

	window = SDL_CreateWindow(name.data(), SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED, w, h, graphics->GetWindowFlag());
	if (window == NULL) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create window: %s\n", SDL_GetError());
		return;
	}
}

void SDLWindow::Startup()
{
	graphics->Startup(window);
	Run();
}

void SDLWindow::Close()
{
	running = false;
}

void SDLWindow::Run()
{
	SDL_Event event;
	Uint32 lastTime = SDL_GetTicks64();
	int frames = 0;

	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				running = false;
			}
			// etc...
		}

		graphics->Render();

		frames++;
		Uint32 currentTime = SDL_GetTicks64();
		if (currentTime - lastTime >= 1000) {
			//printf("FPS: %d\n", frames);
			frames = 0;
			lastTime = currentTime;
		}
	}

	SDL_Quit();
}
