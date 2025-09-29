#include "Script.h"
#include "Scripting.h"

Script::Script(const std::string& uuid, const std::string& name, Scripting* scripting, WorldObject* worldObject)
	: uuid(uuid), name(name), scripting(scripting), worldObject(worldObject)
{

}
