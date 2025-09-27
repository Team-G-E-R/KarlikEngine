#pragma once
#include "Graphics/ImGui/ImGuiRenderPart.h"
#include <imgui.h>

class TestRenderPart : public ImGuiRenderPart {
public:
	void ShowDockSpace()
	{
		ImGuiWindowFlags window_flags = ImGuiWindowFlags_MenuBar | ImGuiWindowFlags_NoDocking;
		const ImGuiViewport* viewport = ImGui::GetMainViewport();
		ImGui::SetNextWindowPos(viewport->WorkPos);
		ImGui::SetNextWindowSize(viewport->WorkSize);
		ImGui::SetNextWindowViewport(viewport->ID);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowRounding, 0.0f);
		ImGui::PushStyleVar(ImGuiStyleVar_WindowBorderSize, 0.0f);
		window_flags |= ImGuiWindowFlags_NoTitleBar | ImGuiWindowFlags_NoCollapse |
			ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMove |
			ImGuiWindowFlags_NoBringToFrontOnFocus | ImGuiWindowFlags_NoNavFocus;

		ImGui::Begin("DockSpace Demo", nullptr, window_flags);
		ImGui::PopStyleVar(2);

		// Dockspace node
		ImGuiID dockspace_id = ImGui::GetID("MyDockspace");
		ImGui::DockSpace(dockspace_id, ImVec2(0.0f, 0.0f), ImGuiDockNodeFlags_PassthruCentralNode);

		ImGui::End();
	}

	void Render() override{
		ShowDockSpace();

		// Your GUI code here
		ImGui::Begin("Hello, world!");
		ImGui::Text("This is a simple SDL3 + OpenGL3 example");
		ImGui::End();
		ImGui::Begin("Hello, world2!");
		ImGui::Text("This is a simple SDL3 + OpenGL3 example");
		ImGui::End();
	}
};
