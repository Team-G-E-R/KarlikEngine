#pragma once

class Runtime;
class GraphicsBase;

class ImGuiRenderPart {
public:
	virtual void Render(Runtime* runtime, GraphicsBase* graphics) = 0;
};
