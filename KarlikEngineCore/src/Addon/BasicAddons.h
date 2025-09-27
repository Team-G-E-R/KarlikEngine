#pragma once
#include <memory>
#include "AddonRegistry.h"
#include <Graphics/ImGui/ImGuiOpenGLAddon.h>

namespace BasicAddons {
	static void InitializeAddons() {
		AddonRegistry::Instance().Register<ImGuiAddonBase>(
			[](GraphicsBase* graphics) -> std::unique_ptr<ImGuiAddonBase> {
				if (graphics->GetRendererType() == RendererType::OpenGL)
				{
					return std::make_unique<ImGuiOpenGLAddon>();
				}
				return nullptr;
			}
		);
	}
}
