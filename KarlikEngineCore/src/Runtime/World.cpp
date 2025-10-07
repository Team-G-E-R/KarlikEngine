#include "World.h"
#include "Utils/UUIDGenerator.h"

WorldObject* World::CreateObject(std::string name)
{
	std::unique_ptr<WorldObject> worldObject = std::make_unique<WorldObject>(scripting, uuid_generator::generate_uuid_v4(), name);
	WorldObject* rawObject = worldObject.get();
	worldObjects.push_back(std::move(worldObject));
	return rawObject;
}

WorldObject* World::GetObjectByName(const std::string& name)
{
	for (int i = 0; i < worldObjects.size(); i++) {
		WorldObject* current = worldObjects[i].get();
		if (current->name == name) {
			return current;
		}
	}
	return nullptr;
}
