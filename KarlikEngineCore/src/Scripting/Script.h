#pragma once

class Scripting;

class Script {
public:
	Script(const std::string& uuid, const std::string& name, const Scripting* scripting);
	virtual ~Script() = default;

	virtual void OnStart() = 0;
	virtual void OnUpdate() = 0;
	virtual void OnPhysicsUpdate() = 0;

private:
	const std::string uuid;
	const std::string name;
	const Scripting* scripting;
};
