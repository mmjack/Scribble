%error-verbose
%locations
%name-prefix "scribble_"

%{
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <vector>
#include <Scribble/Statement/ThreadStatement.hpp>
#include <Scribble/Statement/BoolStatement.hpp>
#include <Scribble/Statement/IntStatement.hpp>
#include <Scribble/Statement/OperateStatement.hpp>
#include <Scribble/Statement/StringStatement.hpp>
#include <Scribble/Statement/AssignVariable.hpp>
#include <Scribble/Statement/GetVariableStatement.hpp>
#include <Scribble/Statement/FunctionStatement.hpp>
#include <Scribble/Statement/AndStatement.hpp>
#include <Scribble/Statement/ForStatement.hpp>
#include <Scribble/Statement/TestStatement.hpp>
#include <Scribble/Statement/IfStatement.hpp>
#include <Scribble/Statement/OperateStatement.hpp>
#include <Scribble/Statement/ReturnStatement.hpp>
#include <Scribble/Statement/TestNilStatement.hpp>
#include <Scribble/Statement/WhileStatement.hpp>
#include <Scribble/Statement/IncrementStatement.hpp>
#include <Scribble/Statement/ArrayStatement.hpp>
#include <Scribble/Statement/ArraySliceStatement.hpp>
#include <Scribble/Statement/AssignArrayStatement.hpp>
#include <Scribble/Statement/GetArrayStatement.hpp>
#include <Scribble/Statement/ArrayLengthStatement.hpp>
#include <Scribble/Statement/NegativeStatement.hpp>
#include <Scribble/Statement/StructureStatement.hpp>
#include <Scribble/Statement/GetStructureElementStatement.hpp>
#include <Scribble/Statement/StructureAssignElement.hpp>
#include <Scribble/Parser/TypeReference.hpp>
#include <Pointers/SmartPointer.hpp>
#include <Scribble/Function/Function.hpp>
#include <Scribble/Function/ScriptedFunction.hpp>
#include <Scribble/Function/WriteFunction.hpp>
#include <Scribble/Value/TypeManager.hpp>
#include <Scribble/Value/Util.hpp>
#include <Scribble/Parser/Parser.hpp>
#include <Scribble/Value/StructureInfo.hpp>

#include <Scribble/Value/Variable.hpp>
#include <Scribble/Value/String.hpp>

int scribble_lex();
void scribble_error(const char* s);

bool ParsingError;
std::vector<std::string> ImportList;
std::map<std::string, SP<Variable>> Variables;

std::map<std::string, NamespaceType> Namespace;
NamespaceType Functions;

std::vector<TypeReference> TypeReferences;
std::vector<SP<Variable>> VariableReferences;
std::vector<ParserReference> StatementReferences;

void parser_free_all() {
	ImportList.clear();
	Variables.clear();
	Namespace.clear();
	Functions.clear();
	StatementReferences.clear();
	TypeReferences.clear();
	VariableReferences.clear();
	ParsingError = false;
}

extern int scribble_lineno;	// defined and maintained in lex.c
extern char *scribble_text;	// defined and maintained in lex.c

%}

%union {
	std::vector<SmartPointer<Statement>>* statements;
	std::vector<SmartPointer<Variable>>* variables;
	StructureInfo* structureinfo;
	Statement* statement;
	Function* function;
	SP<Variable>* variable;
	std::string* string;
	
	float real;
	int integer;
	TypeReference* type;
}

%token <string> WORD STRING
%token <real> REAL
%token <integer> INT
%token <token> PLUS MINUS TIMES DIVIDE POWER EQUALS ASSIGN IF ELSE GREATER LESSER FOR TYPE_ARRAY TYPE_VOID RETURN WHILE NOT IMPORT LINK
%token <token> LPAREN RPAREN LBRACKET RBRACKET COMMA TWOMINUS TWOPLUS TYPE_BOOL TRUE FALSE AUTO AND NIL TYPE
%token <token> FUNCTION VARIABLE CONST STRUCT LENGTH THREAD POINT
%token <token> TYPE_INT TYPE_STRING COLON LSQBRACKET RSQBRACKET THEN
%token <token> END

