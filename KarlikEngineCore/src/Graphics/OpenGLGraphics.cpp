#include "OpenGLGraphics.h"

void OpenGLGraphics::Initialize()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
}

void OpenGLGraphics::Startup(SDL_Window* window)
{
	GraphicsBase::Startup(window);

	SDL_GLContext context = SDL_GL_CreateContext(window);
	if (!context) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create OpenGL context\n");
		return;
	}

	if (!SDL_GL_MakeCurrent(window, context)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not make OpenGL context current\n");
		return;
	}

	glewInit();
	
	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	// 60 fps?
	//SDL_GL_SetSwapInterval(1);
}

void OpenGLGraphics::Render()
{
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	SDL_GL_SwapWindow(window);
}

unsigned long long OpenGLGraphics::GetWindowFlag()
{
	return SDL_WINDOW_OPENGL;
}
