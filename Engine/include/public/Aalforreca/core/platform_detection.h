#ifdef __linux__
    #define ALRC_PLATFORM_LINUX
#elif defined(_WIN64)
    #define ALRC_PLATFORM_WINDOWS
    #error "Windows is not currently supported"
#else
    #error "Unknown platform"
#endif
