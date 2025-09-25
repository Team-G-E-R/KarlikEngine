#pragma once
#include <vector>
#include <memory>
#include "Addon/AddonBase.h"
#include "ImGuiRenderPart.h"
#include <imgui_impl_sdl3.h>

class ImGuiAddonBase : public AddonBase {
public:
	ImGuiAddonBase() {}

	virtual void Initialize() override;
	void Render() override;

	void AddRenderPart(std::unique_ptr<ImGuiRenderPart> part);

protected:
	virtual void PreRender() = 0;
	virtual void PostRender() = 0;

protected:
	std::vector<std::unique_ptr<ImGuiRenderPart>> renderParts;
	ImGuiIO* io = nullptr;
};
