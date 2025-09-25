#include "OpenGLGraphics.h"
#include "imgui.h"
#include "imgui_impl_sdl3.h"
#include "imgui_impl_opengl3.h"

void OpenGLGraphics::Initialize()
{
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 4);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 6);
}

void OpenGLGraphics::Startup()
{
	context = SDL_GL_CreateContext(window);
	if (!context) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not create OpenGL context\n");
		return;
	}

	if (!SDL_GL_MakeCurrent(window, context)) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Could not make OpenGL context current\n");
		return;
	}

	glewExperimental = GL_TRUE; // Needed for modern OpenGL
	if (glewInit() != GLEW_OK) {
		SDL_LogError(SDL_LOG_CATEGORY_ERROR, "Failed to initialize GLEW\n");
		return;
	}

	printf("OpenGL version: %s\n", glGetString(GL_VERSION));
	printf("GLSL version: %s\n", glGetString(GL_SHADING_LANGUAGE_VERSION));

	// 0 = disable VSync, 1 = enable VSync, -1 = late swap tearing if supported
	SDL_GL_SetSwapInterval(0);
}

void OpenGLGraphics::ProcessEvents(SDL_Event event)
{
	ImGui_ImplSDL3_ProcessEvent(&event);
}

unsigned long long OpenGLGraphics::GetWindowFlag()
{
	return SDL_WINDOW_OPENGL;
}

void OpenGLGraphics::PreRender()
{	
	// render objects
	glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
}

void OpenGLGraphics::RenderObjects()
{

}

void OpenGLGraphics::PostRender()
{
	SDL_GL_SwapWindow(window);
}
