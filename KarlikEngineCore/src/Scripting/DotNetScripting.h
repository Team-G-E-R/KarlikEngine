#include "Scripting.h"
#include <Coral/HostInstance.hpp>
#include <Coral/Array.hpp>
#include <Coral/Attribute.hpp>

class DotNetScripting : public Scripting {
public:
	DotNetScripting();
	Coral::Type* GetTypeByName(const std::string& name);

	void ReloadAssembly() override;

	void OnUpdate() override;
	void OnPhysicsUpdate() override;

protected:
	std::shared_ptr<Script> CreateScriptProcess(const std::string& name, WorldObject* worldObject) override;

private:
	std::vector<Coral::Type*> types;
	std::unordered_map<std::string, Coral::Type*> typesByNames;

	Coral::HostInstance hostInstance;
	std::unique_ptr<Coral::AssemblyLoadContext> loadContext; // keep current context
};
