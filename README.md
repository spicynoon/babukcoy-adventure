TEMPAT NYIMPEN TUGAS PRAKTIKUM ALGORITMA DAN PEMROGRAMAN

//cpp properties
{
    "configurations": [
        {
            "name": "Win32",
            "includePath": [
                "${workspaceFolder}/**"
            ],
            "defines": [
                "_DEBUG",
                "UNICODE",
                "_UNICODE"
            ],
            "windowsSdkVersion": "10.0.19041.0",
            "compilerPath": "C:\\mingw64\\bin\\gcc.exe",
            "cStandard": "c17",
            "cppStandard": "c++17",
            "intelliSenseMode": "clang-x64"
        }
    ],
    "version": 4
}

//json setting
{
    "files.associations": {
        "iostream": "cpp",
        "ostream": "cpp"
    }
}

//json task
{
    // See https://go.microsoft.com/fwlink/?LinkId=733558
    // for the documentation about the tasks.json format
    "version": "2.0.0",
    "tasks": [
        {
            "label": "Compile C++",
            "type": "shell",
            "command": "g++",
            "args": [
                "-std=c++17",
                ".\\src\\*.cpp",
                "-o",
                ".\\bin\\Main.exe"
            ]
        },
        {
            "label": "run",
            "type": "shell",
            "command": ".\\bin\\Main",
            "dependsOn":["Compile C++"],
            "group": {
                "kind": "build",
                "isDefault": true
            }
        }
    ]
}

better comment
code runner
