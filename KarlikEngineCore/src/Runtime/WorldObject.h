#pragma once
#include <string>
#include <vector>

class Script;

class WorldObject
{
public:
	WorldObject(const std::string uuid, std::string name = "");
	virtual ~WorldObject() = default;

	const std::string& GetUUID() { return uuid; }

public:
	std::string name;

private:
	const std::string uuid;
	std::vector<std::shared_ptr<Script>> scripts;
};
