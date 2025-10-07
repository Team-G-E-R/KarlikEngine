#include "EditorWindow.h"
#include "Graphics/OpenGLGraphics.h"
#include "Graphics/ImGui/ImGuiOpenGLAddon.h"
#include <Addon/AddonRegistry.h>
#include "../ImGui/TestRenderPart.h"
#include <Scripting/DotNetScripting.h>

void EditorWindow::PostInitialize()
{
	graphics = std::make_unique<OpenGLGraphics>();

	auto scripting = std::make_unique<DotNetScripting>();
	runtime = std::make_unique<Runtime>(std::move(scripting));

	AddonRegistry::Instance().Create<ImGuiAddonBase>(graphics.get(), runtime.get());

	auto imgui = graphics->GetAddonRaw<ImGuiAddonBase>();
	imgui->AddRenderPart(std::make_unique<TestRenderPart>());

	World* world = runtime->CreateWorld();

	WorldObject* test = world->CreateObject("Test");
	auto script = test->CreateScript("Test");
	script->runInEditor = true;

	WorldObject* test2 = world->CreateObject("Test2");
	script = test2->CreateScript("Test");
	script->runInEditor = true;

	WorldObject* test3 = world->CreateObject("Test3");
	script = test3->CreateScript("Test");
	script->runInEditor = true;
}

void EditorWindow::OnUpdate()
{
	runtime->OnUpdate();
}
