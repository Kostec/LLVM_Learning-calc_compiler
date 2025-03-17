#ifndef AST_H
#define AST_H

#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"


class AST;
class Expr;
class Factor;
class BinaryOp;
class WithDecl;

class ASTVisitor
{
public:
	virtual void visit(AST&) {};
	virtual void visit(Expr&) {};
	virtual void visit(Factor&) = 0;
	virtual void visit(BinaryOp&) = 0;
	virtual void visit(WithDecl&) = 0;
};

class AST
{
public:
	virtual ~AST() {}
	virtual void accept(ASTVisitor& V) = 0;
};

class Expr : public AST
{
public:
	Expr() {};
};

class Factor : public Expr
{
public:
	enum ValueKind { Ident, Number };

private:
	ValueKind m_kind;
	llvm::StringRef m_val;

public:
	Factor(ValueKind kind, llvm::StringRef val)
		: m_kind(kind), m_val(val)
	{
	}

	ValueKind getKind()
	{
		return m_kind;
	}

	llvm::StringRef getVal()
	{
		return m_val;
	}

	virtual void accept(ASTVisitor& V) override
	{
		V.visit(*this);
	}
};

class BinaryOp : public Expr
{
public:
	enum Operator { Plus, Minus, Mul, Div };
private:
	Expr* m_left;
	Expr* m_right;
	Operator m_op;

public:
	BinaryOp(Operator op, Expr* left, Expr* right)
		: m_op(op), m_left(left), m_right(right)
	{
	}

	Expr* getLeft() { return m_left; }
	Expr* getRight() { return m_right; }

	Operator getOperator() { return m_op; }

	virtual void accept(ASTVisitor& V) override
	{
		V.visit(*this);
	}
};

class WithDecl : public AST
{
	using VarVector = llvm::SmallVector<llvm::StringRef, 8>;

	VarVector m_vars;
	Expr* m_expr;

public:
	WithDecl(VarVector vars, Expr* expr)
		: m_vars(vars), m_expr(expr)
	{
	}

	VarVector::const_iterator begin() { return m_vars.begin(); }
	VarVector::const_iterator end() { return m_vars.end(); }

	Expr* getExpr() { return m_expr; }

	virtual void accept(ASTVisitor& V) override
	{
		V.visit(*this);
	}
};

#endif // AST_H