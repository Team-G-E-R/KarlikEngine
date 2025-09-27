#include "World.h"
#include "Utils/UUIDGenerator.h"

WorldObject* World::CreateObject(std::string name)
{
	std::unique_ptr<WorldObject> worldObject = std::make_unique<WorldObject>(uuid_generator::generate_uuid_v4());
	WorldObject* rawObject = worldObject.get();
	worldObjects.push_back(std::move(worldObject));
	return rawObject;
}
