#pragma once
#include <string>
class WorkingDirectory
{
public:
	WorkingDirectory();
	~WorkingDirectory();

	inline const std::string& Get() {
		return path;
	}
private:
	std::string path;
};

