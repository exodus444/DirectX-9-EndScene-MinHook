#pragma once
#include "pch.h"
typedef uintptr_t PTR;
typedef long(__stdcall* EndScene)(LPDIRECT3DDEVICE9);
typedef LRESULT(CALLBACK* WNDPROC)(HWND, UINT, WPARAM, LPARAM);

extern bool init_hook;
extern HWND window;
extern void* pDevice[119];
extern PTR EndSceneAddress;
extern EndScene oEndScene;
extern WNDPROC oWndProc;

namespace PHook
{
	void Init();
	void Shutdown();
	LRESULT CALLBACK WndProc(HWND hwnd,UINT uMsg, WPARAM wParam, LPARAM lParam);
	long __stdcall hkEndScene(LPDIRECT3DDEVICE9 pDevice);
}