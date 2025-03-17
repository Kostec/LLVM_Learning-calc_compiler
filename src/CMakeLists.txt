add_executable (calc
  _main.cpp
  CodeGen.cpp
  Lexer.cpp
  Parser.cpp
  Sema.cpp
  runtime.c
  )
target_link_libraries(calc PRIVATE ${llvm_libs})
