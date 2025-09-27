#pragma once
#include "Graphics/SDLWindow.h"

class EditorWindow : public SDLWindow {
protected:
	void InitializeGraphics() override;
	void OnUpdate() override;
};
