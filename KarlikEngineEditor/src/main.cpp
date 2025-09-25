#include "Graphics/SDLWindow.h"
#include "Graphics/OpenGLGraphics.h"
#include "Graphics/ImGui/ImGuiOpenGLAddon.h"
#include <Addon/AddonRegistry.h>
#include "ImGui/TestRenderPart.h"

void InitializeAddon() {
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

int main(int argc, char* argv[])
{
	InitializeAddon();

	std::unique_ptr<GraphicsBase> graphics = std::make_unique<OpenGLGraphics>();
	AddonRegistry::Instance().Create<ImGuiAddonBase>(graphics.get());

	auto imgui = graphics->GetAddonRaw<ImGuiAddonBase>();
	imgui->AddRenderPart(std::make_unique<TestRenderPart>());

	std::unique_ptr<SDLWindow> window = std::make_unique<SDLWindow>(std::move(graphics));
	window->Initialize("KarlikEngine - Editor", 920, 780);
	window->Startup();
	return 0;
}