%left PLUS MINUS
%left TIMES DIVIDE
%left NEG
%left TRUE FALSE EQUALS
%right POWER WORD

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
%type <statement> FunctionCall;
%type <structureinfo> BaseStructureInfo;
%type <statements> IfStatements
%type <statement> Expression;

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
	} | Program TYPE WORD ASSIGN Type {
		Functions[*$3] = NamespaceEntry(*$5);
		delete $3;
		delete $5;
	} | Program TYPE WORD ASSIGN STRUCT LBRACKET BaseStructureInfo RBRACKET {
		Functions[*$3] = NamespaceEntry(TypeReference(new TypeReferenceCore(*$3, $7)));
		delete $3;
	}
;

BaseStructureInfo: {
		$$ = new StructureInfo("INVALID");
	} | BaseStructureInfo WORD COLON Type {
		$1->addInfo(*$2, *$4);
		delete $2;
		delete $4;
	}
;

Type: TYPE_INT {
		$$ = new TypeReference( new TypeReferenceCore ( "", getTypeManager().getType(Int) ) );
	} | TYPE_STRING {
		$$ = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(String) ) );
	} | TYPE_BOOL {
		$$ = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Boolean) ) );
	} | TYPE_VOID {
		$$ = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Void) ) );
	} | TYPE_ARRAY LPAREN Type RPAREN {
		$$ = new TypeReference ( new TypeReferenceCore ( "", getTypeManager().getType(Array, *$3) ) );
		delete $3;
	} | WORD LINK WORD {
	
		$$ = new TypeReference ( new TypeReferenceCore( *$1, *$3, nullptr) );
		TypeReferences.push_back(*$$);
		delete $1;
		delete $3;
		
	} | WORD {
		
		/**
		if (Functions[*$1].type() != TypeEntry) {
			char err[256];
			sprintf(err, "%s is not a type\n", $1->c_str());
			yyerror(err);
			return -1;
		}*/
		
		$$ = new TypeReference( new TypeReferenceCore ( *$1, nullptr ) );
		TypeReferences.push_back(*$$);
		
		delete $1;
	}
;

Variable:  VARIABLE WORD COLON Type {

		printf("TODO: Check no variable is declared as void\n");

		auto it = Variables.find(*$2);
			
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, *$4, nullptr));
			VariableReferences.push_back(*nVar);
			Variables[*$2] = *nVar;
			$$ = nVar;
		}
		
		delete $2;
		delete $4;
	}
;

AutoVariable: VARIABLE WORD ASSIGN Expression {

		auto it = Variables.find(*$2);
				
		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
		
			SafeStatement sp = $4;
		
			SP<Variable> nVar = SP<Variable>(new Variable(0, nullptr, nullptr));
			Variables[*$2] = nVar;
			
			ParserReference r(AutoVariablePair(nVar, sp));
			StatementReferences.push_back(r);			

			$$ = new AssignVariableStatement(scribble_lineno, scribble_text, nVar, sp);
		}
		
		delete $2;
	}
;

