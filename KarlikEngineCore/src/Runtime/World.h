#pragma once
#include <string>
#include <vector>
#include <memory>
#include "WorldObject.h"

class World {
public:
	World(std::string uuid, std::string name) : uuid(std::move(uuid)), name(std::move(name)) {}
	virtual ~World() = default;

	WorldObject* CreateObject(std::string name = "");

public:
	const std::string uuid;
	const std::string name;

private:
	std::vector<std::unique_ptr<WorldObject>> worldObjects;
};
