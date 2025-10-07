#include "GraphicsBase.h"
#include "Addon/BasicAddons.h"

GraphicsBase::GraphicsBase(RendererType type) : rendererType(type) {
	BasicAddons::InitializeAddons();
}

GraphicsBase::~GraphicsBase()
{
	AddonRegistry::Instance().Clear();
}

void GraphicsBase::Startup(SDL_Window* window)
{
	this->window = window;
	Startup();
	PostStartup();
}

void GraphicsBase::PostStartup()
{
	for (int i = 0; i < addons.size(); i++) {
		addons[i]->Initialize();
	}
}

void GraphicsBase::Render()
{
	PreRender();
	RenderObjects();
	RenderAddons();
	PostRender();
}

void GraphicsBase::AddAddon(std::unique_ptr<AddonBase> addon)
{
	addon->SetGraphicsBase(this);
	addons.push_back(std::move(addon));
}

void GraphicsBase::RenderAddons()
{
	for (auto& addon : addons) {
		addon->Render();
	}
}