#ifndef TOKEN_H
#define TOKEN_H

#include "llvm/ADT/StringRef.h"
#include "llvm/Support/MemoryBuffer.h"

class Token {
	friend class Lexer;

public:
	enum TokenKind : unsigned short
	{
		eoi, unknown,
		ident, number,
		comma, colon, plus, minus, star, slash, 
		l_paren, r_paren, 
		KW_with
	};

	llvm::StringRef getText() const { return m_text; }
	TokenKind getKind() const { return m_kind; }

	bool is(TokenKind K) const { return m_kind == K; }
	bool isOneOf(TokenKind K1, TokenKind K2) const {
		return is(K1) || is(K2);
	}
	template <typename... Ts>
	bool isOneOf(TokenKind K1, TokenKind K2, Ts... Ks) const
	{
		return is(K1) || isOneOf(K2, Ks...);
	}


private:
	TokenKind m_kind;
	llvm::StringRef m_text;

};

#endif // !TOKEN_H

