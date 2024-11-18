#include <iostream>
#include <vector>
#include <windows.h>
#include <psapi.h>
#include <thread>
#include <chrono>

using namespace std;

vector<string> getActiveProcesses() {
    vector<string> processList;
    DWORD processes[1024], cbNeeded;

    if (!EnumProcesses(processes, sizeof(processes), &cbNeeded)) {
        return processList;
    }

    DWORD processCount = cbNeeded / sizeof(DWORD);

    for (DWORD i = 0; i < processCount; ++i) {
        DWORD processId = processes[i];
        if (processId != 0) {
            HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processId);
            if (hProcess) {
                WCHAR processName[MAX_PATH] = L"<unknown>";

                if (GetModuleFileNameExW(hProcess, NULL, processName, sizeof(processName) / sizeof(WCHAR))) {
                    char processNameAnsi[MAX_PATH];
                    size_t convertedChars = 0;

                    // Use wcstombs_s for safe conversion
                    wcstombs_s(&convertedChars, processNameAnsi, MAX_PATH, processName, _TRUNCATE);
                    processList.push_back(processNameAnsi);
                }
                CloseHandle(hProcess);
            }
        }
    }

    return processList;
}

void printProcesses(const vector<string>& processes) {
    system("cls");
    cout << "Active Processes:" << endl;
    cout << "----------------------" << endl;
    for (const auto& process : processes) {
        cout << process << endl;
    }
    cout << "\nPress Ctrl+C to exit." << endl;
}

int main() {
    while (true) {
        vector<string> processes = getActiveProcesses();
        printProcesses(processes);
        std::this_thread::sleep_for(std::chrono::seconds(2));
    }

    return 0;
}
