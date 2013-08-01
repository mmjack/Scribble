/*
 * StringFunction.cpp
 *
 *  Created on: 10 Mar 2013
 *      Author: blake
 */

#include "StringFunction.hpp"
#include <Scribble/Statement/StatementException.hpp>
#include <Scribble/Value/Int.hpp>
#include <Scribble/Value/Bool.hpp>
#include <Scribble/Value/String.hpp>
#include <Scribble/Value/TypeManager.hpp>
#include <sstream>

IntToStringFunction::IntToStringFunction() {
	// TODO Auto-generated constructor stub

}

IntToStringFunction::~IntToStringFunction() {
	// TODO Auto-generated destructor stub
}

Value* IntToStringFunction::execute(std::vector<Value*> arguments) {
	Value* arg = arguments[0];
	std::stringstream st;

	st << ((IntValue*) arg)->value();

	return new StringValue(st.str());
}

Type* IntToStringFunction::getType() {
	return getTypeManager().getType(String);
}

unsigned int const IntToStringFunction::numArgs() {
	return 1;
}

Type* IntToStringFunction::argType(unsigned int arg) {

	if (arg == 0) {
		return getTypeManager().getType(Int);
	}

	return getTypeManager().getType(TypeUnresolved);
}

BoolToStringFunction::BoolToStringFunction() {
	// TODO Auto-generated constructor stub

}

BoolToStringFunction::~BoolToStringFunction() {
	// TODO Auto-generated destructor stub
}

Value* BoolToStringFunction::execute(std::vector<Value*> arguments) {
	Value* arg = arguments[0];
	std::stringstream st;

	if (((BoolValue*) arg)->value()) {
		st << "true";
	} else {
		st << "false";
	}

	return new StringValue(st.str());
}

Type* BoolToStringFunction::getType() {
	return getTypeManager().getType(String);
}

unsigned int const BoolToStringFunction::numArgs() {
	return 1;
}

Type* BoolToStringFunction::argType(unsigned int arg) {

	if (arg == 0) {
		return getTypeManager().getType(Boolean);
	}

	return getTypeManager().getType(TypeUnresolved);
}