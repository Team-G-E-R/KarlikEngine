#include "TestRenderPart.h"
#include "Runtime/Runtime.h"
#include <imgui.h>
#include <fmt/format.h>

void TestRenderPart::ShowDockSpace()
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

struct ScriptA
{
    std::string name;
    std::string path;
    bool enabled = false;
    float executionTime = 0.0f;
};

void TestRenderPart::Render(Runtime* runtime, GraphicsBase* graphicsBase)
{
	ShowDockSpace();

	World* world = runtime->GetWorldActive();
	auto& worldObjects = world->GetWorldObjects();

	ImGui::Begin("World Objects");
	for (int i = 0; i < worldObjects.size(); i++) {
		ImGui::PushID(i);
		ImGui::BeginChild(
			("ObjectChild" + std::to_string(i)).c_str(),
			ImVec2(0, 100),
			true,
			ImGuiWindowFlags_None
		);

		if (ImGui::BeginDragDropSource(ImGuiDragDropFlags_None)) {
			ImGui::SetDragDropPayload("SelectedWorldObject", worldObjects[i].get(), sizeof(WorldObject*));
			ImGui::Text(fmt::format("Dragging Item: {} ({})", worldObjects[i]->name, worldObjects[i]->GetUUID()).c_str());
			ImGui::EndDragDropSource();
		}

		ImGui::SeparatorText(fmt::format("{} ({})", worldObjects[i]->name, worldObjects[i]->GetUUID()).c_str());
		ImGui::Text("Additional object data...");

		ImGui::EndChild();
		ImGui::PopID();

		ImGui::Spacing();
	}
	ImGui::End();

	//if (ImGui::BeginDragDropTarget()) {
	//	if (const ImGuiPayload* payload = ImGui::AcceptDragDropPayload("SelectedWorldObject")) {
	//		IM_ASSERT(payload->DataSize == sizeof(WorldObject*));
	//		WorldObject* received_data = (WorldObject*)payload->Data;
	//		ImGui::Text("Dropped data: %d", received_data->name);
	//	}
	//	ImGui::EndDragDropTarget();
	//}
	//ImGui::Text("AAAA");
}
