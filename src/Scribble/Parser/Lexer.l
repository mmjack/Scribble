%option yylineno
%option noyywrap
%option nounput
%option prefix="scribble_"

%x C_COMMENT

%{
#include <Scribble/Function/Function.hpp>
#include <string>
#include <vector>
#include <Scribble/Statement/IntStatement.hpp>
#include <Pointers/SmartPointer.hpp>
#include <Scribble/Value/Variable.hpp>
#include <Scribble/Value/StructureInfo.hpp>
#include <Scribble/Parser/TypeReference.hpp>
#include "Parser.hpp"

#define SAVE_INT scribble_lval.integer = atoi(scribble_text);
#define SAVE_REAL scribble_lval.real = atof(scribble_text);
#define SAVE_TOKEN scribble_lval.string = new std::string(scribble_text, scribble_leng);

void myReplace(std::string& str, const std::string& oldStr, const std::string& newStr)
{
  size_t pos = 0;
  while((pos = str.find(oldStr, pos)) != std::string::npos)
  {
     str.replace(pos, oldStr.length(), newStr);
     pos += newStr.length();
  }
}

%}

white [ \t]+
digit [0-9]
integer {digit}+
exponent [eE][+-]?{integer}
real {integer}("."{integer})
string \"[^\"\n]*\"
word [_|a-z|A-Z][a-z|A-Z|0-9]*

%%

"//"            { BEGIN(C_COMMENT); }
<C_COMMENT>"\n" { BEGIN(INITIAL); }
<C_COMMENT>.    { }
{white} { }
"++" return TWOPLUS;
"+" return PLUS;
"--" return TWOMINUS;
"-" return MINUS;
"*" return TIMES;
"/" return DIVIDE;
"^" return POWER;
"=" return EQUALS;
":=" return ASSIGN;
"&" return AND;
"(" return LPAREN;
")" return RPAREN;
"{" return LBRACKET;
"}" return RBRACKET;
"," return COMMA;
";" return END;
":" return COLON;
">" return GREATER;
"<" return LESSER;
"!" return NOT;
"\n" ;
"then" return THEN;
"if" return IF;
"else" return ELSE;
"struct" return STRUCT;
"func" return FUNCTION;
"for" return FOR;
"var" return VARIABLE;
"const" return CONST;
"int" return TYPE_INT;
"bool" return TYPE_BOOL;
"nil" return NIL;
"string" return TYPE_STRING;
"void" return TYPE_VOID;
"return" return RETURN;
"while" return WHILE;
"import" return IMPORT;
"true" return TRUE;
"false" return FALSE;
"type" return TYPE;
"." return LINK;
"->" return POINT;
"array" return TYPE_ARRAY;
"len" return LENGTH;
"thread" return THREAD;
"[" return LSQBRACKET;
"]" return RSQBRACKET;;

{integer} { SAVE_INT;
 return INT;
}

{real} { SAVE_REAL; 
 return REAL;
}

{word} { SAVE_TOKEN; return WORD; }
{string} { std::string r(scribble_text, scribble_leng); myReplace(r, "\\n", "\n"); myReplace(r, "\"", ""); scribble_lval.string = new std::string(r); return STRING; }