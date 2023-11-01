#pragma once

#include "Pleiades/Core/Core.h"

#ifdef PE_PLATFORM_WINDOWS

extern Pleiades::Application* Pleiades::CreateApplication();

int main(int argc, char** argv)
{
	// If the platform is supported, a logging session starts
	Pleiades::Log::Init();

	PE_PROFILE_BEGIN_SESSION("Startup", "PleiadesProfile-Startup.json");
	auto app = Pleiades::CreateApplication();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Runtime", "PleiadesProfile-Runtime.json");
	app->Run();
	PE_PROFILE_END_SESSION();

	PE_PROFILE_BEGIN_SESSION("Startup", "PleiadesProfile-Shutdown.json");
	delete app;
	PE_PROFILE_END_SESSION();
}

#endif