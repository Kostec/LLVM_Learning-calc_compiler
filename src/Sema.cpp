#include "Sema.h"
#include "llvm/ADT/StringSet.h"
#include "llvm/Support/raw_ostream.h"

namespace
{
	class DeclCheck : public ASTVisitor
	{
		llvm::StringSet<> m_scope;
		bool m_hasError;

		enum ErrorType { Twice, Not };

		void error(ErrorType errorType, llvm::StringRef variable)
		{
			llvm::errs() << "Variable " << variable << " "
				<< (errorType == Twice ? "already" : "not")
				<< " declared\n";
			m_hasError = true;
		}

		virtual void visit(Factor& node) override
		{
			if (node.getKind() == Factor::Ident)
			{
				if (m_scope.find(node.getVal()) == m_scope.end())
				{
					error(Not, node.getVal());
				}
			}
		}

		virtual void visit(BinaryOp& node) override
		{
			if (node.getLeft())
			{
				node.getLeft()->accept(*this);
			}
			else
			{
				m_hasError = true;
			}

			if (node.getRight())
			{
				node.getRight()->accept(*this);
			}
			else
			{
				m_hasError = true;
			}
		}

		virtual void visit(WithDecl& node) override
		{
			for (auto I = node.begin(), E = node.end(); I != E; ++I)
			{
				if (!m_scope.insert(*I).second)
				{
					error(Twice, *I);
				}
			}
			
			if (node.getExpr())
			{
				node.getExpr()->accept(*this);
			}
			else
			{
				m_hasError = true;
			}
		}
	public:
		DeclCheck()
			: m_hasError(false)
		{ }

		bool hasError()
		{
			return m_hasError;
		}
	};
}

bool Sema::semantic(AST* tree)
{
	if (!tree)
	{
		return false;
	}

	DeclCheck check;
	tree->accept(check);
	return check.hasError();
}