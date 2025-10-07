#pragma once
#include <memory>
#include "AddonRegistry.h"
#include <Graphics/ImGui/ImGuiOpenGLAddon.h>
#include <Runtime/Runtime.h>

namespace BasicAddons {
	static void InitializeAddons() {
		AddonRegistry::Instance().Register<ImGuiAddonBase>(
			[](GraphicsBase* graphics, Runtime* runtime) -> std::unique_ptr<ImGuiAddonBase> {
				if (graphics->GetRendererType() == RendererType::OpenGL)
				{
					return std::make_unique<ImGuiOpenGLAddon>(runtime);
				}
				return nullptr;
			}
		);
	}
}
