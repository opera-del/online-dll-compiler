// framepacer_bypass.c
#include <windows.h>

extern "C" {

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {

  Thought for 4s

A DLL intercept approach: FramePacer loads framepacer64.dll on launch. We'll drop a stub that skips the Steam check.

// framepacer_bypass.c
#include <windows.h>

extern "C" {

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
    switch (ul_reason_for_call)
    {
        case DLL_PROCESS_ATTACH:
            // Skip the Steam-only check on launch
            DisableNotifyOnExit(TRUE);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
    }
    return TRUE;
}

// Stub the blocking function (if present in this version)
__declspec(dllexport) void DisableNotifyOnExit(BOOL enable)
{
    // No-op: Steam check is bypassed by DllMain
}

} // extern "C"
