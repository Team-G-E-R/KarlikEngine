#include "Windows/EditorWindow.h"
#include "Addon/BasicAddons.h"
#include "ImGui/TestRenderPart.h"

int main(int argc, char* argv[])
{
	BasicAddons::InitializeAddons();

	std::unique_ptr<EditorWindow> window = std::make_unique<EditorWindow>();
	window->Initialize("KarlikEngine - Editor", 920, 780);
	window->Startup();

	return 0;
}
