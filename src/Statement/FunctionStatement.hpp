#ifndef _FUNCTION_STATEMENT_H_
#define _FUNCTION_STATEMENT_H_
#include "Statement.hpp"
#include <Pointers/SmartPointer.hpp>
#include <Function/Function.hpp>
#include <Function/FunctionReference.hpp>
#include <stdio.h>
#include <vector>

class FunctionStatement: public Statement {
private:
	SmartPointer<FunctionReference> func_;
	std::vector<SmartPointer<Statement>> args_;

public:
	FunctionStatement(int lineNo, std::string sym, SmartPointer<FunctionReference> function,
			std::vector<SmartPointer<Statement>> arguments) : Statement(lineNo, sym) {
		func_ = function;
		args_ = arguments;
	}

	virtual Value* execute(std::vector<Value*> const& variables) {

		std::vector<Value*> pArgs;

		for (unsigned int i = 0; i < args_.size(); i++) {
			pArgs.push_back(args_[i]->execute(variables));
		}

		Value* res = func_->getFunction()->execute(pArgs);

		for (unsigned int i = 0; i < pArgs.size(); i++) {
			delete pArgs[i];
		}

		return res;
	}

	ValueType type() {
		return func_->getFunction()->getType();
	}

	void checkTree(ValueType functionType);
};

#endif //_FUNCTION_STATEMENT_H