ArgumentDefinition: WORD COLON Type {

		auto it = Variables.find(*$1);

		if (it != Variables.end()) {
			yyerror("Variable already defined.");
			return -1;
		} else {
			SP<Variable>* nVar = new SP<Variable>(new Variable(0, *$3, nullptr));
			VariableReferences.push_back(*nVar);
			Variables[*$1] = *nVar;
			$$ = nVar;
		}
		
		delete $1;
		delete $3;
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


		SP<Variable> returnTemplate = new Variable(0, *$7, nullptr);
		VariableReferences.push_back(returnTemplate);
		SP<Function> fn = new ScriptedFunction(*$7, returnTemplate, *$9, values, *$4);
		
		if (Functions[*$2].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*$2] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*$2].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*$2].getFunctionSet();
			
			if ( functions.size() > 0) {
				
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*$2].addFunctionToSet(fn);
		
		}
		
		Variables.clear();
		
		//Delete name
		delete $2;
		
		//Delete statements vector
		delete $9;
		
		//Delete variables vector
		delete $4;
		
		delete $7;

	} | FUNCTION WORD LPAREN RPAREN COLON Type LBRACKET Statements RBRACKET {
		
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}
	
	
		SP<Variable> returnTemplate = new Variable(0, *$6, nullptr);
		VariableReferences.push_back(returnTemplate);
		SP<Function> fn = SP<Function>(new ScriptedFunction(*$6, returnTemplate, *$8, values, std::vector<SP<Variable>>()));
		
		if (Functions[*$2].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*$2] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*$2].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*$2].getFunctionSet();
			
			if ( functions.size() > 0) {
			
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*$2].addFunctionToSet(fn);
		
		}
	
		Variables.clear();

		delete $2;
		delete $8;
		delete $6;
	} | FUNCTION WORD LPAREN ArgumentDefinitions RPAREN LBRACKET Statements RBRACKET {
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}

		TypeReference voidReference = TypeReference( new TypeReferenceCore ( "", getVoidType() ) );

		SP<Variable> returnTemplate = new Variable(0, voidReference, ValueUtil::generateValue(getVoidType()));
		SP<Function> fn = new ScriptedFunction(voidReference, returnTemplate, *$7, values, *$4);
		
		if (Functions[*$2].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*$2] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*$2].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*$2].getFunctionSet();
			
			if ( functions.size() > 0) {
				
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*$2].addFunctionToSet(fn);
		
		}
		
		Variables.clear();
		
		//Delete name
		delete $2;
		
		//Delete statements vector
		delete $7;
		
		//Delete variables vector
		delete $4;

	} | FUNCTION WORD LPAREN RPAREN LBRACKET Statements RBRACKET {
		
		std::vector<SP<Variable>> values;

		int pos = 0;
		for (auto it = Variables.begin(); it != Variables.end(); it++) {
			it->second->setPosition(pos);
			values.push_back(it->second);
			pos++;
		}
	
	
		TypeReference voidReference = TypeReference( new TypeReferenceCore ( "", getVoidType() ) );
	
		SP<Variable> returnTemplate = new Variable(0, voidReference, ValueUtil::generateValue(getVoidType()));
		SP<Function> fn = SP<Function>(new ScriptedFunction(voidReference, returnTemplate, *$6, values, std::vector<SP<Variable>>()));
		
		if (Functions[*$2].type() == EmptyEntry) {
		
			std::vector<SafeFunction> newSet;
			newSet.push_back(fn);

			Functions[*$2] = NamespaceEntry(newSet);
		
		} else {
		
			if ( Functions[*$2].type() != FunctionSetEntry) {
				yyerror("Not a function type");
				return -1;
			}
			
			std::vector<SafeFunction> functions = Functions[*$2].getFunctionSet();
			
			if ( functions.size() > 0) {
			
				printf("TODO: Function return type.\n");
				
				if (Parser::functionSetAlreadyContainsEquivilent(fn, functions) == true) {
					yyerror("Identical function already defined");
					return -1;
				}
			}
			
			Functions[*$2].addFunctionToSet(fn);
		
		}
	
		Variables.clear();

		delete $2;
		delete $6;
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
		$$->push_back(new ReturnStatement(scribble_lineno, scribble_text, $3));
	} | Statements RETURN {
		$$ = $1;
		$$->push_back(new ReturnStatement(scribble_lineno, scribble_text, nullptr));
	}
;

