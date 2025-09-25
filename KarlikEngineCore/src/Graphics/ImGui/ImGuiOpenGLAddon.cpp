#include "ImGuiOpenGLAddon.h"
#include "Graphics/OpenGLGraphics.h"

void ImGuiOpenGLAddon::Initialize()
{
	ImGuiAddonBase::Initialize();

	auto graphics = (OpenGLGraphics*)graphicsBase;

	ImGui_ImplSDL3_InitForOpenGL(graphics->GetWindow(), graphics->GetContext());
	ImGui_ImplOpenGL3_Init("#version 150");
}

void ImGuiOpenGLAddon::PreRender()
{
	ImGui_ImplOpenGL3_NewFrame();
}

void ImGuiOpenGLAddon::PostRender()
{
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
}
