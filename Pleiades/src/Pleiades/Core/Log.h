#pragma once

#include "Pleiades/Core/Core.h"

// spdlog
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Pleiades {
	
	class Log
	{
	public:
		static void Init();

		inline static Ref<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static Ref<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }
	private:
		static Ref<spdlog::logger> s_CoreLogger;
		static Ref<spdlog::logger> s_ClientLogger;
	};
}

//Core log
#define PE_CORE_ERROR(...)		::Pleiades::Log::GetCoreLogger()->error(__VA_ARGS__)
#define PE_CORE_WARN(...)		::Pleiades::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define PE_CORE_INFO(...)		::Pleiades::Log::GetCoreLogger()->info(__VA_ARGS__)
#define PE_CORE_TRACE(...)		::Pleiades::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define PE_CORE_FATAL(...)		::Pleiades::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//Client log
#define PE_ERROR(...)			::Pleiades::Log::GetClientLogger()->error(__VA_ARGS__)
#define PE_WARN(...)			::Pleiades::Log::GetClientLogger()->warn(__VA_ARGS__)
#define PE_INFO(...)			::Pleiades::Log::GetClientLogger()->info(__VA_ARGS__)
#define PE_TRACE(...)			::Pleiades::Log::GetClientLogger()->trace(__VA_ARGS__)
#define PE_FATAL(...)			::Pleiades::Log::GetClientLogger()->fatal(__VA_ARGS__)