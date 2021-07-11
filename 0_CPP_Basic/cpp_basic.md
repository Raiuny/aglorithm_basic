
## C++基础
[TOC]
#### 标准输入输出流
- cin 键盘输入 标准输入，有缓冲
- cou 屏幕输出 标准输出，有缓冲
- cerr 屏幕输出  标准错误输出，无缓冲
- clog 屏幕输出，标准错误输出，有缓冲
#### 头文件
> 头文件的作用：内部包括一些函数，类供cpp文件使用
>[文字链接](www.baidu.com)
##### launch.json 文件（vscode）
```json
{
    "version": "0.2.0",
    "configurations": [
        {
            "name": "g++.exe build and debug active file",
            "type": "cppdbg",
            "request": "launch",
            "program": "${fileDirname}\\${fileBasenameNoExtension}.exe",
            "args": [],
            "stopAtEntry": false,
            "cwd": "${workspaceFolder}",
            "environment": [],
            "externalConsole": false,      //修改此项，让其弹出终端
            "MIMode": "gdb",
            "miDebuggerPath": "D:\\Mingw\\mingw64\\bin\\gdb.exe",
            "setupCommands": [
                {
                    "description": "Enable pretty-printing for gdb",
                    "text": "-enable-pretty-printing",
                    "ignoreFailures": true
                }
            ],
            "preLaunchTask": "task g++" //修改此项
        }
    ]
}
```
```json
{
    "version": "2.0.0",
    "tasks": [
        {
            "type": "shell",
            "label": "task g++",
            "command": "D:\\Mingw\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "D:\\Mingw\\mingw64\\bin"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": "build"
        },
        {
            "type": "cppbuild",
            "label": "C/C++: g++.exe 生成活动文件",
            "command": "D:\\Mingw\\mingw64\\bin\\g++.exe",
            "args": [
                "-g",
                "${file}",
                "-o",
                "${fileDirname}\\${fileBasenameNoExtension}.exe"
            ],
            "options": {
                "cwd": "${fileDirname}"
            },
            "problemMatcher": [
                "$gcc"
            ],
            "group": {
                "kind": "build",
                "isDefault": true
            },
            "detail": "调试器生成的任务。"
        }
    ]
}
```
---

<!---注释
 [x] 学习markdown
- [x] 上标 2^n^ 下标2~t~
 -->
