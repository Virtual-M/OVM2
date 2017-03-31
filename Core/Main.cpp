
#include <Windows.h>
#include <iostream>

BOOL WINAPI OpenConsole(LPCSTR ConsoleTitle)
{
	DWORD nOldProtect;
	if (!VirtualProtect(FreeConsole, 1, PAGE_EXECUTE_READWRITE, &nOldProtect))
		return FALSE;
	*(BYTE*)(FreeConsole) = 0xC3;
	if (!VirtualProtect(FreeConsole, 1, nOldProtect, &nOldProtect))
		return FALSE;
	
	SetConsoleTitleA(ConsoleTitle);
	freopen("CONOUT$", "w", stdout);
	freopen("CONIN$", "r", stdout);
	return TRUE;
}

VOID WINAPI OVMEntry()
{
	OpenConsole("OVM2 Beta - by Louka @ V3rmillion");

}

BOOL WINAPI DllMain(HMODULE DllModule, DWORD TReason, LPVOID Reserved)
{
	if (TReason == DLL_PROCESS_ATTACH)
		CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)OVMEntry, NULL, NULL, NULL);
	return TRUE;
}