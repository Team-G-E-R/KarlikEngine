#include "Runtime.h"
#include "Utils/UUIDGenerator.h"

World* Runtime::CreateWorld(const std::string& name)
{
    std::string uuid = uuid_generator::generate_uuid_v4();
    std::unique_ptr<World> world = std::make_unique<World>(uuid, name);
    World* rawWorld = world.get();
    worlds[uuid] = std::move(world);
    return rawWorld;
}

void Runtime::SetWorldActive(World* world)
{
    activeWorld = world;
}

World* Runtime::GetWorldActive()
{
    return activeWorld;
}

bool Runtime::DestroyWorld(const std::string& uuid)
{
    return worlds.erase(uuid);
}

bool Runtime::DestroyWorldByName(const std::string& name)
{
    for (auto& world : worlds) {
        if (world.second->name == name) {
            worlds.erase(world.first);
            return true;
        }
    }
    return false;
}
