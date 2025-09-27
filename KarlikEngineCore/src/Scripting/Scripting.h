#pragma once
#include "Script.h"

class Scripting {
public:
	virtual ~Scripting() = default;

	virtual std::shared_ptr<Script> CreateScript() = 0;
	void RemoveScript(std::shared_ptr<Script> script);

private:
	std::vector<std::shared_ptr<Script>> scripts;
};
