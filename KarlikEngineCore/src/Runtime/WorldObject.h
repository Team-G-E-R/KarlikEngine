#pragma once
#include <string>
#include <vector>

class Script;

class WorldObject
{
public:
	WorldObject() = default;
	WorldObject(const std::string uuid);
	virtual ~WorldObject() = default;

	const std::string& GetUUID() { return uuid; }

private:
	const std::string uuid;
	std::vector<std::shared_ptr<Script>> scripts;
};
