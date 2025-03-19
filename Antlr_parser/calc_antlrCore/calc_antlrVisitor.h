
// Generated from calc_antlr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "calc_antlrParser.h"


namespace calc_antlrCore {

/**
 * This class defines an abstract visitor for a parse tree
 * produced by calc_antlrParser.
 */
class  calc_antlrVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by calc_antlrParser.
   */
    virtual std::any visitCalc(calc_antlrParser::CalcContext *context) = 0;

    virtual std::any visitExpr(calc_antlrParser::ExprContext *context) = 0;

    virtual std::any visitFactor(calc_antlrParser::FactorContext *context) = 0;

    virtual std::any visitTerm(calc_antlrParser::TermContext *context) = 0;

    virtual std::any visitWithDecl(calc_antlrParser::WithDeclContext *context) = 0;

    virtual std::any visitIdent(calc_antlrParser::IdentContext *context) = 0;

    virtual std::any visitNumber(calc_antlrParser::NumberContext *context) = 0;


};

}  // namespace calc_antlrCore
