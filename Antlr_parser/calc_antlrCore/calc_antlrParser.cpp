
// Generated from calc_antlr.g4 by ANTLR 4.13.2


#include "calc_antlrListener.h"
#include "calc_antlrVisitor.h"

#include "calc_antlrParser.h"


using namespace antlrcpp;
using namespace calc_antlrCore;

using namespace antlr4;

namespace {

struct Calc_antlrParserStaticData final {
  Calc_antlrParserStaticData(std::vector<std::string> ruleNames,
                        std::vector<std::string> literalNames,
                        std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Calc_antlrParserStaticData(const Calc_antlrParserStaticData&) = delete;
  Calc_antlrParserStaticData(Calc_antlrParserStaticData&&) = delete;
  Calc_antlrParserStaticData& operator=(const Calc_antlrParserStaticData&) = delete;
  Calc_antlrParserStaticData& operator=(Calc_antlrParserStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calc_antlrParserOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Calc_antlrParserStaticData> calc_antlrParserStaticData = nullptr;

void calc_antlrParserInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (calc_antlrParserStaticData != nullptr) {
    return;
  }
#else
  assert(calc_antlrParserStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Calc_antlrParserStaticData>(
    std::vector<std::string>{
      "calc", "expr", "factor", "term", "withDecl", "ident", "number"
    },
    std::vector<std::string>{
      "", "':'", "';'", "'('", "')'", "','", "", "", "'-'", "'+'", "'*'", 
      "'/'"
    },
    std::vector<std::string>{
      "", "", "", "", "", "", "Nondigit", "Digit", "Minus", "Plus", "Star", 
      "Slash", "With"
    }
  );
  static const int32_t serializedATNSegment[] = {
  	4,1,12,63,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,6,1,0,
  	1,0,1,0,1,0,1,0,1,1,1,1,1,1,5,1,23,8,1,10,1,12,1,26,9,1,1,2,1,2,1,2,1,
  	2,1,2,1,2,3,2,34,8,2,1,3,1,3,1,3,5,3,39,8,3,10,3,12,3,42,9,3,1,4,1,4,
  	1,4,1,4,5,4,48,8,4,10,4,12,4,51,9,4,1,5,4,5,54,8,5,11,5,12,5,55,1,6,4,
  	6,59,8,6,11,6,12,6,60,1,6,0,0,7,0,2,4,6,8,10,12,0,2,1,0,8,9,1,0,10,11,
  	62,0,14,1,0,0,0,2,19,1,0,0,0,4,33,1,0,0,0,6,35,1,0,0,0,8,43,1,0,0,0,10,
  	53,1,0,0,0,12,58,1,0,0,0,14,15,3,8,4,0,15,16,5,1,0,0,16,17,3,2,1,0,17,
  	18,5,2,0,0,18,1,1,0,0,0,19,24,3,6,3,0,20,21,7,0,0,0,21,23,3,6,3,0,22,
  	20,1,0,0,0,23,26,1,0,0,0,24,22,1,0,0,0,24,25,1,0,0,0,25,3,1,0,0,0,26,
  	24,1,0,0,0,27,34,3,10,5,0,28,34,3,12,6,0,29,30,5,3,0,0,30,31,3,2,1,0,
  	31,32,5,4,0,0,32,34,1,0,0,0,33,27,1,0,0,0,33,28,1,0,0,0,33,29,1,0,0,0,
  	34,5,1,0,0,0,35,40,3,4,2,0,36,37,7,1,0,0,37,39,3,4,2,0,38,36,1,0,0,0,
  	39,42,1,0,0,0,40,38,1,0,0,0,40,41,1,0,0,0,41,7,1,0,0,0,42,40,1,0,0,0,
  	43,44,5,12,0,0,44,49,3,10,5,0,45,46,5,5,0,0,46,48,3,10,5,0,47,45,1,0,
  	0,0,48,51,1,0,0,0,49,47,1,0,0,0,49,50,1,0,0,0,50,9,1,0,0,0,51,49,1,0,
  	0,0,52,54,5,6,0,0,53,52,1,0,0,0,54,55,1,0,0,0,55,53,1,0,0,0,55,56,1,0,
  	0,0,56,11,1,0,0,0,57,59,5,7,0,0,58,57,1,0,0,0,59,60,1,0,0,0,60,58,1,0,
  	0,0,60,61,1,0,0,0,61,13,1,0,0,0,6,24,33,40,49,55,60
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calc_antlrParserStaticData = std::move(staticData);
}

}

calc_antlrParser::calc_antlrParser(TokenStream *input) : calc_antlrParser(input, antlr4::atn::ParserATNSimulatorOptions()) {}

calc_antlrParser::calc_antlrParser(TokenStream *input, const antlr4::atn::ParserATNSimulatorOptions &options) : Parser(input) {
  calc_antlrParser::initialize();
  _interpreter = new atn::ParserATNSimulator(this, *calc_antlrParserStaticData->atn, calc_antlrParserStaticData->decisionToDFA, calc_antlrParserStaticData->sharedContextCache, options);
}

calc_antlrParser::~calc_antlrParser() {
  delete _interpreter;
}

const atn::ATN& calc_antlrParser::getATN() const {
  return *calc_antlrParserStaticData->atn;
}

std::string calc_antlrParser::getGrammarFileName() const {
  return "calc_antlr.g4";
}

const std::vector<std::string>& calc_antlrParser::getRuleNames() const {
  return calc_antlrParserStaticData->ruleNames;
}

const dfa::Vocabulary& calc_antlrParser::getVocabulary() const {
  return calc_antlrParserStaticData->vocabulary;
}

antlr4::atn::SerializedATNView calc_antlrParser::getSerializedATN() const {
  return calc_antlrParserStaticData->serializedATN;
}


//----------------- CalcContext ------------------------------------------------------------------

calc_antlrParser::CalcContext::CalcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

calc_antlrParser::WithDeclContext* calc_antlrParser::CalcContext::withDecl() {
  return getRuleContext<calc_antlrParser::WithDeclContext>(0);
}

calc_antlrParser::ExprContext* calc_antlrParser::CalcContext::expr() {
  return getRuleContext<calc_antlrParser::ExprContext>(0);
}


size_t calc_antlrParser::CalcContext::getRuleIndex() const {
  return calc_antlrParser::RuleCalc;
}

void calc_antlrParser::CalcContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterCalc(this);
}

void calc_antlrParser::CalcContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitCalc(this);
}


std::any calc_antlrParser::CalcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitCalc(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::CalcContext* calc_antlrParser::calc() {
  CalcContext *_localctx = _tracker.createInstance<CalcContext>(_ctx, getState());
  enterRule(_localctx, 0, calc_antlrParser::RuleCalc);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(14);
    withDecl();
    setState(15);
    match(calc_antlrParser::T__0);
    setState(16);
    expr();
    setState(17);
    match(calc_antlrParser::T__1);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExprContext ------------------------------------------------------------------

calc_antlrParser::ExprContext::ExprContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<calc_antlrParser::TermContext *> calc_antlrParser::ExprContext::term() {
  return getRuleContexts<calc_antlrParser::TermContext>();
}

calc_antlrParser::TermContext* calc_antlrParser::ExprContext::term(size_t i) {
  return getRuleContext<calc_antlrParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> calc_antlrParser::ExprContext::Plus() {
  return getTokens(calc_antlrParser::Plus);
}

tree::TerminalNode* calc_antlrParser::ExprContext::Plus(size_t i) {
  return getToken(calc_antlrParser::Plus, i);
}

std::vector<tree::TerminalNode *> calc_antlrParser::ExprContext::Minus() {
  return getTokens(calc_antlrParser::Minus);
}

tree::TerminalNode* calc_antlrParser::ExprContext::Minus(size_t i) {
  return getToken(calc_antlrParser::Minus, i);
}


size_t calc_antlrParser::ExprContext::getRuleIndex() const {
  return calc_antlrParser::RuleExpr;
}

void calc_antlrParser::ExprContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterExpr(this);
}

void calc_antlrParser::ExprContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitExpr(this);
}


std::any calc_antlrParser::ExprContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitExpr(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::ExprContext* calc_antlrParser::expr() {
  ExprContext *_localctx = _tracker.createInstance<ExprContext>(_ctx, getState());
  enterRule(_localctx, 2, calc_antlrParser::RuleExpr);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(19);
    term();
    setState(24);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == calc_antlrParser::Minus

    || _la == calc_antlrParser::Plus) {
      setState(20);
      _la = _input->LA(1);
      if (!(_la == calc_antlrParser::Minus

      || _la == calc_antlrParser::Plus)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(21);
      term();
      setState(26);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

calc_antlrParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

calc_antlrParser::IdentContext* calc_antlrParser::FactorContext::ident() {
  return getRuleContext<calc_antlrParser::IdentContext>(0);
}

calc_antlrParser::NumberContext* calc_antlrParser::FactorContext::number() {
  return getRuleContext<calc_antlrParser::NumberContext>(0);
}

calc_antlrParser::ExprContext* calc_antlrParser::FactorContext::expr() {
  return getRuleContext<calc_antlrParser::ExprContext>(0);
}


size_t calc_antlrParser::FactorContext::getRuleIndex() const {
  return calc_antlrParser::RuleFactor;
}

void calc_antlrParser::FactorContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterFactor(this);
}

void calc_antlrParser::FactorContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitFactor(this);
}


std::any calc_antlrParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::FactorContext* calc_antlrParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 4, calc_antlrParser::RuleFactor);

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    setState(33);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case calc_antlrParser::Nondigit: {
        enterOuterAlt(_localctx, 1);
        setState(27);
        ident();
        break;
      }

      case calc_antlrParser::Digit: {
        enterOuterAlt(_localctx, 2);
        setState(28);
        number();
        break;
      }

      case calc_antlrParser::T__2: {
        enterOuterAlt(_localctx, 3);
        setState(29);
        match(calc_antlrParser::T__2);
        setState(30);
        expr();
        setState(31);
        match(calc_antlrParser::T__3);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

calc_antlrParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<calc_antlrParser::FactorContext *> calc_antlrParser::TermContext::factor() {
  return getRuleContexts<calc_antlrParser::FactorContext>();
}

calc_antlrParser::FactorContext* calc_antlrParser::TermContext::factor(size_t i) {
  return getRuleContext<calc_antlrParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> calc_antlrParser::TermContext::Star() {
  return getTokens(calc_antlrParser::Star);
}

tree::TerminalNode* calc_antlrParser::TermContext::Star(size_t i) {
  return getToken(calc_antlrParser::Star, i);
}

std::vector<tree::TerminalNode *> calc_antlrParser::TermContext::Slash() {
  return getTokens(calc_antlrParser::Slash);
}

tree::TerminalNode* calc_antlrParser::TermContext::Slash(size_t i) {
  return getToken(calc_antlrParser::Slash, i);
}


size_t calc_antlrParser::TermContext::getRuleIndex() const {
  return calc_antlrParser::RuleTerm;
}

void calc_antlrParser::TermContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterTerm(this);
}

void calc_antlrParser::TermContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitTerm(this);
}


std::any calc_antlrParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::TermContext* calc_antlrParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 6, calc_antlrParser::RuleTerm);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(35);
    factor();
    setState(40);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == calc_antlrParser::Star

