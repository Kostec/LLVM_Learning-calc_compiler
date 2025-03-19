#ifndef MY_LANGUAGE_AST_VISITOR_H
#define MY_LANGUAGE_AST_VISITOR_H

#include "calc_antlrCore/calc_antlrBaseVisitor.h"

#include "llvm/ADT/StringMap.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/raw_ostream.h"

using namespace calc_antlrCore;
using namespace llvm;

class calc_antlrAstVisitor : public calc_antlrBaseVisitor
{
private:
    Module* m_module;
    IRBuilder<> m_builder;
    LLVMContext context;
    Type* m_voidType;
    Type* m_int32Type;
    PointerType* m_ptrType;
    Constant* m_int32Zero;
    Value* m_value;

    FunctionType* readFnTy;
    Function* readFn;

    StringMap<Value*> m_nameMap;
public:

    calc_antlrAstVisitor(Module* module)
        : m_module(module), m_builder(module->getContext()), m_value(nullptr),
        readFnTy(nullptr), readFn(nullptr)
    {
        m_voidType = Type::getVoidTy(m_module->getContext());
        m_int32Type = Type::getInt32Ty(m_module->getContext());
        m_ptrType = PointerType::getUnqual(m_module->getContext());
        m_int32Zero = ConstantInt::get(m_int32Type, 0, true);
    }

    void run(antlr4::tree::ParseTree* tree)
    {
        FunctionType* mainFty = FunctionType::get(m_int32Type, { m_int32Type, m_ptrType }, false);
        Function* mainFn = Function::Create(mainFty, GlobalValue::ExternalLinkage, "main", m_module);
        BasicBlock* basicBlock = BasicBlock::Create(m_module->getContext(), "entry", mainFn);
        m_builder.SetInsertPoint(basicBlock);

        tree->accept(this);

        FunctionType* calcWriteFnTy = FunctionType::get(m_voidType, { m_int32Type }, false);
        Function* calcWriteFn = Function::Create(calcWriteFnTy, GlobalValue::ExternalLinkage, "calc_write", m_module);
        m_builder.CreateCall(calcWriteFnTy, calcWriteFn, { m_value });

        m_builder.CreateRet(m_int32Zero);
    }

    void compile(antlr4::tree::ParseTree* tree)
    {
        run(tree);
        std::error_code error;
        llvm::raw_fd_ostream fileStream("calc.ll", error);
        m_module->print(outs(), nullptr);
        m_module->print(fileStream, nullptr);
    }

    virtual std::any visitCalc(calc_antlrParser::CalcContext* ctx) override 
    {
        readFnTy = FunctionType::get(m_int32Type, { m_ptrType }, false);
        readFn = Function::Create(readFnTy, GlobalValue::ExternalLinkage, "calc_read", m_module);
        return visitChildren(ctx);
    }

    virtual std::any visitExpr(calc_antlrParser::ExprContext* ctx) override
    {

        for (auto it = ctx->children.begin(), end = ctx->children.end(); it != end; ++it)
        {
            auto left = *it;
            left->accept(this);
            llvm::Value* lValue = m_value;
            
            it++;
            if (it == end)
            {
                break;
            }
            auto op = *it;
            op->accept(this);

            it++;
            if (it == end)
            {
                break;
            }
            auto right = *it;
            right->accept(this);
            llvm::Value* rValue = m_value;

            auto lText = left->getText();
            auto rText = right->getText();

            if (op->getText() == "+")
            {
                m_value = m_builder.CreateNSWAdd(lValue, rValue);
            }
            else if (op->getText() == "-")
            {
                m_value = m_builder.CreateNSWSub(lValue, rValue);
            }
        }

        llvm::Value* exprValue = m_value;
        return m_value;
    }

    virtual std::any visitFactor(calc_antlrParser::FactorContext* ctx) override
    {
        auto text = ctx->getText();

        return visitChildren(ctx);
    }

    virtual std::any visitTerm(calc_antlrParser::TermContext* ctx) override
    {
        auto text = ctx->getText();

        for (auto it = ctx->children.begin(), end = ctx->children.end(); it != end; ++it)
        {
            auto left = *it;
            left->accept(this);
            llvm::Value* lValue = m_value;

            it++;
            if (it == end)
            {
                break;
            }
            auto op = *it;
            op->accept(this);

            it++;
            if (it == end)
            {
                break;
            }
            auto right = *it;
            right->accept(this);
            llvm::Value* rValue = m_value;

            auto lText = left->getText();
            auto rText = right->getText();

            if (op->getText() == "*")
            {
                m_value = m_builder.CreateNSWMul(lValue, rValue);
            }
            else if (op->getText() == "/")
            {
                m_value = m_builder.CreateSDiv(lValue, rValue);
            }
        }

        llvm::Value* termValue = m_value;
        m_value = termValue;
        return m_value;
    }

    virtual std::any visitWithDecl(calc_antlrParser::WithDeclContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual std::any visitIdent(calc_antlrParser::IdentContext* ctx) override
    {
        auto text = ctx->getText();
        if (dynamic_cast<calc_antlrParser::WithDeclContext*>(ctx->parent))
        {
            // With declaration
            Constant* strText = ConstantDataArray::getString(m_module->getContext(), text);
            GlobalVariable* str = new GlobalVariable(*m_module, strText->getType(), true, GlobalValue::PrivateLinkage, strText, Twine(text).concat(".str"));
            CallInst* call = m_builder.CreateCall(readFnTy, readFn, { str });
            m_nameMap[text] = call;
        }
        llvm::Value* identValue = m_nameMap[text];
        m_value = identValue;
        return m_value;
    }

    virtual std::any visitNumber(calc_antlrParser::NumberContext* ctx) override
    {
        auto text = ctx->getText();

        int intval;
        llvm::StringRef val = text;
        val.getAsInteger(10, intval);
        m_value = ConstantInt::get(m_int32Type, intval, true);

        return m_value;
    }
};

#endif MY_LANGUAGE_AST_VISITOR_H