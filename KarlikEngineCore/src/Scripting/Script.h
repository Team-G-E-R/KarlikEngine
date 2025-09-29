#pragma once

class Scripting;
class WorldObject;

class Script {
public:
	Script(const std::string& uuid, const std::string& name, Scripting* scripting, WorldObject* worldObject);
	virtual ~Script() = default;

	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnPhysicsUpdate() = 0;

	bool runInEditor = false;

private:
	const std::string uuid;
	const std::string name;
	Scripting* scripting;
	WorldObject* worldObject;
};
