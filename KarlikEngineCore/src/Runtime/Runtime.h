#pragma once
#include <string>
#include <unordered_map>
#include <memory>
#include "World.h"

class Runtime {
public:
	std::string CreateWorld(std::string_view name);
	bool DestroyWorld(const std::string& uuid);
	bool DestroyWorldByName(const std::string& name);
private:
	std::unordered_map<std::string, std::unique_ptr<World>> worlds;
};
