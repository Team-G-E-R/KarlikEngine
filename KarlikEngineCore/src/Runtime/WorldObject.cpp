#include "WorldObject.h"
#include "Scripting/Scripting.h"

WorldObject::WorldObject(Scripting* scripting, const std::string uuid, std::string name) : scripting(scripting), uuid(uuid), name(name)
{
}

void WorldObject::ClearScripts()
{
	scripts.clear();
}

std::shared_ptr<Script> WorldObject::CreateScript(const std::string& name)
{
	return scripting->CreateScript(name, this);
}

void WorldObject::RemoveScript(const std::string& name)
{
	for (auto script : scripts) {
		if (name == script->GetName()) {
			scripting->RemoveScript(script);
		}
	}
}

bool WorldObject::ContainsScript(const std::string& name)
{
	for (auto script : scripts) {
		if (name == script->GetName()) {
			return true;
		}
	}
	return false;
}

void WorldObject::AttachScript(std::shared_ptr<Script> script)
{
	scripts.push_back(script);
}

void WorldObject::DetachScript(std::shared_ptr<Script> script)
{
	scripts.erase(std::find(scripts.begin(), scripts.end(), script));
}
