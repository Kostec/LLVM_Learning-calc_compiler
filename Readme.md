Project for LLVM learning

## To create .sln
1. set correct LLVM_DIR into _install_project.bat
2. run _install_project.bat

## To build Project
1. run calc_compiler.sln in Visual Studio
2. build the solution

## to test
1. copy all files from tools to target build directory
2. set correct llc path into _test_prepare.bat
3. set correct compiler path into _test_compile.bat
4. run VS Developer Commnand Toll
5. call _test_prepare.bat to create .obj file
6. call _test_compile.bat to compile executable file