#include <stdio.h>
#include <windows.h>

LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
    BOOL fEatKeystroke = FALSE;
    if (nCode == HC_ACTION)
    {
        switch (wParam)
        {
            case WM_KEYDOWN:
            case WM_SYSKEYDOWN:
                // case WM_KEYUP:
                //case WM_SYSKEYUP:
                PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT) lParam;
                switch (p->vkCode)
                {
                    case VK_NUMLOCK:  // Eat up NumLock
                        fEatKeystroke = TRUE;
                        printf("\r\n[#] Eat KeyCode: %lu\r\n\n", p->vkCode);
                        break;
                    default:
                        fEatKeystroke = FALSE;
                        printf("[+] Current KeyCode: %lu\r\n", p->vkCode);
                        break;
                }
                break;
            default:
                break;
        }
    }
    return (fEatKeystroke ? 1 : CallNextHookEx(NULL, nCode, wParam, lParam));
}

int main()
{
    // Set Console
    HWND cmd_hwnd = GetConsoleWindow();
    if (cmd_hwnd)
    {
        ShowWindow(cmd_hwnd, SW_MINIMIZE);
    }
    SetConsoleTitle("AlwaysOnNumLock "EXE_VERSION" by Hui-Shao");

    // Install the low-level keyboard & mouse hooks
    HHOOK hhkLowLevelKybd = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, 0, 0);

    // Determine whether the hook is successful
    if (hhkLowLevelKybd)
    {
        printf("Hooked\n");
    } else
    {
        printf("Hook Failed. Code: %lu", GetLastError());
        getchar();
        getchar();
        return 0;
    }

    // Keep this app running until we're told to stop
    MSG msg;
    while (!GetMessage(&msg, NULL, 0, 0))
    {    //this while loop keeps the hook
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    UnhookWindowsHookEx(hhkLowLevelKybd);

    return (0);
}
