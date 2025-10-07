#pragma once
#include "ImGuiAddonBase.h"
#include <imgui_impl_opengl3.h>

class ImGuiOpenGLAddon : public ImGuiAddonBase
{
public:
	ImGuiOpenGLAddon() {}
	~ImGuiOpenGLAddon();

	void Initialize() override;

protected:
	void PreRender() override;
	void PostRender() override;
};
