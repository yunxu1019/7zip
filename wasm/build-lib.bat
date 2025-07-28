@echo off
setlocal
@CHCP 65001

:: 设置 LZMA SDK 路径
set LZMA_DIR=D:\work\7zip
set OUTPUT_DIR=%LZMA_DIR%\bin
rd /s /q %OUTPUT_DIR%
:: 设置 Visual Studio 2008 环境（x86 架构）
@REM call "C:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\vcvarsall.bat" x86
set VC=D:\prog\vs2010\VC
set crt=D:\prog\vs2010\VC\crt\src
call %VC%\vcvarsall.bat x86
echo %VC%
:: 进入 LzmaLib 项目目录
cd /d %LZMA_DIR%\C

:: 创建输出目录（如果不存在）
if not exist %OUTPUT_DIR% mkdir %OUTPUT_DIR%

:: 编译 LzmaLib 项目（生成 .lib，使用 stdcall 调用约定）
@REM %cl% /c /O2 /I%LZMA_DIR%\C *.c /D_WIN32 /DNO_ASM /MT /Gz /GS-
%VC%\bin\cl /c /MT /Gz /Ot /D_WIN32 /I"%LZMA_DIR%\C" /I"%VC%\include" /I"%crt%" %LZMA_DIR%\wasm\LzmaUnC.c LzmaDec.c LzFindMt.c LzFind.c Alloc.c LzFindOpt.c Threads.c CpuArch.c
%VC%\bin\lib /OUT:%OUTPUT_DIR%\LzmaLib.lib *.obj
:: 清理临时文件
del *.obj

:: 生成 LzmaLib.inc 文件
echo ; LzmaLib.inc > %OUTPUT_DIR%\LzmaLib.inc
echo LzmaUncompress PROTO :PTR BYTE, :PTR DWORD, :PTR BYTE, :PTR DWORD >> %OUTPUT_DIR%\LzmaLib.inc

endlocal