    || _la == calc_antlrParser::Slash) {
      setState(36);
      _la = _input->LA(1);
      if (!(_la == calc_antlrParser::Star

      || _la == calc_antlrParser::Slash)) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(37);
      factor();
      setState(42);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- WithDeclContext ------------------------------------------------------------------

calc_antlrParser::WithDeclContext::WithDeclContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* calc_antlrParser::WithDeclContext::With() {
  return getToken(calc_antlrParser::With, 0);
}

std::vector<calc_antlrParser::IdentContext *> calc_antlrParser::WithDeclContext::ident() {
  return getRuleContexts<calc_antlrParser::IdentContext>();
}

calc_antlrParser::IdentContext* calc_antlrParser::WithDeclContext::ident(size_t i) {
  return getRuleContext<calc_antlrParser::IdentContext>(i);
}


size_t calc_antlrParser::WithDeclContext::getRuleIndex() const {
  return calc_antlrParser::RuleWithDecl;
}

void calc_antlrParser::WithDeclContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterWithDecl(this);
}

void calc_antlrParser::WithDeclContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitWithDecl(this);
}


std::any calc_antlrParser::WithDeclContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitWithDecl(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::WithDeclContext* calc_antlrParser::withDecl() {
  WithDeclContext *_localctx = _tracker.createInstance<WithDeclContext>(_ctx, getState());
  enterRule(_localctx, 8, calc_antlrParser::RuleWithDecl);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(43);
    match(calc_antlrParser::With);
    setState(44);
    ident();
    setState(49);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == calc_antlrParser::T__4) {
      setState(45);
      match(calc_antlrParser::T__4);
      setState(46);
      ident();
      setState(51);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- IdentContext ------------------------------------------------------------------

calc_antlrParser::IdentContext::IdentContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> calc_antlrParser::IdentContext::Nondigit() {
  return getTokens(calc_antlrParser::Nondigit);
}

tree::TerminalNode* calc_antlrParser::IdentContext::Nondigit(size_t i) {
  return getToken(calc_antlrParser::Nondigit, i);
}


size_t calc_antlrParser::IdentContext::getRuleIndex() const {
  return calc_antlrParser::RuleIdent;
}

void calc_antlrParser::IdentContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterIdent(this);
}

void calc_antlrParser::IdentContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitIdent(this);
}


