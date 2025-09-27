#include "Runtime.h"
#include "Utils/UUIDGenerator.h"

std::string Runtime::CreateWorld(std::string_view name)
{
    std::string uuid = uuid_generator::generate_uuid_v4();
    std::unique_ptr<World> world = std::make_unique<World>(uuid, name);
    worlds[uuid] = std::move(world);
    return uuid;
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
