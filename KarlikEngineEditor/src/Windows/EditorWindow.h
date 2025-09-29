#pragma once
#include "Graphics/SDLWindow.h"

class EditorWindow : public SDLWindow {
protected:
	void PostInitialize() override;
	void OnUpdate() override;
};
