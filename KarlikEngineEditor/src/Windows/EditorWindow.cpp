#include "EditorWindow.h"
#include "Graphics/OpenGLGraphics.h"
#include "Graphics/ImGui/ImGuiOpenGLAddon.h"
#include <Addon/AddonRegistry.h>
#include "../ImGui/TestRenderPart.h"
#include <Scripting/DotNetScripting.h>

void EditorWindow::PostInitialize()
{
	graphics = std::make_unique<OpenGLGraphics>();
	AddonRegistry::Instance().Create<ImGuiAddonBase>(graphics.get());

	auto imgui = graphics->GetAddonRaw<ImGuiAddonBase>();
	imgui->AddRenderPart(std::make_unique<TestRenderPart>());

	runtime = std::make_unique<Runtime>();
	scripting = std::make_unique<DotNetScripting>();

	World* world = runtime->CreateWorld();
	runtime->SetWorldActive(world);

	WorldObject* test = world->CreateObject("Test");
	auto script = scripting->CreateScript("Test", test);
	script.lock()->runInEditor = true;
}

void EditorWindow::OnUpdate()
{
	scripting->OnUpdate();
}
