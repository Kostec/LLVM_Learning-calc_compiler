antlr4 -Dlanguage=Cpp calc_antlr.g4 -visitor -o calc_antlrCore -package calc_antlrCore -Xlog
pause

javac *.java
pause

grun calc_antlr primaryExpression -token
@rem input there
pause

grun calc_antlr primaryExpression -tree
@rem input there
pause

grun calc_antlr primaryExpression -gui
@rem input there