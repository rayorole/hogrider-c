#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
// Local
#include "payloads.c"

int main(int argc, char *argv[])
{
    hideWindow();
    hideAppInTaskbar();

    unsigned int threadId;
    HANDLE hThread = (HANDLE)_beginthreadex(NULL, 0, showMsgBox, NULL, 0, &threadId);

    WaitForSingleObject(hThread, INFINITE);
    CloseHandle(hThread);

    return 0;
}