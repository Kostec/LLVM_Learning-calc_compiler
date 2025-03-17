#include "CodeGen.h"

#include "llvm/ADT/StringMap.h"
#include "llvm/IR/IRBuilder.h"
#include "llvm/IR/LLVMContext.h"
#include "llvm/Support/raw_ostream.h"

using namespace llvm;

namespace
{
    class ToIRVisitor : public ASTVisitor
    {
    private:
        Module* m_module;
        IRBuilder<> m_builder;
        Type* m_voidType;
        Type* m_int32Type;
        PointerType* m_ptrType;
        Constant* m_int32Zero;
        Value* m_value;

        StringMap<Value*> m_nameMap;

    public:
        ToIRVisitor(Module* module)
            : m_module(module), m_builder(module->getContext()), m_value(nullptr)
        {
            m_voidType = Type::getVoidTy(m_module->getContext());
            m_int32Type = Type::getInt32Ty(m_module->getContext());
            m_ptrType = PointerType::getUnqual(m_module->getContext());
            m_int32Zero = ConstantInt::get(m_int32Type, 0, true);
        }

        void run(AST* tree)
        {
            FunctionType* mainFty = FunctionType::get(m_int32Type, { m_int32Type, m_ptrType }, false);
            Function* mainFn = Function::Create(mainFty, GlobalValue::ExternalLinkage, "main", m_module);
            BasicBlock* basicBlock = BasicBlock::Create(m_module->getContext(), "entry", mainFn);
            m_builder.SetInsertPoint(basicBlock);

            tree->accept(*this);

            FunctionType* calcWriteFnTy = FunctionType::get(m_voidType, { m_int32Type }, false);
            Function* calcWriteFn = Function::Create(calcWriteFnTy, GlobalValue::ExternalLinkage, "calc_write", m_module);
            m_builder.CreateCall(calcWriteFnTy, calcWriteFn, { m_value });
            
            m_builder.CreateRet(m_int32Zero);
        }

        virtual void visit(WithDecl& node) override
        {
            FunctionType* readFnTy = FunctionType::get(m_int32Type, { m_ptrType }, false);
            Function* readFn = Function::Create(readFnTy, GlobalValue::ExternalLinkage, "calc_read", m_module);

            for (auto I = node.begin(), E = node.end(); I != E; ++I)
            {
                StringRef var = *I;
                Constant* strText = ConstantDataArray::getString(m_module->getContext(), var);
                GlobalVariable* str = new GlobalVariable(*m_module, strText->getType(), true, GlobalValue::PrivateLinkage, strText, Twine(var).concat(".str"));
                CallInst* call = m_builder.CreateCall(readFnTy, readFn, { str });
                m_nameMap[var] = call;
            }

            node.getExpr()->accept(*this);
        }

        virtual void visit(Factor& node) override
        {
            if (node.getKind() == Factor::Ident)
            {
                m_value = m_nameMap[node.getVal()];
            }
            else
            {
                int intval;
                node.getVal().getAsInteger(10, intval);
                m_value = ConstantInt::get(m_int32Type, intval, true);
            }

        }

        virtual void visit(BinaryOp& node) override
        {
            node.getLeft()->accept(*this);
            Value* left = m_value;
            node.getRight()->accept(*this);
            Value* right = m_value;
            switch (node.getOperator())
            {
            case BinaryOp::Plus:
                m_value = m_builder.CreateNSWAdd(left, right);
                break;
            case BinaryOp::Minus:
                m_value = m_builder.CreateNSWSub(left, right);
                break;
            case BinaryOp::Mul:
                m_value = m_builder.CreateNSWMul(left, right);
                break;
            case BinaryOp::Div:
                m_value = m_builder.CreateSDiv(left, right);
                break;
            default:
                break;
            }
        }
    };
}

void CodeGen::compile(AST* tree)
{
    LLVMContext context;
    Module* module = new Module("calc.expr", context);
    ToIRVisitor toIR(module);
    toIR.run(tree);
    std::error_code error;
    llvm::raw_fd_ostream fileStream("calc.ll", error);
    module->print(outs(), nullptr);
    //module->dump();
}