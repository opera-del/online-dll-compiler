// framepacer_bypass.h
#include <windows.h>

extern "C" {

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved);

// Stub function (if needed)
__declspec(dllexport) void DisableNotifyOnExit(BOOL enable);

} // extern "C"

cl /LD framepacer_bypass.h /Fe:my_library.dll

3. If you want a C-style .c module, drop the extern "C":

// framepacer_bypass.c
#include <windows.h>

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            DisableNotifyOnExit(TRUE);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

__declspec(dllexport) void DisableNotifyOnExit(BOOL enable)
{
    // no-op
}
