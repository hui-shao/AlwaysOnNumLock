#include <windows.h>
#include <stdio.h>


void turnOnNumLock()
{
    SHORT state = GetKeyState(VK_NUMLOCK);

    if (!state)  // The key is off and untoggled
    {
        keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY, 0);
        keybd_event(VK_NUMLOCK, 0, KEYEVENTF_EXTENDEDKEY | KEYEVENTF_KEYUP, 0);
        printf("[*] Virtually pressed key.\r\n");
    }
}

int main()
{
    // Set Console
    SetConsoleTitle("AlwaysOnNumLock_Loop_Ver "EXE_VERSION" by Hui-Shao");
    system("mode con cols=60 lines=15");
    HWND cmd_hwnd = GetConsoleWindow();
    if (cmd_hwnd)
    {
        ShowWindow(cmd_hwnd, SW_MINIMIZE);
    }

    while (1)
    {
        turnOnNumLock();
        Sleep(200);
    }
}