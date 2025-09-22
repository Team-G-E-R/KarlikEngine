#include "SDLWindow.h"

void SDLWindow::Initialize(std::string_view name, int w, int h)
{
	if (!SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL");
	}

	graphics->Initialize();

	window = SDL_CreateWindow(name.data(), w, h, graphics->GetWindowFlag());
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
	while (running) {
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			// etc...
		}

		graphics->Render();
	}

	SDL_Quit();
}
