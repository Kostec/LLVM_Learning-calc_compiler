
// Generated from calc_antlr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "calc_antlrParser.h"


namespace calc_antlrCore {

/**
 * This interface defines an abstract listener for a parse tree produced by calc_antlrParser.
 */
class  calc_antlrListener : public antlr4::tree::ParseTreeListener {
public:

  virtual void enterCalc(calc_antlrParser::CalcContext *ctx) = 0;
  virtual void exitCalc(calc_antlrParser::CalcContext *ctx) = 0;

  virtual void enterExpr(calc_antlrParser::ExprContext *ctx) = 0;
  virtual void exitExpr(calc_antlrParser::ExprContext *ctx) = 0;

  virtual void enterFactor(calc_antlrParser::FactorContext *ctx) = 0;
  virtual void exitFactor(calc_antlrParser::FactorContext *ctx) = 0;

  virtual void enterTerm(calc_antlrParser::TermContext *ctx) = 0;
  virtual void exitTerm(calc_antlrParser::TermContext *ctx) = 0;

  virtual void enterWithDecl(calc_antlrParser::WithDeclContext *ctx) = 0;
  virtual void exitWithDecl(calc_antlrParser::WithDeclContext *ctx) = 0;

  virtual void enterIdent(calc_antlrParser::IdentContext *ctx) = 0;
  virtual void exitIdent(calc_antlrParser::IdentContext *ctx) = 0;

  virtual void enterNumber(calc_antlrParser::NumberContext *ctx) = 0;
  virtual void exitNumber(calc_antlrParser::NumberContext *ctx) = 0;


};

}  // namespace calc_antlrCore
