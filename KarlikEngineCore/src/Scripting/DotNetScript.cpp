#include "DotNetScript.h"
#include "DotNetScripting.h"

DotNetScript::DotNetScript(const std::string& uuid, const std::string& name, Scripting* scripting, WorldObject* worldObject) 
	: Script(uuid, name, scripting, worldObject)
{
	DotNetScripting* dotNetScripting = static_cast<DotNetScripting*>(scripting);
	auto baseClass = dotNetScripting->GetTypeByName(name);

	if (baseClass == nullptr) {
		// Class not found
		return;
	}

	cachedMethods = DotNetCache::RetrieveExistingMethods(name, baseClass);

	instance = baseClass->CreateInstance();
	if (!instance.IsValid()) 
	{
		// Log errors. Do what?
		return;
	}
}

DotNetScript::~DotNetScript()
{
	if (instance.IsValid()) {
		instance.Destroy();
	}
}

void DotNetScript::OnStart()
{
	InvokeIfValid(ScriptMethods::Start);
}

void DotNetScript::OnUpdate()
{
	InvokeIfValid(ScriptMethods::Update);
}

void DotNetScript::OnPhysicsUpdate()
{
	InvokeIfValid(ScriptMethods::PhysicsUpdate);
}

bool DotNetScript::HasMethod(const std::string& methodName) const {
	return cachedMethods->names.contains(methodName);
}

void DotNetScript::InvokeIfValid(std::string_view methodName)
{
	if (HasMethod(std::string(methodName)) && runInEditor)
		instance.InvokeMethod(std::string(methodName));
}
