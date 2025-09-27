#include "EditorWindow.h"
#include "Graphics/OpenGLGraphics.h"
#include "Graphics/ImGui/ImGuiOpenGLAddon.h"
#include <Addon/AddonRegistry.h>
#include "../ImGui/TestRenderPart.h"

#include <Coral/HostInstance.hpp>
#include <Coral/GC.hpp>
#include <Coral/Array.hpp>
#include <Coral/Attribute.hpp>

void EditorWindow::InitializeGraphics()
{
	graphics = std::make_unique<OpenGLGraphics>();
	AddonRegistry::Instance().Create<ImGuiAddonBase>(graphics.get());

	auto imgui = graphics->GetAddonRaw<ImGuiAddonBase>();
	imgui->AddRenderPart(std::make_unique<TestRenderPart>());

	Coral::HostSettings settings =
	{
		.CoralDirectory = "",
		.ExceptionCallback = nullptr
	};
	Coral::HostInstance hostInstance;
	hostInstance.Initialize(settings);
}

void EditorWindow::OnUpdate()
{
}
