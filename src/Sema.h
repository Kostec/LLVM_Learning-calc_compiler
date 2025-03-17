#ifndef SEMA_H
#define SEMA_H

#include "AST.h"
#include "Lexer.h"

class Sema
{
public:
	bool semantic(AST* tree);
};

#endif // !SEMA_H

