#pragma once
#include <memory>
#include "Script.h"

class Scripting {
public:
	virtual ~Scripting() = default;

	std::weak_ptr<Script> CreateScript(const std::string& name, WorldObject* worldObject);
	void RemoveScript(std::shared_ptr<Script> script);

	virtual void ReloadAssembly() = 0; // Call this only if you cached all current variables and ready to make all scripts null

	virtual void OnUpdate() = 0;
	virtual void OnPhysicsUpdate() = 0;

protected:
	virtual std::shared_ptr<Script> CreateScriptProcess(const std::string& name, WorldObject* worldObject) = 0;

protected:
	std::vector<std::shared_ptr<Script>> scripts;
	std::vector<std::shared_ptr<Script>> scriptsToStart;
};
