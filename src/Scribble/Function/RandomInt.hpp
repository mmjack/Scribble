/*
 * RandomInt.hpp
 *
 *  Created on: 18 Mar 2013
 *      Author: blake
 */

#ifndef RANDOMINT_HPP_
#define RANDOMINT_HPP_
#include "Function.hpp"

/**
 * Random integer implementation. Returns a random integer between zero and n
 */
class RandomInt: public Function {
public:
	RandomInt();
	virtual ~RandomInt();

	Value* execute(std::vector<Value*> arguments);
	Type* getType();
	const unsigned int numArgs();
	Type* argType(unsigned int arg);
	void check();

	virtual std::string getName() {
		return "NativeRandomInt";
	}

	virtual VM::VMFunc generateVMFunction() {
		return VM::VMFunc(getName(), VM::InstructionSet());
	}
};

#endif /* RANDOMINT_HPP_ */
