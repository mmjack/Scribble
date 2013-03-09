#ifndef _VARIABLE_H_
#define _VARIABLE_H_
#include <Pointers/SmartPointer.hpp>
#include "Value.hpp"
#include <map>

class Variable {
public:
	SmartPointer<Value> value;
	ValueType type;

	Variable(ValueType t) {
		type = t;
		value = 0;
	}
};

#endif //_VARIABLE_H_
