#include "Application.hpp"

class HelloWindowApp final : public Application
{
public:
	HelloWindowApp(const std::string& title);

protected:
	bool Load() override;
	void Render() override;
	void Update() override;
};