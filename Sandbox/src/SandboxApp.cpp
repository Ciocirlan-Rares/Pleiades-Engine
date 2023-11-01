#include <Pleiades.h>
#include <Pleiades/Core/EntryPoint.h>

#include "GameLayer.h"

class Sandbox : public Pleiades::Application
{
public:
	Sandbox()
	{
		PushLayer(new GameLayer());
	}

	~Sandbox()
	{
	}
};

Pleiades::Application* Pleiades::CreateApplication()
{
	return new Sandbox();
}