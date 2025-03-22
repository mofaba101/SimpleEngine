#pragma once

#ifdef SE_PLATFORM_WINDOWS
	#ifdef SE_BUILD_DLL
		#define SIMPLEENGINE_API __declspec(dllexport)
	#else
		#define SIMPLEENGINE_API __declspec(dllimport)
	#endif
#else
	#error SimpleEngine only support Windows!
#endif //  SE_BUILD_DLL
