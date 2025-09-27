#pragma once
#include <string>
#include <vector>
#include <memory>
#include "WorldObject.h"

class World {
public:
	World(std::string_view uuid, std::string_view name) : uuid(uuid), name(name) {}
	virtual ~World() = default;

	WorldObject* CreateObject(std::string name = "");

public:
	const std::string uuid;
	const std::string name;

private:
	std::vector<std::unique_ptr<WorldObject>> worldObjects;
};
