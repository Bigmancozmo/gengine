#ifdef _WIN32
	#ifdef BUILDING_GENGINE_DLL
		#define GENGINE_API __declspec(dllexport)
	#else
		#define GENGINE_API __declspec(dllimport)
	#endif
#else
	#define GENGINE_API
#endif