#include "Scripting.h"

std::weak_ptr<Script> Scripting::CreateScript(const std::string& name, WorldObject* worldObject)
{
	auto script = CreateScriptProcess(name, worldObject);
	scripts.push_back(script);
	return script;
}

void Scripting::RemoveScript(std::shared_ptr<Script> script)
{
	scripts.erase(std::remove(scripts.begin(), scripts.end(), script), scripts.end());
}
