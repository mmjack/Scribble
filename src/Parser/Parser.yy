%error-verbose
%locations

%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <Statement/BoolStatement.hpp>
#include <Statement/IntStatement.hpp>
#include <Statement/OperateStatement.hpp>
#include <Statement/StringStatement.hpp>
#include <Statement/AssignVariable.hpp>
#include <Statement/GetVariableStatement.hpp>
#include <Statement/FunctionStatement.hpp>
#include <Statement/ForStatement.hpp>
#include <Statement/TestStatement.hpp>
#include <Statement/IfStatement.hpp>
#include <Statement/OperateStatement.hpp>
#include <Statement/ReturnStatement.hpp>
#include <Statement/WhileStatement.hpp>
#include <Statement/IncrementStatement.hpp>
#include <Statement/ArrayStatement.hpp>
#include <Statement/AssignArrayStatement.hpp>
#include <Statement/GetArrayStatement.hpp>
#include <Pointers/SmartPointer.hpp>
#include <Function/Function.hpp>
#include <Function/ScriptedFunction.hpp>
#include <Function/WriteFunction.hpp>
#include <Value/TypeManager.hpp>
#include <Value/Util.hpp>
#include <Parser/Parser.hpp>

#include <Value/Variable.hpp>
#include <Value/String.hpp>

int yylex();
void yyerror(const char* s);

bool ParsingError;
std::vector<std::string> ImportList;
std::map<std::string, SP<Variable>> Variables;

std::map<std::string, NamespaceType> Namespace;
NamespaceType Functions;

std::vector<Reference> References;

void parser_free_all() {
	ImportList.clear();
	Variables.clear();
	Namespace.clear();
	Functions.clear();
	References.clear();
	ParsingError = false;
}

extern int yylineno;	// defined and maintained in lex.c
extern char *yytext;	// defined and maintained in lex.c

%}

%union {
	std::string* string;
	std::vector<SmartPointer<Statement>>* statements;
	std::vector<SmartPointer<Variable>>* variables;
	Statement* statement;
	Function* function;
	SP<Variable>* variable;
	float real;
	int integer;
	Type* type;
}

%token <string> WORD STRING
%token <real> REAL
%token <integer> INT
%token <token> PLUS MINUS TIMES DIVIDE POWER EQUALS ASSIGN IF ELSE GREATER LESSER FOR TYPE_ARRAY TYPE_VOID RETURN WHILE NOT IMPORT LINK
%token <token> LPAREN RPAREN LBRACKET RBRACKET COMMA TWOMINUS TWOPLUS TYPE_BOOL TRUE FALSE AUTO
%token <token> FUNCTION VARIABLE CONST STRUCT
%token <token> TYPE_INT TYPE_STRING COLON LSQBRACKET RSQBRACKET
%token <token> END

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%right POWER

%type <statement> Statement;
%type <statements> Program;
%type <variable> Variable;
%type <variable> ArgumentDefinition;
%type <statements> Arguments;
%type <statements> Statements;
%type <function> Function;
%type <variables> ArgumentDefinitions;
%type <statement> AutoVariable;
%type <type> Type;
%type <statement> FunctionCall

%start Program
%%

Program: {
		Variables.clear();
		$$ = 0;
	} | Program IMPORT LPAREN STRING RPAREN {
		ImportList.push_back(*$4);
		delete $4;
		$$ = 0;
	} | Program Function {
		$$ = 0;
	}
;

Type: TYPE_INT {
		$$ = getTypeManager().getType(Int);
	} | TYPE_STRING {
		$$ = getTypeManager().getType(String);
	} | TYPE_BOOL {
		$$ = getTypeManager().getType(Boolean);
	} | TYPE_VOID {
		$$ = getTypeManager().getType(Void);
	} | TYPE_ARRAY LPAREN Type RPAREN {
		$$ = getTypeManager().getType(Array, $3);
	}
;

Variable:  VARIABLE WORD COLON Type {

		if (($4)->getType() == Void) {
			yyerror("Cannot declare a variable as a void.");
			return -1;
		}

		auto it = Variables.find(*$2);
			
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, ValueUtil::generateValue($4)));
			Variables[*$2] = *nVar;
			$$ = nVar;
		}
		
		delete $2;
	}
;

AutoVariable: VARIABLE WORD ASSIGN Statement {

		auto it = Variables.find(*$2);
				
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
		
			SafeStatement sp = $4;
		
			SP<Variable> nVar = SP<Variable>(new Variable(0, nullptr));
			Variables[*$2] = nVar;
			
			Reference r;
			r.fRef = 0;
			r.avRef = AutoVariablePair(nVar, sp);
			References.push_back(r);			

			$$ = new AssignVariableStatement(yylineno, yytext, nVar, sp);
		}
		
		delete $2;
	}
