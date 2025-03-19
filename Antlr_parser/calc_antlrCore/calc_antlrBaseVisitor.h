
// Generated from calc_antlr.g4 by ANTLR 4.13.2

#pragma once


#include "antlr4-runtime.h"
#include "calc_antlrVisitor.h"


namespace calc_antlrCore {

/**
 * This class provides an empty implementation of calc_antlrVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  calc_antlrBaseVisitor : public calc_antlrVisitor {
public:

  virtual std::any visitCalc(calc_antlrParser::CalcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitExpr(calc_antlrParser::ExprContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitFactor(calc_antlrParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitTerm(calc_antlrParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitWithDecl(calc_antlrParser::WithDeclContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitIdent(calc_antlrParser::IdentContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual std::any visitNumber(calc_antlrParser::NumberContext *ctx) override {
    return visitChildren(ctx);
  }


};

}  // namespace calc_antlrCore
