
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include <io.h>
#include <fcntl.h>
#include <wchar.h>
#include <psapi.h>
#define MAX_PROCS 256


#pragma comment(lib, Psapi.lib)
void GetNameID(DWORD ProcessID)
{
    char szProcessName[MAX_PROCS] = "Unknown";
    static int i;
    HMODULE hMod;
    DWORD cbNeeded;
    // Get a handle to the process
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, ProcessID);
    if (hProcess != NULL)
    {
        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(char));
        }

    }
     printf("Processs #%d: %s\t(PID:%d)\t(0x%08X)\n",i,szProcessName,ProcessID,hMod);
        i++;
        CloseHandle(hProcess);
}
int main()
{
    DWORD pProcessIds[MAX_PROCS], nb_Processes, cProcesses;
    if(!EnumProcesses(pProcessIds, sizeof(pProcessIds), &nb_Processes)){
        return 1;
    }

    else
        printf("EnumProcesses() is OK\n");
    cProcesses = nb_Processes/sizeof(DWORD);
    for(int i = 0; i < cProcesses; i++)
    {
        if(pProcessIds[i] != 0)
        {
            GetNameID(pProcessIds[i]);
        }
    }
}