;

ArgumentDefinition: WORD COLON Type {

		if (($3)->getType() == Void) {
			yyerror("Cannot declare a variable as a void.");
			return -1;
		}

		auto it = Variables.find(*$1);
			
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, ValueUtil::generateValue($3)));
			Variables[*$1] = *nVar;
			$$ = nVar;
		}
		
		delete $1;
	}
;

ArgumentDefinitions: ArgumentDefinition {
		$$ = new std::vector<SP<Variable>>();
		$$->push_back(*$1);
		delete $1;
	} | ArgumentDefinitions COMMA ArgumentDefinition {
		$$ = $1;
		$$->push_back(*$3);
		delete $3;
	}
;

Function: FUNCTION WORD LPAREN ArgumentDefinitions RPAREN COLON Type LBRACKET Statements RBRACKET {
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}

		SP<Function> fn = new ScriptedFunction($7, ValueUtil::generateValue($7), *$9, values, *$4);
		
		if ( Functions[*$2].size() > 0) {
		
			if (!(Parser::functionSetType(Functions[*$2])->Equals($7))) {
				yyerror("Function differs from predefined function type");
				return -1;
			}
			
			if (Parser::functionSetAlreadyContainsEquivilent(fn, Functions[*$2]) == true) {
				yyerror("Identical function already defined");
				return -1;
			}
		}
		
		Functions[*$2].push_back(fn);
		
		Variables.clear();
		
		//Delete name
		delete $2;
		
		//Delete statements vector
		delete $9;
		
		//Delete variables vector
		delete $4;

	} | FUNCTION WORD LPAREN RPAREN COLON Type LBRACKET Statements RBRACKET {
		
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}
	
		SP<Function> fn = SP<Function>(new ScriptedFunction($6, ValueUtil::generateValue($6), *$8, values, std::vector<SP<Variable>>()));

		if ( Functions[*$2].size() > 0) {

			if (Parser::functionSetType(Functions[*$2]) != $6) {
				yyerror("Function differs from predefined function type");
				return -1;
			}

			if (Parser::functionSetAlreadyContainsEquivilent(fn, Functions[*$2]) == true) {
				yyerror("Identical function already defined");
				return -1;
			}

		}
		
		Functions[*$2].push_back(fn);
	
		Variables.clear();

		delete $2;
		delete $8;
	}
;

Arguments: Statement {
		$$ = new std::vector<SmartPointer<Statement>>();
		$$->push_back($1);
	} | Arguments COMMA Statement {
		$$ = $1;
		$$->push_back($3);
	}
;

Statements: {
		$$ = new std::vector<SmartPointer<Statement>>();
	} | Statements Statement {
		$$ = $1;
		$$->push_back($2);
	} | Statements RETURN Statement {
		$$ = $1;
		$$->push_back(new ReturnStatement(yylineno, yytext, $3));
	}
;

FunctionCall: WORD LPAREN Arguments RPAREN {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < $3->size(); ++i) {
			args.push_back($3->at(i));
		}
	
		delete $3;
		
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *$1, args, 0));
		Reference r;
		r.fRef = reference;
		References.push_back(r);
		
		
		$$ = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointer
		delete $1;
		
	} | WORD LPAREN RPAREN {
		std::vector<SmartPointer<Statement>> args;
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *$1, args, 0));
		
		Reference r;
		r.fRef = reference;
		References.push_back(r);
		
		
		$$ = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointer
		delete $1;
	} | WORD LINK WORD LPAREN Arguments RPAREN {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < $5->size(); ++i) {
			args.push_back($5->at(i));
		}
	
		delete $5;
	
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*$1, *$3, args, 0));
	
		Reference r;
		r.fRef = reference;
		References.push_back(r);
		
		$$ = new FunctionStatement(yylineno, yytext, reference);
	
		//Free the name pointers
		delete $1;
		delete $3;
		
	} | WORD LINK WORD LPAREN RPAREN {
		std::vector<SmartPointer<Statement>> args;
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*$1, *$3, args, 0));
		
		Reference r;
		r.fRef = reference;
		References.push_back(r);
		
		$$ = new FunctionStatement(yylineno, yytext, reference);
		
		//Free the name pointers
		delete $1;
		delete $3;

	}
;