FunctionCall: WORD LPAREN Arguments RPAREN {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < $3->size(); ++i) {
			args.push_back($3->at(i));
		}
	
		delete $3;
		
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *$1, args, 0));
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		
		$$ = new FunctionStatement(scribble_lineno, scribble_text, reference, Variables.size());
		
		//Free the name pointer
		delete $1;
		
	} | WORD LPAREN RPAREN {
		std::vector<SmartPointer<Statement>> args;
		
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference("", *$1, args, 0));
		
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		
		$$ = new FunctionStatement(scribble_lineno, scribble_text, reference, Variables.size());
		
		//Free the name pointer
		delete $1;
	} | WORD LINK WORD LPAREN Arguments RPAREN {
	
		std::vector<SmartPointer<Statement>> args;
	
		for (unsigned int i = 0; i < $5->size(); ++i) {
			args.push_back($5->at(i));
		}
	
		delete $5;
	
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*$1, *$3, args, 0));
	
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		$$ = new FunctionStatement(scribble_lineno, scribble_text, reference, Variables.size());
	
		//Free the name pointers
		delete $1;
		delete $3;
		
	} | WORD LINK WORD LPAREN RPAREN {
		std::vector<SmartPointer<Statement>> args;
		SmartPointer<FunctionReference> reference = SmartPointer<FunctionReference>(new FunctionReference(*$1, *$3, args, 0));
		
		ParserReference r(reference);
		StatementReferences.push_back(r);
		
		$$ = new FunctionStatement(scribble_lineno, scribble_text, reference, Variables.size());
		
		//Free the name pointers
		delete $1;
		delete $3;

	}
;

IfStatements: Statement {
		std::vector<SafeStatement>* stmts = new std::vector<SafeStatement>();
		stmts->push_back($1);
		$$ = stmts;
	} | LBRACKET Statements RBRACKET {
		$$ = $2;
	}
;

Statement: Expression END {
		$$ = $1;
	} | IF Expression THEN IfStatements  {
		$$ = new IfStatement(scribble_lineno, scribble_text, $2, *$4, std::vector<SP<Statement>>());
		delete $4;
	} | IF Expression THEN IfStatements ELSE IfStatements {
		$$ = new IfStatement(scribble_lineno, scribble_text, $2, *$4, *$6);
		delete $4;
		delete $6;
	} | FOR Expression END Expression END Expression LBRACKET Statements RBRACKET {
		$$ = new ForStatement(scribble_lineno, scribble_text, $2, $4, $6, *$8);
		delete $8;
	} | WHILE Expression LBRACKET Statements RBRACKET {
		$$ = new WhileStatement(scribble_lineno, scribble_text, $2, *$4);
		delete $4;
	};

