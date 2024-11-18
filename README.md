
# Processes Viewer

A simple C++ tool that lists the active processes running on a Windows machine. It provides real-time updates every 2 seconds, showing the executable name of each process.

## Features

- **Real-time process listing:** Displays the active processes running on your system and updates every 2 seconds.
- **Process details:** For each process, the name of the executable is shown.
- **Cross-platform (Windows):** The tool uses Windows APIs to gather process data, so it works on Windows-based systems.

## Requirements

- **C++ Compiler**: You need a C++ compiler that supports C++11 or later (e.g., [Microsoft Visual Studio](https://visualstudio.microsoft.com/), [MinGW](https://winlibs.com/#download-release).
- **Windows OS**: This tool uses Windows-specific APIs, so it will only work on Windows.

## Getting Started

### 1. Clone the repository

First, clone the repository to your local machine using Git:

```bash
git clone https://github.com/BiocsRE/active-processes-viewer.git
```

### 2. Install a C++ compiler

If you don’t already have a C++ compiler, install one:

- For **Windows**, you can download and install [Microsoft Visual Studio](https://visualstudio.microsoft.com/downloads/) or [MinGW](https://winlibs.com/#download-release).
  
  - If you're using Visual Studio, you can create a new C++ project and add the provided `main.cpp` file to it.
  - If you're using MinGW, you can compile directly from the command line.

### 3. Compile the code

#### Using Visual Studio:
- Open Visual Studio and create a new **Console App** project.
- Add the `main.cpp` file to the project.
- Build and run the project using the "Start" button.

#### Using MinGW (GCC compiler):
1. Open **Command Prompt** or **PowerShell**.
2. Navigate to the directory where your `main.cpp` is located.
3. Compile the code with MinGW:

```bash
g++ main.cpp -o process_viewer -lpsapi
```

### 4. Run the program

After compiling, you will have an executable named `process_viewer.exe` (or simply `process_viewer` on some systems).

- Open a command prompt in the directory where the executable is located and run:

```bash
process_viewer.exe
```

The tool will start displaying a list of active processes, updating every 2 seconds.

## How It Works

This tool uses Windows API functions such as `EnumProcesses` to retrieve a list of active processes. For each process, it fetches the name of the executable file using `GetModuleFileNameExW`. The program then prints the list to the command line interface (CLI) and refreshes the output every 2 seconds.

### Key Functions:
- **EnumProcesses**: Enumerates the process IDs of all the processes currently running.
- **OpenProcess**: Opens a handle to a specified process for querying information.
- **GetModuleFileNameExW**: Retrieves the executable file name of the process.
- **wcstombs_s**: Converts the wide-character string (`wchar_t*`) to a standard multi-byte string (`char*`), using a secure function to prevent buffer overflow.

## Troubleshooting

- **Missing Dependencies**: If you encounter issues with missing libraries, ensure you have the necessary development environment set up (Visual Studio or MinGW with the correct libraries, like `psapi.lib`).
  
- **Compilation Errors**: If you’re using MinGW or another compiler, ensure it supports the C++11 standard or later. If you're seeing errors with `psapi.lib`, make sure you link the `psapi` library properly during compilation (`-lpsapi`).


---

### How to customize:

- **Repository name**: Replace `BiocsRE/active-processes-viewer.git` with the actual path to your GitHub repository.
- **Additional dependencies**: If there are any additional dependencies, you can add them to the README.

This README provides clear instructions on setting up the project, compiling the code, and running it. It's structured so that anyone with basic knowledge of C++ and Windows development can follow the steps and get the program working.
![image](https://github.com/user-attachments/assets/7f43fb4d-3385-4dac-b333-d8bb7c96a5a4)
