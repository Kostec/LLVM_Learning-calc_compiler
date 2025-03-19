Project for LLVM learning

## Before start
- clone [LLVM](https://github.com/llvm/llvm-project) and build it
- upload from https://www.antlr.org/download.html or build antlr4-cpp-runtime from [sources](https://github.com/antlr/antlr4) __TODO: include this to the CMakeList__
- set correct variables "_install_project.bat":
    - ANTLR_INCLUDE_DIR={path to antlr sources}/runtime/src
    - ANTLR_DIR={path to antlr sources}/cmake
    - LLVM_DIR={LLVM build}/lib/cmake/llvm into

## To create .sln
1. run "_install_project.bat"

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