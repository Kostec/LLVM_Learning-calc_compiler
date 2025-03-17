#include "Lexer.h"

namespace charInfo
{
	LLVM_READNONE inline bool isWhitespace(char c)
	{
		return c == ' ' || c == '\t' || c == '\f' ||
			c == '/v' || c == '\r' || c == '\n';
	}

	LLVM_READNONE inline bool isDigit(char c)
	{
		return c >= '0' && c <= '9';
	}

	LLVM_READNONE inline bool isLetter(char c)
	{
		return (c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z');
	}
}


void Lexer::next(Token& token)
{
	while (*m_bufferPtr && charInfo::isWhitespace(*m_bufferPtr))
	{
		++m_bufferPtr;
	}

	if (!*m_bufferPtr)
	{
		// No tokens any more
		//token.m_kind == Token::eoi;
		fromToken(token, m_bufferPtr, Token::eoi);
		return;
	}

	if (charInfo::isLetter(*m_bufferPtr))
	{
		// Letter token
		const char* end = m_bufferPtr+1;
		while (charInfo::isLetter(*end))
		{
			end++;
		}

		llvm::StringRef Name(m_bufferPtr, end - m_bufferPtr);
		Token::TokenKind kind = Name == llvm::StringRef("with") ? Token::KW_with : Token::ident;
		fromToken(token, end, kind);
		return;
	}

	if (charInfo::isDigit(*m_bufferPtr))
	{
		// Digit token
		const char* end = m_bufferPtr + 1;
		while (charInfo::isDigit(*end))
		{
			end++;
		}

		fromToken(token, end, Token::number);
	}
	else
	{
		switch (*m_bufferPtr)
		{
			#define CASE(ch, tok) case ch: fromToken(token, m_bufferPtr + 1, tok); break
				CASE('+', Token::plus);
				CASE('-', Token::minus);
				CASE('*', Token::star);
				CASE('/', Token::slash);
				CASE('(', Token::l_paren);
				CASE(')', Token::r_paren);
				CASE(':', Token::colon);
				CASE(',', Token::comma);
			#undef CASE
			default:
				fromToken(token, m_bufferPtr + 1, Token::unknown);
				break;
		}
	}
}

void Lexer::fromToken(Token& tok, const char* TokEnd, Token::TokenKind Kind)
{
	tok.m_kind = Kind;
	tok.m_text = llvm::StringRef(m_bufferPtr, TokEnd - m_bufferPtr);
	m_bufferPtr = TokEnd;
}
