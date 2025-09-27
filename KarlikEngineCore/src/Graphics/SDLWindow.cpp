#include "SDLWindow.h"

void SDLWindow::Initialize(std::string_view name, int w, int h)
{
	if (!SDL_Init(SDL_INIT_VIDEO)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not initialize SDL: %s", SDL_GetError());
		return;
	}

	InitializeGraphics();

	graphics->Initialize();

	window = SDL_CreateWindow(name.data(), w, h, graphics->GetWindowFlag() | SDL_WINDOW_RESIZABLE);
	if (window == nullptr) {
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
	Uint32 lastTime = SDL_GetTicks();
	int frames = 0;

	while (running) {
		while (SDL_PollEvent(&event)) {
			graphics->ProcessEvents(event);
			if (event.type == SDL_EVENT_QUIT) {
				running = false;
			}
			// etc...
		}

		OnUpdate();
		graphics->Render();

		frames++;
		Uint32 currentTime = SDL_GetTicks();
		if (currentTime - lastTime >= 1000) {
			//printf("FPS: %d\n", frames);
			frames = 0;
			lastTime = currentTime;
		}
	}

	SDL_Quit();
}
