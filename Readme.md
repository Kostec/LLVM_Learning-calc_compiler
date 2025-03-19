Project for LLVM learning

## To create .sln
1. set correct ANTLR_INCLUDE_DIR, ANTLR_DIR, LLVM_DIR into "_install_project.bat"
2. run "_install_project.bat"

## To build Project
- with Visual Studio
    1. run "calc_compiler.sln" in Visual Studio
    2. build the solution
- with bat
    1. run "_build_project.bat"
    

## to test
1. copy all files from "tools/gen" to target build directory
2. set correct llc path into "*_prepare.bat"
3. set correct compiler path into "_compile.bat"