#include "ImGuiAddonBase.h"

void ImGuiAddonBase::Initialize()
{
	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	io = &ImGui::GetIO(); (void)*io;
	io->ConfigFlags = ImGuiConfigFlags_NavEnableKeyboard | ImGuiConfigFlags_NavEnableGamepad | ImGuiConfigFlags_DockingEnable;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// ImGui::StyleColorsLight();
}

void ImGuiAddonBase::Render()
{
	PreRender();
	ImGui_ImplSDL3_NewFrame();
	ImGui::NewFrame();

	for (int i = 0; i < renderParts.size(); i++) {
		renderParts[i]->Render();
	}

	ImGui::Render();
	PostRender();
}

void ImGuiAddonBase::AddRenderPart(std::unique_ptr<ImGuiRenderPart> part) {
	renderParts.push_back(std::move(part));
}
