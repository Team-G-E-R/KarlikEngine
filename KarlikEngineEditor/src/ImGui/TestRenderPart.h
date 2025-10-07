#pragma once
#include "Graphics/ImGui/ImGuiRenderPart.h"

class TestRenderPart : public ImGuiRenderPart {
public:
	void ShowDockSpace();
	void Render(Runtime* runtime, GraphicsBase* graphicsBase) override;
};
