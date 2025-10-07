#pragma once
#include <string>
#include <vector>
#include <memory>
#include "WorldObject.h"
#include "Scripting/Scripting.h"

class World {
public:
	World(Scripting* scripting, std::string uuid, std::string name) : scripting(scripting), uuid(std::move(uuid)), name(std::move(name)) {}
	virtual ~World() = default;

	WorldObject* CreateObject(std::string name = "");
	WorldObject* GetObjectByName(const std::string& name);

public:
	const std::string uuid;
	const std::string name;

private:
	Scripting* scripting;
	std::vector<std::unique_ptr<WorldObject>> worldObjects;
};
