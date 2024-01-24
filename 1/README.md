
## C++基础
[TOC]
### 标准输入输出流
- cin 键盘输入 标准输入，有缓冲
- cou 屏幕输出 标准输出，有缓冲
- cerr 屏幕输出  标准错误输出，无缓冲
- clog 屏幕输出，标准错误输出，有缓冲
### 头文件
> 头文件的作用：内部包括一些函数，类供cpp文件使用
>[文字链接](www.baidu.com)
#### launch.json 文件（vscode）
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
#### tasks.json (vscode)
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

<!---注释
 [x] 学习markdown
- [x] 上标 2^n^ 下标2~t~
 -->

#### iomanip库
- setfill(char c)  设置以c表示的填充字
- setprecision(int n) 设置以n表示的数值精度
- setw(int n)  设置以n表示的宽度
    - cout << setfill('*')<<setw(10)<<d<<endl; 
    - 默认右对齐如果想左对齐则加入std::left
    - 这些函数均是用来配置输出流对象的，需要写在输出流对象的右边，输出对象的左旁边，中间可以任意添加字符串。
    - oct 八进制输出数据
    - dec 十进制输出数据（默认）
    - hex 十六进制输出数据
    - uppercase 十六进制输出时字母大写，搭配hex使用,nouppercase 则不输出大写
    - skipws 输出时候跳过空白
    - flush 刷新流
    - left right 左对齐 右对齐
    - scientific 科学计数法输出
    - fixed 定点数方式输出
    - showbase 输出前缀（八进制为0，十六进制为0x）noshowbase则不输出前缀
    - showpoint 输出浮点数时带小数点
    - showpos 输出正整数时加 "+"
  
### 分支结构（if switch)
- if(条件x) {y} else {z}
    如果满足条件x则触发y事件，否则触发z事件
- if(条件x1) {y1} else if(x2) {y2} else {z}
如果满足条件x1则触发y1事件，否则判断是否满足x2，如果满足x2，则触发y2事件，否则执行z事件
- switch(x){
  case(n1):y1; break;
  case(n2):y2; break;
  case(n3):y3; break;
  default: z
} 

### 循环结构（for, while, do while）
- for (i = 0; i < num ; i++) 最好在前面事先定义i
- while(条件x){y} 
- do{y}while(条件x) 至少执行一次y

