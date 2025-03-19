#include "llvm/Support/CommandLine.h"
#include "llvm/Support/InitLLVM.h"
#include "llvm/Support/raw_ostream.h"

#include "antlr4-runtime.h"
#include "calc_antlrCore/calc_antlrLexer.h"
#include "calc_antlrCore/calc_antlrParser.h"
#include "calc_antlrAstVisitor.h"

static llvm::cl::opt<std::string>
Input(llvm::cl::Positional,
    llvm::cl::desc("<input expression>"),
    llvm::cl::init(""));

int main(int argc, const char** argv) {
    llvm::InitLLVM X(argc, argv);
    llvm::cl::ParseCommandLineOptions(argc, argv, "calc - the expression compiler\n");

    //Lexer lexer(llvm::StringRef("with a, b: 4 + (3 + b);"));
    antlr4::ANTLRInputStream input(Input);
    calc_antlrCore::calc_antlrLexer lexer(&input);
    antlr4::CommonTokenStream tokens(&lexer);

    calc_antlrCore::calc_antlrParser parser(&tokens);
    antlr4::tree::ParseTree* tree = parser.calc();

    llvm::LLVMContext llvmContext;
    llvm::Module* module = new llvm::Module("calc_antlr.exp", llvmContext);
    calc_antlrAstVisitor astVisitor(module);
    auto s = tree->toStringTree(&parser);
    astVisitor.compile(tree);

    /*Lexer lexer(Input);
    Parser parser(lexer);
    AST* tree = parser.parse();
    if (!tree || parser.hasError()) {
        llvm::errs() << "Syntax errors occured\n";
        return 1;
    }
    Sema semantic;
    if (semantic.semantic(tree)) {
        llvm::errs() << "Semantic errors occured\n";
        return 1;
    }

    CodeGen codeGenerator;
    codeGenerator.compile(tree);*/
    return 0;
}