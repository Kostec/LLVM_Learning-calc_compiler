#ifndef PARSER_H
#define PARSER_H

#include "AST.h"
#include "Lexer.h"
#include "llvm/Support/raw_ostream.h"

class Parser
{
private:
	Lexer& m_lexer;
	Token m_token;
	bool m_hasError;

	void error() {
		llvm::errs() << "Unexpected " << m_token.getText() << "\n";
		m_hasError = true;
	}

	void advance()
	{
		m_lexer.next(m_token);
	}

	bool expect(Token::TokenKind kind)
	{
		if (!m_token.is(kind))
		{
			error();
			return true;
		}
		return false;
	}

	bool consume(Token::TokenKind kind)
	{
		if (expect(kind))
		{
			return true;
		}
		advance();
		return false;
	}

	AST* parseCalc();
	Expr* parseExpr();
	Expr* parseTerm();
	Expr* parseFactor();

public:
	Parser(Lexer& lexer) 
		: m_lexer(lexer), m_hasError(false)
	{
		advance();
	}

	bool hasError()
	{
		return m_hasError;
	}

	AST* parse();
};


#endif // !PARSER_H