std::any calc_antlrParser::IdentContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitIdent(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::IdentContext* calc_antlrParser::ident() {
  IdentContext *_localctx = _tracker.createInstance<IdentContext>(_ctx, getState());
  enterRule(_localctx, 10, calc_antlrParser::RuleIdent);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(53); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(52);
      match(calc_antlrParser::Nondigit);
      setState(55); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == calc_antlrParser::Nondigit);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- NumberContext ------------------------------------------------------------------

calc_antlrParser::NumberContext::NumberContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> calc_antlrParser::NumberContext::Digit() {
  return getTokens(calc_antlrParser::Digit);
}

tree::TerminalNode* calc_antlrParser::NumberContext::Digit(size_t i) {
  return getToken(calc_antlrParser::Digit, i);
}


size_t calc_antlrParser::NumberContext::getRuleIndex() const {
  return calc_antlrParser::RuleNumber;
}

void calc_antlrParser::NumberContext::enterRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->enterNumber(this);
}

void calc_antlrParser::NumberContext::exitRule(tree::ParseTreeListener *listener) {
  auto parserListener = dynamic_cast<calc_antlrListener *>(listener);
  if (parserListener != nullptr)
    parserListener->exitNumber(this);
}


std::any calc_antlrParser::NumberContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<calc_antlrVisitor*>(visitor))
    return parserVisitor->visitNumber(this);
  else
    return visitor->visitChildren(this);
}

calc_antlrParser::NumberContext* calc_antlrParser::number() {
  NumberContext *_localctx = _tracker.createInstance<NumberContext>(_ctx, getState());
  enterRule(_localctx, 12, calc_antlrParser::RuleNumber);
  size_t _la = 0;

#if __cplusplus > 201703L
  auto onExit = finally([=, this] {
#else
  auto onExit = finally([=] {
#endif
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(58); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(57);
      match(calc_antlrParser::Digit);
      setState(60); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == calc_antlrParser::Digit);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

void calc_antlrParser::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  calc_antlrParserInitialize();
#else
  ::antlr4::internal::call_once(calc_antlrParserOnceFlag, calc_antlrParserInitialize);
#endif
}
