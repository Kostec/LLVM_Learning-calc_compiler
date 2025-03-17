#ifndef LEXER_H
#define LEXER_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"

#include "Token.h"

class Lexer
{
private:
	const char* m_bufferStart;
	const char* m_bufferPtr;

public:
	Lexer(const llvm::StringRef& buffer)
	{
		m_bufferStart = buffer.begin();
		m_bufferPtr = m_bufferStart;
	}

	void next(Token& token);

private:
	void fromToken(Token& result, const char* TokEnd, Token::TokenKind Kind);
};

#endif LEXER_H

