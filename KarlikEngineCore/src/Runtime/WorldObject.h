#pragma once
#include <string>
#include <vector>

class Scripting;
class Script;

class WorldObject
{
public:
	WorldObject(Scripting* scripting, const std::string uuid, std::string name);
	virtual ~WorldObject() = default;

	const std::string& GetUUID() { return uuid; }

	std::shared_ptr<Script> CreateScript(const std::string& name);
	void RemoveScript(const std::string& name);
	bool ContainsScript(const std::string& name);
	void AttachScript(std::shared_ptr<Script> script); // only adds to container
	void DetachScript(std::shared_ptr<Script> script); // only removes from container

	void ClearScripts();

public:
	std::string name;

private:
	const std::string uuid;
	Scripting* scripting;
	std::vector<std::shared_ptr<Script>> scripts;
};
