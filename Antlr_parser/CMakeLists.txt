link_directories("D:/Projects/LLVM/Learning/antlr4-cpp-runtime-4.13.2-source/runtime/bin/vs-2022/x64/Debug DLL")  

add_executable (calc_antlr
  main.cpp
  calc_antlrAstVisitor.cpp
  "calc_antlrCore/calc_antlrBaseListener.cpp"
  "calc_antlrCore/calc_antlrBaseVisitor.cpp"
  "calc_antlrCore/calc_antlrLexer.cpp"
  "calc_antlrCore/calc_antlrListener.cpp"
  "calc_antlrCore/calc_antlrParser.cpp"
  "calc_antlrCore/calc_antlrVisitor.cpp"
  )
  
# get_cmake_property(_variableNames VARIABLES)
# list (SORT _variableNames)
# foreach (_variableName ${_variableNames})
#     message(STATUS "${_variableName}=${${_variableName}}")
# endforeach()

target_include_directories(calc_antlr PRIVATE ./)  

target_link_libraries(calc_antlr PRIVATE ${llvm_libs})
# target_link_libraries(calc_antlr PRIVATE "D:/Projects/LLVM/Learning/antlr4-cpp-runtime-4.13.2-source/runtime/bin/vs-2022/x64/Debug DLL/antlr4-runtime.lib")
target_link_libraries(calc_antlr PRIVATE "${CMAKE_CURRENT_LIST_DIR}/ext/antlr/antlr4-runtime.lib")

add_custom_command(TARGET calc_antlr POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:calc_antlr> "$(Configuration)/antlr4-runtime.lib"
    COMMAND ${CMAKE_COMMAND} -E copy $<TARGET_FILE:calc_antlr> "$(Configuration)/antlr4-runtime.dll"
)
