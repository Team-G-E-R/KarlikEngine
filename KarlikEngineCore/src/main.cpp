#include "Graphics/SDLWindow.h"
#include "Graphics/OpenGLGraphics.h"
#include <iostream>

int main(int argc, char* argv[])
{
	std::unique_ptr<GraphicsBase> graphics = std::make_unique<OpenGLGraphics>();
	std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>(std::move(graphics));
	window->Initialize("Test", 920, 780);
	window->Startup();
	return 0;
}