Statement: TRUE {
		$$ = new BoolStatement(yylineno, yytext, true);
	} | FALSE {
		$$ = new BoolStatement(yylineno, yytext, false);
	} | INT {
		$$ = new IntStatement(yylineno, yytext, $1);
	} | STRING {
		
		$$ = new StringStatement(yylineno, yytext, *$1);
		
		//Free string pointer
		delete $1;

	} | LSQBRACKET INT RSQBRACKET Type {
		$$ = new ArrayStatement(yylineno, yytext, getTypeManager().getType(Array, $4), $2);
	} | Statement LSQBRACKET Statement RSQBRACKET ASSIGN Statement{
		$$ = new AssignArrayStatement(yylineno, yytext, $1, $6, $3); 
	} | Statement LSQBRACKET Statement RSQBRACKET {
		$$ = new GetArrayStatement(yylineno, yytext, $1, $3); 
	} | Variable {
		$$ = new GetVariableStatement(yylineno, yytext, *$1);
		delete $1;
	} | Variable ASSIGN Statement {
		$$ = new AssignVariableStatement(yylineno, yytext, *$1, $3);
		delete $1;
	} | AutoVariable {
		$$ = $1;
	} | WORD {

		auto it = Variables.find(*$1);

		if (it == Variables.end()) {
			yyerror("Variable not defined");
			return -1;
		} else {
			$$ = new GetVariableStatement(yylineno, yytext, it->second);
		}

		//Free name pointer
		delete $1;
		
	} | FunctionCall {
		$$ = $1;
	} | IF Statement LBRACKET Statements RBRACKET {
		$$ = new IfStatement(yylineno, yytext, $2, *$4, std::vector<SP<Statement>>());
		delete $4;
	} | IF Statement LBRACKET Statements RBRACKET ELSE LBRACKET Statements RBRACKET {
		$$ = new IfStatement(yylineno, yytext, $2, *$4, *$8);
		delete $4;
		delete $8;
	} | Statement PLUS Statement {
		$$ = new OperateStatement(yylineno, yytext, Add, $1, $3);
	} | Statement MINUS Statement {
		$$ = new OperateStatement(yylineno, yytext, Subtract, $1, $3);
	} | Statement TIMES Statement {
		$$ = new OperateStatement(yylineno, yytext, Multiply, $1, $3);
	} | Statement DIVIDE Statement {
		$$ = new OperateStatement(yylineno, yytext, Divide, $1, $3);
	} | FOR Statement END Statement END Statement LBRACKET Statements RBRACKET {
		$$ = new ForStatement(yylineno, yytext, $2, $4, $6, *$8);
		delete $8;
	} | WHILE Statement LBRACKET Statements RBRACKET {
		$$ = new WhileStatement(yylineno, yytext, $2, *$4);
		delete $4;
	} | Statement EQUALS Statement {
		$$ = new TestStatement(yylineno, yytext, TestEquals, $1, $3);
	} | Statement NOT EQUALS Statement {
		$$ = new TestStatement(yylineno, yytext, TestNotEquals, $1, $4);
	} | Statement GREATER Statement {
		$$ = new TestStatement(yylineno, yytext, TestGreater, $1, $3);
	} | Statement LESSER Statement {
		$$ = new TestStatement(yylineno, yytext, TestLess, $1, $3);
	} | LPAREN Statement RPAREN {
		$$ = $2;
	} | WORD ASSIGN Statement {
		
		auto it = Variables.find(*$1);

		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new AssignVariableStatement(yylineno, yytext, it->second, $3);
		}
		
		//Free up string pointer.
		delete $1;
		
	} | WORD TWOPLUS {
	
		auto it = Variables.find(*$1);
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new IncrementStatement(yylineno, yytext, it->second, Increment, false);
		}
		
		//Free name pointer
		delete $1;
		
	} | TWOPLUS WORD {
		auto it = Variables.find(*$2);
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new IncrementStatement(yylineno, yytext, it->second, Increment, true);
		}
		
		//Free name pointer
		delete $2;
		
	} | WORD TWOMINUS {
		auto it = Variables.find(*$1);
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new IncrementStatement(yylineno, yytext, it->second, Decrement, false);
		}
		
		//Free name pointer
		delete $1;
		
	} | TWOMINUS WORD {
		auto it = Variables.find(*$2);
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new IncrementStatement(yylineno, yytext, it->second, Decrement, true);
		}
		
		//Free name pointer
		delete $2;
	}
;

%%

void yyerror(std::string s)
{

  printf("ERROR: %s at symbol %s on line %i\n", s.c_str(), yytext, yylineno);
  ParsingError = true;
}

void yyerror(const char* s)
{
  yyerror(std::string(s));
}
