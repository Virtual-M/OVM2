#pragma once

#include <Windows.h>

class Memory {
public:
	bool Compare(const BYTE *pData, const BYTE *bMask, const char *szMask);
	DWORD FindPattern(DWORD dwAddress, DWORD dwLen, BYTE *bMask, char *szMask);
	static int Scan(DWORD mode, char* content, char* mask, DWORD Offset = 0);
	static int QuickScan(DWORD Mode, char* content, char* mask);
};