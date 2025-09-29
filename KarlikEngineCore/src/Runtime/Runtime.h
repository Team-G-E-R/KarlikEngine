#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "World.h"

class Runtime {
public:
	World* CreateWorld(const std::string& name = "");
	void SetWorldActive(World* world);
	World* GetWorldActive();
	bool DestroyWorld(const std::string& uuid);
	bool DestroyWorldByName(const std::string& name);
private:
	std::unordered_map<std::string, std::unique_ptr<World>> worlds = std::unordered_map<std::string, std::unique_ptr<World>>();
	World* activeWorld = nullptr;
};
