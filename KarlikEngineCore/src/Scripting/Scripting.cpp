#include "Scripting.h"
#include "Runtime/WorldObject.h"

std::shared_ptr<Script> Scripting::CreateScript(const std::string& name, WorldObject* worldObject)
{
	if (worldObject->ContainsScript(name)) {
		return nullptr;
	}

	auto script = CreateScriptProcess(name, worldObject);
	worldObject->AttachScript(script);
	scripts.push_back(script);
	return script;
}

void Scripting::RemoveScript(std::shared_ptr<Script> script)
{
	script->worldObject->DetachScript(script);
	scripts.erase(std::remove(scripts.begin(), scripts.end(), script), scripts.end());
}
