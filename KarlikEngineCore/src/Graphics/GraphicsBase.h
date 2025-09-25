#pragma once
#include <SDL3/SDL.h>
#include <memory>
#include <vector>
#include <string>
#include "Addon/AddonBase.h"

enum class RendererType : uint8_t {
	None = 0,
	OpenGL = 1,
	DirectX = 2,
	Vulkan = 3
};

class GraphicsBase {
public:
	GraphicsBase(RendererType type) : rendererType(type) {}
	~GraphicsBase() = default;

	virtual void Initialize() = 0;
	void Startup(SDL_Window* window);
	virtual void ProcessEvents(SDL_Event event) = 0;
	virtual unsigned long long GetWindowFlag() = 0;
	void Render();

	void AddAddon(std::unique_ptr<AddonBase> addon);

	template<typename T>
	T* GetAddonRaw() {
		for (auto& addon : addons) {
			if (auto ptr = dynamic_cast<T*>(addon.get())) {
				return ptr;
			}
		}
		return nullptr;
	}

	const RendererType GetRendererType() const { return rendererType; }
	SDL_Window* GetWindow() { return window; }

protected:
	virtual void Startup() = 0;
	void PostStartup();

	virtual void PreRender() = 0;
	virtual void RenderObjects() = 0;
	virtual void PostRender() = 0;

	virtual void RenderAddons();

protected:
	std::vector<std::unique_ptr<AddonBase>> addons;
	const RendererType rendererType;
	SDL_Window* window = nullptr;
};
