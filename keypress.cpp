#include <iostream>
#include <windows.h>
using namespace std;

BYTE scan_code(DWORD pkey)
{
    const DWORD result = MapVirtualKey(pkey, MAPVK_VK_TO_VSC);
    return static_cast<BYTE>(result);
}

int main()
{
    Sleep(3000);
    for (int i = 0; i < 10; i++)
    {
        keybd_event(static_cast<BYTE>(67), scan_code(67), 0, 0);
        Sleep(50);
        keybd_event(static_cast<BYTE>(67), scan_code(67), KEYEVENTF_KEYUP, 0);
    }

    system("pause");

    return 0;
}