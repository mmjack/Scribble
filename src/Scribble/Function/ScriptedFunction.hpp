/*
 * ScriptedFunction.hpp
 *
 *  Created on: 9 Mar 2013
 *      Author: blake
 */

#ifndef SCRIPTEDFUNCTION_HPP_
#define SCRIPTEDFUNCTION_HPP_
#include "Function.hpp"
#include <Scribble/Statement/Statement.hpp>
#include <Pointers/SmartPointer.hpp>
#include <Scribble/Value/Variable.hpp>
#include <Scribble/Parser/TypeReference.hpp>
#include <SASM/Parser.hpp>

class ScriptedFunction: public Function {
private:
	std::string name_;
	int version_;

	TypeReference fType_;SP<Variable> templateReturn_;
	std::vector<SmartPointer<Statement>> statements_;
	std::vector<SmartPointer<Variable>> variableTemplates_;
	std::vector<SmartPointer<Variable>> arguments_;

public:

	ScriptedFunction(std::string name, int version, TypeReference functionType,
			SP<Variable> templateReturn,
			std::vector<SmartPointer<Statement>> statements,
			std::vector<SmartPointer<Variable>> variableTemplates,
			std::vector<SmartPointer<Variable>> variables);

	virtual ~ScriptedFunction();

	Value* execute(std::vector<Value*> arguments);

	Type* getType();

	const unsigned int numArgs();
	Type* argType(unsigned int arg);
	void check();

	int debugCode(std::stringstream& gen);

	std::string getName() {
		std::stringstream name;
		name << name_ << "#" << version_;
		return name.str();
	}

	virtual VM::VMFunc generateVMFunction() {

		std::stringstream code;

		debugCode(code);
		VM::InstructionSet instructions = SimpleASM::Parser::parse(
				code.str().c_str());

		return VM::VMFunc(getName(), instructions);
	}
};

#endif /* SCRIPTEDFUNCTION_HPP_ */
