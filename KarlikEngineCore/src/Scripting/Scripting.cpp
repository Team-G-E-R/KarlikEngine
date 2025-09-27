#include "Scripting.h"

void Scripting::RemoveScript(std::shared_ptr<Script> script)
{
	scripts.erase(std::remove(scripts.begin(), scripts.end(), script), scripts.end());
}
