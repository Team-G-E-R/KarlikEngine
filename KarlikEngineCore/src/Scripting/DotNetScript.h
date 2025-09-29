#pragma once
#include <unordered_set>
#include "Script.h"
#include <Coral/HostInstance.hpp>
#include <Coral/Array.hpp>
#include <Coral/Attribute.hpp>

namespace ScriptMethods {
    constexpr std::string_view Start = "Start";
    constexpr std::string_view Update = "Update";
    constexpr std::string_view PhysicsUpdate = "PhysicsUpdate";
}

class DotNetCache {
public:    
    struct MethodCache {
        std::unordered_set<std::string> names;
    };

    static const MethodCache* RetrieveExistingMethods(
        const std::string& className,
        const Coral::Type* typeData)
    {
        auto [it, inserted] = methodsByName.try_emplace(className);
        if (inserted) {
            auto& cache = it->second;
            cache.names.reserve(typeData->GetMethods().size());

            for (const auto& method : typeData->GetMethods()) {
                auto name = method.GetName();
                cache.names.insert(std::move(name));
            }
        }
        return &it->second;
    }

private:
    static inline std::unordered_map<std::string, MethodCache> methodsByName;
};

class DotNetScript : public Script {
public:
	DotNetScript(const std::string& uuid, const std::string& name, Scripting* scripting, WorldObject* worldObject);
    ~DotNetScript();

	void OnStart() override;
	void OnUpdate() override;
	void OnPhysicsUpdate() override;

private:
    bool HasMethod(const std::string& methodName) const; 
    void InvokeIfValid(std::string_view methodName);

private:
    const DotNetCache::MethodCache* cachedMethods;
	Coral::ManagedObject instance;
};
