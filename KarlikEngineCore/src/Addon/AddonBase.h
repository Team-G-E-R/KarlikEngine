#pragma once
#include <string>
#include <SDL3/SDL.h>

class GraphicsBase;

class AddonBase {
public:
	AddonBase() {}
	virtual ~AddonBase() = default;

	virtual void Initialize() = 0;
	virtual void Render() = 0;

	void SetGraphicsBase(GraphicsBase* graphicsBase) { this->graphicsBase = graphicsBase; }

protected:
	GraphicsBase* graphicsBase = nullptr;
};
