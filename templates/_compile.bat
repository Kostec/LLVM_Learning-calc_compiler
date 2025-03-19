REM D:\Projects\LLVM\llvm_17\build\Debug\bin\clang-cl.exe -o expr.o "D:\Projects\LLVM\Learning\CompilerStructure\src\runtime.cpp"
REM "C:\Program Files\Microsoft Visual Studio\2022\Community\VC\Tools\MSVC\14.43.34808\bin\Hostx64\x64\cl.exe" expr.obj "D:\Projects\LLVM\Learning\CompilerStructure\src\runtime.c"
"${LLVM_TOOLS_BINARY_DIR}\clang-cl.exe" expr.obj "${CMAKE_CURRENT_LIST_DIR}\src\runtime.c"