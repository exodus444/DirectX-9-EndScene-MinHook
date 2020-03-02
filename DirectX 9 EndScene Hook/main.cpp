#include "pch.h"
#include "phook.h"

HWND window;
void* pDevice[119];
PTR EndSceneAddress;
EndScene oEndScene;
WNDPROC oWndProc;

long __stdcall PHook::hkEndScene(LPDIRECT3DDEVICE9 pDevice)
{
	return oEndScene(pDevice);
}

LRESULT CALLBACK PHook::WndProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return oWndProc(hwnd, uMsg, wParam, lParam);
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
		CreateThread(nullptr, 0, (LPTHREAD_START_ROUTINE)PHook::Init, hModule, 0, nullptr);
		break;
	case DLL_THREAD_ATTACH:
		break;
	case DLL_THREAD_DETACH:
		break;
	case DLL_PROCESS_DETACH:
		PHook::Shutdown();
		break;
	}
	return TRUE;
}