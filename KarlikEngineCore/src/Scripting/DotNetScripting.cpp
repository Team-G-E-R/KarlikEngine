#include "DotNetScripting.h"
#include "DotNetScript.h"
#include "Utils/UUIDGenerator.h"

#include <iostream>
static void ExceptionCallback(std::string_view InMessage)
{
	std::cout << "Unhandled native exception: " << InMessage << std::endl;
}

DotNetScripting::DotNetScripting()
{
	Coral::HostSettings settings;
	settings.CoralDirectory = "";
	settings.ExceptionCallback = ExceptionCallback;

	if (hostInstance.Initialize(settings) != Coral::CoralInitStatus::Success)
	{
		std::cerr << "Failed to initialize Coral HostInstance" << std::endl;
		return;
	}

	ReloadAssembly();
}

std::shared_ptr<Script> DotNetScripting::CreateScriptProcess(const std::string& name, WorldObject* worldObject)
{
	std::shared_ptr<DotNetScript> script = std::make_shared<DotNetScript>(uuid_generator::generate_uuid_v4(), name, this, worldObject);
	scripts.push_back(script);
	scriptsToStart.push_back(script);
	return script;
}

Coral::Type* DotNetScripting::GetTypeByName(const std::string& name)
{
	auto iter = typesByNames.find(name);
	return iter != typesByNames.end() ? iter->second : nullptr;
}

void DotNetScripting::ReloadAssembly()
{
	scripts.clear();
	scriptsToStart.clear();
	types.clear();
	typesByNames.clear();

	if (loadContext)
	{
		hostInstance.UnloadAssemblyLoadContext(*loadContext);
		loadContext.reset();
	}

	loadContext = std::make_unique<Coral::AssemblyLoadContext>(
		hostInstance.CreateAssemblyLoadContext("MainContext")
	);

	const std::string assemblyPath = "KarlikEngineScriptingCore.dll";
	auto& assembly = loadContext->LoadAssembly(assemblyPath);

	types = assembly.GetTypes();
	for (auto type : types)
	{
		typesByNames[type->GetFullName()] = type;
	}

	std::cout << "[DotNetScripting] Reloaded assembly: " << assemblyPath << std::endl;
}

static int i = 0;
void DotNetScripting::OnUpdate()
{
	for (auto& script : scriptsToStart) {
		script->OnStart();
	}
	scriptsToStart.clear();

	for (auto& script : scripts) {
		script->OnUpdate();
	}
	
	i++;
	if (i == 5000) {
		ReloadAssembly();
		i = 0;
	}
}

void DotNetScripting::OnPhysicsUpdate()
{
	for (size_t i = 0; i < scripts.size(); i++)
	{
		scripts[i]->OnPhysicsUpdate();
	}
}
