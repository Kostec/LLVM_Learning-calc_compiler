
// Generated from calc_antlr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "calc_antlrListener.h"


namespace calc_antlrCore {

/**
 * This class provides an empty implementation of calc_antlrListener,
 * which can be extended to create a listener which only needs to handle a subset
 * of the available methods.
 */
class  calc_antlrBaseListener : public calc_antlrListener {
public:

  virtual void enterCalc(calc_antlrParser::CalcContext * /*ctx*/) override { }
  virtual void exitCalc(calc_antlrParser::CalcContext * /*ctx*/) override { }

  virtual void enterExpr(calc_antlrParser::ExprContext * /*ctx*/) override { }
  virtual void exitExpr(calc_antlrParser::ExprContext * /*ctx*/) override { }

  virtual void enterFactor(calc_antlrParser::FactorContext * /*ctx*/) override { }
  virtual void exitFactor(calc_antlrParser::FactorContext * /*ctx*/) override { }

  virtual void enterTerm(calc_antlrParser::TermContext * /*ctx*/) override { }
  virtual void exitTerm(calc_antlrParser::TermContext * /*ctx*/) override { }

  virtual void enterWithDecl(calc_antlrParser::WithDeclContext * /*ctx*/) override { }
  virtual void exitWithDecl(calc_antlrParser::WithDeclContext * /*ctx*/) override { }

  virtual void enterIdent(calc_antlrParser::IdentContext * /*ctx*/) override { }
  virtual void exitIdent(calc_antlrParser::IdentContext * /*ctx*/) override { }

  virtual void enterNumber(calc_antlrParser::NumberContext * /*ctx*/) override { }
  virtual void exitNumber(calc_antlrParser::NumberContext * /*ctx*/) override { }


  virtual void enterEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void exitEveryRule(antlr4::ParserRuleContext * /*ctx*/) override { }
  virtual void visitTerminal(antlr4::tree::TerminalNode * /*node*/) override { }
  virtual void visitErrorNode(antlr4::tree::ErrorNode * /*node*/) override { }

};

}  // namespace calc_antlrCore
