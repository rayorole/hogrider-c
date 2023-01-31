#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <Shlobj.h>
#include <tchar.h>

SHFOLDERAPI SHGetFolderPathA(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, __out_ecount(MAX_PATH) LPSTR pszPath);
SHFOLDERAPI SHGetFolderPathW(HWND hwnd, int csidl, HANDLE hToken, DWORD dwFlags, __out_ecount(MAX_PATH) LPWSTR pszPath);
#ifdef UNICODE
#define SHGetFolderPath SHGetFolderPathW
#else
#define SHGetFolderPath SHGetFolderPathA
#endif

// Local
#include "payloads.c"

int main(int argc, char *argv[])
{
    hideWindow();
    hideAppInTaskbar();

    unsigned int threadId;
    HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, showMsgBox, NULL, 0, &threadId);

    char myDocumentsPath[MAX_PATH];
    if (SUCCEEDED(SHGetSpecialFolderPath(NULL, myDocumentsPath, CSIDL_PERSONAL, FALSE)))
    {
        // Use myDocumentsPath
    }
    else
    {
        // Handle the error
    }

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}