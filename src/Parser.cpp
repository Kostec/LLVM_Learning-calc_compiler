#include "Parser.h"

AST* Parser::parse()
{
	AST* res = parseCalc();
	expect(Token::eoi);
	return res;
}

AST* Parser::parseCalc()
{
	Expr* E;
	llvm::SmallVector<llvm::StringRef, 8> vars;
	if (m_token.is(Token::KW_with))
	{
		advance();

		if (expect(Token::ident))
		{
			goto _error; // TODO: WTF? Find way to avoid goto
		}
		vars.push_back(m_token.getText());
		advance();

		while (m_token.is(Token::comma))
		{
			advance();
			if (expect(Token::ident))
			{
				goto _error;
			}
			vars.push_back(m_token.getText());
			advance();
		}

		if (consume(Token::colon))
		{
			goto _error;
		}

		E = parseExpr();

		if (vars.empty())
		{
			return E;
		}
		else
		{
			return new WithDecl(vars, E);
		}

		return nullptr;

	_error:
		while (!m_token.is(Token::eoi))
		{
			advance();
		}
	}

	return nullptr;
}

Expr* Parser::parseExpr()
{
	Expr* left = parseTerm();
	while (m_token.isOneOf(Token::plus, Token::minus))
	{
		BinaryOp::Operator op = m_token.is(Token::plus) ? BinaryOp::Plus : BinaryOp::Minus;
		advance();
		Expr* right = parseTerm();
		left = new BinaryOp(op, left, right);
	}
	return left;
}

Expr* Parser::parseTerm()
{
	Expr* left = parseFactor();
	Expr* res = nullptr;
	while (m_token.isOneOf(Token::star, Token::slash))
	{
		BinaryOp::Operator op = m_token.is(Token::star) ? BinaryOp::Mul : BinaryOp::Div;
		advance();
		Expr* right = parseFactor();
		res = new BinaryOp(op, left, right);
	}
	return left;
}

Expr* Parser::parseFactor()
{
	Expr* res = nullptr;
	
	switch (m_token.getKind())
	{
	case Token::number:
		res = new Factor(Factor::Number, m_token.getText());
		advance();
		break;
	case Token::ident:
		res = new Factor(Factor::Ident, m_token.getText());
		advance();
		break;
	case Token::l_paren:
		advance();
		res = parseExpr();
		if (!consume(Token::r_paren))
		{
			break;
		}
		break;
	default:
		if (!res)
		{
			error();
		}
	}

	return res;
}