Expression: TRUE {
		$$ = new BoolStatement(scribble_lineno, scribble_text, true);
	} | FALSE {
		$$ = new BoolStatement(scribble_lineno, scribble_text, false);
	} | INT {
		$$ = new IntStatement(scribble_lineno, scribble_text, $1);
	} | STRING {
		
		$$ = new StringStatement(scribble_lineno, scribble_text, *$1);
		
		//Free string pointer
		delete $1;

	} | Type LBRACKET Arguments RBRACKET {
	
		$$ = new StructureStatement(scribble_lineno, scribble_text, *$1, *$3);
		delete $3;
		delete $1;
		
	} | Variable {
		$$ = new GetVariableStatement(scribble_lineno, scribble_text, *$1);
		delete $1;
	} | Variable ASSIGN Expression {
		$$ = new AssignVariableStatement(scribble_lineno, scribble_text, *$1, $3);
		delete $1;
	} | AutoVariable {
		$$ = $1;
	} | LENGTH LPAREN Expression RPAREN {
		$$ = new ArrayLengthStatement(scribble_lineno, scribble_text, $3);
	} | LSQBRACKET Expression RSQBRACKET Type {
		$$ = new ArrayStatement(scribble_lineno, scribble_text, getTypeManager().getType(Array, *$4), $2);
		delete $4;
	} | Expression LSQBRACKET Expression RSQBRACKET ASSIGN Expression {
		$$ = new AssignArrayStatement(scribble_lineno, scribble_text, $1, $6, $3); 
	} | Expression LSQBRACKET Expression RSQBRACKET {
		$$ = new GetArrayStatement(scribble_lineno, scribble_text, $1, $3); 
	} | Expression LSQBRACKET Expression COLON Expression RSQBRACKET {
		$$ = new ArraySliceStatement(scribble_lineno, scribble_text, $1, $3, $5);
	} | WORD {

		auto it = Variables.find(*$1);

		if (it == Variables.end()) {
			scribble_error("Variable not defined");
			return -1;
		} else {
			$$ = new GetVariableStatement(scribble_lineno, scribble_text, it->second);
		}

		//Free name pointer
		delete $1;
		
	} | FunctionCall {
		$$ = $1;
	} | Expression PLUS Expression {
		$$ = new OperateStatement(scribble_lineno, scribble_text, Add, $1, $3);
	} | Expression MINUS Expression {
		$$ = new OperateStatement(scribble_lineno, scribble_text, Subtract, $1, $3);
	} | Expression TIMES Expression {
		$$ = new OperateStatement(scribble_lineno, scribble_text, Multiply, $1, $3);
	} | Expression DIVIDE Expression {
		$$ = new OperateStatement(scribble_lineno, scribble_text, Divide, $1, $3);
	} | NIL EQUALS Expression {
		$$ = new TestNilStatement(scribble_lineno, scribble_text, $3);
	} | Expression EQUALS NIL {
		$$ = new TestNilStatement(scribble_lineno, scribble_text, $1);
	} | Expression EQUALS Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestEquals, $1, $3);
	} | Expression NOT EQUALS Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestNotEquals, $1, $4);
	} | Expression GREATER Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestGreater, $1, $3);
	} | Expression LESSER Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestLess, $1, $3);
	} | Expression LESSER EQUALS Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestLessOrEqual, $1, $4);
	} | Expression GREATER EQUALS Expression {
		$$ = new TestStatement(scribble_lineno, scribble_text, TestGreaterOrEqual, $1, $4);
	} | LPAREN Expression RPAREN {
		$$ = $2;
	} | WORD ASSIGN Expression {
		
		auto it = Variables.find(*$1);

		if (it == Variables.end()) {
			scribble_error("Variable not defined");
		} else {
			$$ = new AssignVariableStatement(scribble_lineno, scribble_text, it->second, $3);
		}
		
		//Free up string pointer.
		delete $1;
		
	} | WORD TWOPLUS {
	
		auto it = Variables.find(*$1);
		
		if (it == Variables.end()) {
			scribble_error("Variable not defined");
		} else {
			$$ = new IncrementStatement(scribble_lineno, scribble_text, it->second, Increment, false);
		}
		
		//Free name pointer
		delete $1;
		
	} | TWOPLUS WORD {
		
		auto it = Variables.find(*$2);
		
		if (it == Variables.end()) {
			scribble_error("Variable not defined");
		} else {
			$$ = new IncrementStatement(scribble_lineno, scribble_text, it->second, Increment, true);
		}
		
		//Free name pointer
		delete $2;
		
	} | WORD TWOMINUS {
		
		auto it = Variables.find(*$1);
		
		if (it == Variables.end()) {
			scribble_error("Variable not defined");
		} else {
			$$ = new IncrementStatement(scribble_lineno, scribble_text, it->second, Decrement, false);
		}
		
		//Free name pointer
		delete $1;
		
	} | TWOMINUS WORD {
		
		auto it = Variables.find(*$2);
		
		if (it == Variables.end()) {
			yyerror("Variable not defined");
		} else {
			$$ = new IncrementStatement(scribble_lineno, scribble_text, it->second, Decrement, true);
		}
		
		//Free name pointer
		delete $2;
	} | Expression AND Expression {
		$$ = new AndStatement(scribble_lineno, scribble_text, $1, $3);
	} | Expression POINT WORD {
		
		$$ = new GetStructureElementStatement(scribble_lineno, scribble_text, $1, *$3);
		
		ParserReference r((GetStructureElementStatement*) $$);
		StatementReferences.push_back(r);
		
		delete $3;
	} | Expression POINT WORD ASSIGN Expression {
	
		$$ = new StructureAssignElement(scribble_lineno, scribble_text, $1, $5, *$3);
		
		ParserReference r((StructureAssignElement*) $$);
		StatementReferences.push_back(r);
	
		delete $3;
	}
;

%%

void scribble_error(std::string s)
{

  printf("ERROR: %s at symbol %s on line %i\n", s.c_str(), scribble_text, scribble_lineno);
  ParsingError = true;
}

void scribble_error(const char* s)
{
  scribble_error(std::string(s));
}
