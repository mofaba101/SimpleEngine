#pragma once

#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

#include "SimpleEngine/Core.h"

namespace SimpleEngine
{
	class SE_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

// Core log macros
#define SE_CORE_TRACE(...) :: SimpleEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define SE_CORE_INFO(...)  :: SimpleEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define SE_CORE_WARN(...)  :: SimpleEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define SE_CORE_ERROR(...) :: SimpleEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define SE_CORE_FATAL(...) :: SimpleEngine::Log::GetCoreLogger()->critical(__VA_ARGS__)

// Client log macros
#define SE_TRACE(...)      :: SimpleEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define SE_INFO(...)       :: SimpleEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define SE_WARN(...)       :: SimpleEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define SE_ERROR(...)      :: SimpleEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define SE_FATAL(...)      :: SimpleEngine::Log::GetClientLogger()->critical(__VA_ARGS__)
