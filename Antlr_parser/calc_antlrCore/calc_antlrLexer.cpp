
// Generated from calc_antlr.g4 by ANTLR 4.13.2


#include "calc_antlrLexer.h"


using namespace antlr4;

using namespace calc_antlrCore;


using namespace antlr4;

namespace {

struct Calc_antlrLexerStaticData final {
  Calc_antlrLexerStaticData(std::vector<std::string> ruleNames,
                          std::vector<std::string> channelNames,
                          std::vector<std::string> modeNames,
                          std::vector<std::string> literalNames,
                          std::vector<std::string> symbolicNames)
      : ruleNames(std::move(ruleNames)), channelNames(std::move(channelNames)),
        modeNames(std::move(modeNames)), literalNames(std::move(literalNames)),
        symbolicNames(std::move(symbolicNames)),
        vocabulary(this->literalNames, this->symbolicNames) {}

  Calc_antlrLexerStaticData(const Calc_antlrLexerStaticData&) = delete;
  Calc_antlrLexerStaticData(Calc_antlrLexerStaticData&&) = delete;
  Calc_antlrLexerStaticData& operator=(const Calc_antlrLexerStaticData&) = delete;
  Calc_antlrLexerStaticData& operator=(Calc_antlrLexerStaticData&&) = delete;

  std::vector<antlr4::dfa::DFA> decisionToDFA;
  antlr4::atn::PredictionContextCache sharedContextCache;
  const std::vector<std::string> ruleNames;
  const std::vector<std::string> channelNames;
  const std::vector<std::string> modeNames;
  const std::vector<std::string> literalNames;
  const std::vector<std::string> symbolicNames;
  const antlr4::dfa::Vocabulary vocabulary;
  antlr4::atn::SerializedATNView serializedATN;
  std::unique_ptr<antlr4::atn::ATN> atn;
};

::antlr4::internal::OnceFlag calc_antlrlexerLexerOnceFlag;
#if ANTLR4_USE_THREAD_LOCAL_CACHE
static thread_local
#endif
std::unique_ptr<Calc_antlrLexerStaticData> calc_antlrlexerLexerStaticData = nullptr;

void calc_antlrlexerLexerInitialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  if (calc_antlrlexerLexerStaticData != nullptr) {
    return;
  }
#else
  assert(calc_antlrlexerLexerStaticData == nullptr);
#endif
  auto staticData = std::make_unique<Calc_antlrLexerStaticData>(
    std::vector<std::string>{
      "T__0", "T__1", "T__2", "T__3", "T__4", "Nondigit", "Digit", "Minus", 
      "Plus", "Star", "Slash", "With"
    },
    std::vector<std::string>{
      "DEFAULT_TOKEN_CHANNEL", "HIDDEN"
    },
    std::vector<std::string>{
      "DEFAULT_MODE"
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
  	4,0,12,52,6,-1,2,0,7,0,2,1,7,1,2,2,7,2,2,3,7,3,2,4,7,4,2,5,7,5,2,6,7,
  	6,2,7,7,7,2,8,7,8,2,9,7,9,2,10,7,10,2,11,7,11,1,0,1,0,1,1,1,1,1,2,1,2,
  	1,3,1,3,1,4,1,4,1,5,1,5,1,6,1,6,1,7,1,7,1,8,1,8,1,9,1,9,1,10,1,10,1,11,
  	1,11,1,11,1,11,1,11,0,0,12,1,1,3,2,5,3,7,4,9,5,11,6,13,7,15,8,17,9,19,
  	10,21,11,23,12,1,0,6,2,0,65,90,97,122,1,0,48,57,2,0,87,87,119,119,2,0,
  	73,73,105,105,2,0,84,84,116,116,2,0,72,72,104,104,51,0,1,1,0,0,0,0,3,
  	1,0,0,0,0,5,1,0,0,0,0,7,1,0,0,0,0,9,1,0,0,0,0,11,1,0,0,0,0,13,1,0,0,0,
  	0,15,1,0,0,0,0,17,1,0,0,0,0,19,1,0,0,0,0,21,1,0,0,0,0,23,1,0,0,0,1,25,
  	1,0,0,0,3,27,1,0,0,0,5,29,1,0,0,0,7,31,1,0,0,0,9,33,1,0,0,0,11,35,1,0,
  	0,0,13,37,1,0,0,0,15,39,1,0,0,0,17,41,1,0,0,0,19,43,1,0,0,0,21,45,1,0,
  	0,0,23,47,1,0,0,0,25,26,5,58,0,0,26,2,1,0,0,0,27,28,5,59,0,0,28,4,1,0,
  	0,0,29,30,5,40,0,0,30,6,1,0,0,0,31,32,5,41,0,0,32,8,1,0,0,0,33,34,5,44,
  	0,0,34,10,1,0,0,0,35,36,7,0,0,0,36,12,1,0,0,0,37,38,7,1,0,0,38,14,1,0,
  	0,0,39,40,5,45,0,0,40,16,1,0,0,0,41,42,5,43,0,0,42,18,1,0,0,0,43,44,5,
  	42,0,0,44,20,1,0,0,0,45,46,5,47,0,0,46,22,1,0,0,0,47,48,7,2,0,0,48,49,
  	7,3,0,0,49,50,7,4,0,0,50,51,7,5,0,0,51,24,1,0,0,0,1,0,0
  };
  staticData->serializedATN = antlr4::atn::SerializedATNView(serializedATNSegment, sizeof(serializedATNSegment) / sizeof(serializedATNSegment[0]));

  antlr4::atn::ATNDeserializer deserializer;
  staticData->atn = deserializer.deserialize(staticData->serializedATN);

  const size_t count = staticData->atn->getNumberOfDecisions();
  staticData->decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    staticData->decisionToDFA.emplace_back(staticData->atn->getDecisionState(i), i);
  }
  calc_antlrlexerLexerStaticData = std::move(staticData);
}

}

calc_antlrLexer::calc_antlrLexer(CharStream *input) : Lexer(input) {
  calc_antlrLexer::initialize();
  _interpreter = new atn::LexerATNSimulator(this, *calc_antlrlexerLexerStaticData->atn, calc_antlrlexerLexerStaticData->decisionToDFA, calc_antlrlexerLexerStaticData->sharedContextCache);
}

calc_antlrLexer::~calc_antlrLexer() {
  delete _interpreter;
}

std::string calc_antlrLexer::getGrammarFileName() const {
  return "calc_antlr.g4";
}

const std::vector<std::string>& calc_antlrLexer::getRuleNames() const {
  return calc_antlrlexerLexerStaticData->ruleNames;
}

const std::vector<std::string>& calc_antlrLexer::getChannelNames() const {
  return calc_antlrlexerLexerStaticData->channelNames;
}

const std::vector<std::string>& calc_antlrLexer::getModeNames() const {
  return calc_antlrlexerLexerStaticData->modeNames;
}

const dfa::Vocabulary& calc_antlrLexer::getVocabulary() const {
  return calc_antlrlexerLexerStaticData->vocabulary;
}

antlr4::atn::SerializedATNView calc_antlrLexer::getSerializedATN() const {
  return calc_antlrlexerLexerStaticData->serializedATN;
}

const atn::ATN& calc_antlrLexer::getATN() const {
  return *calc_antlrlexerLexerStaticData->atn;
}




void calc_antlrLexer::initialize() {
#if ANTLR4_USE_THREAD_LOCAL_CACHE
  calc_antlrlexerLexerInitialize();
#else
  ::antlr4::internal::call_once(calc_antlrlexerLexerOnceFlag, calc_antlrlexerLexerInitialize);
#endif
}
