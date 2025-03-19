/** 
 * myLanguage grammar implementation.
 */
 

grammar calc_antlr;
import calc_antlrLexerRules;

calc : withDecl ':' expr ';';
expr : term ((Plus|Minus) term)*;
factor: ident | number | '(' expr ')';
term : factor ((Star|Slash) factor)*;

withDecl: With ident (',' ident)*;
ident : Nondigit+;
number : Digit+;
