// InjectDetectDemo.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#define WIN32_LEAN_AND_MEAN           
#include <windows.h>
#include <stdio.h>
#include <process.h>
#include "resource.h"
#include "../MemoryModule/MemoryModule.h"

static void printerror(char * progname)
{
    printf("call this program with an argument of either evade, or caught\n");
    printf("ex. %s %s\n", progname, "evade");
    exit(-1);
}

int main(int argc, char** argv)
{
    if (argc != 2)
    {
        printerror(argv[0]);
    }
    printf("Finding resource\n");
    HMODULE hself = GetModuleHandle(NULL);
    HRSRC hresourceloc = FindResource(hself, MAKEINTRESOURCE(IDR_FILE1), MAKEINTRESOURCE(255));
    HGLOBAL hresourcedata = LoadResource(hself, hresourceloc);
    void* dll = LockResource(hresourcedata);
    DWORD dllsize = SizeofResource(hself, hresourceloc);
    HMEMORYMODULE dllmod = MemoryLoadLibrary(dll, dllsize);
    void* funcaddr = MemoryGetProcAddress(dllmod, "doingwork");
    if (strcmp(argv[1], "evade") == 0) {
        _beginthreadex(NULL, 0, funcaddr, NULL, 0, NULL);
        Sleep(60000000);
    }
    else if (strcmp(argv[1], "caught") == 0) {
        CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)funcaddr, NULL, 0, NULL);
        Sleep(60000000);
    }
    else {
        printerror(argv[0]);
    }
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
