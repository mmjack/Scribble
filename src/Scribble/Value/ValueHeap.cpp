/*
 * ValueHeap.cpp
 *
 *  Created on: 10 Apr 2013
 *      Author: blake
 */

#include "ValueHeap.hpp"
#include <Scribble/Value/Util.hpp>
#include <Scribble/Value/Bool.hpp>
#include <Scribble/Value/Int.hpp>
#include <Scribble/Value/TypeManager.hpp>

ValueHeap::ValueHeap() {

	valueStore_ = new Stack<Value*> [ValueTypeMax];

}

ValueHeap::~ValueHeap() {
	freeAll();
	delete[] valueStore_;
}

Value* ValueHeap::make(Type* type) {

	lock_.lock();

	Value* generated = nullptr;

	//If it is a complex type we don't store it so ignore it
	if (type->getType() != StructureType && type->getSubtype() == nullptr) {

		if (valueStore_[type->getType()].size() > 0) {
			generated = valueStore_[type->getType()].pop();
		}

	}

	if (generated == nullptr) {
		generated = ValueUtil::generateValue(type);
	}

	lock_.unlock();

	return generated;
}

Value* ValueHeap::make(bool value) {
	Value* val = make(getBooleanType());
	((BoolValue*) val)->setValue(value);
	return val;
}

Value* ValueHeap::make(int value) {
	Value* val = make(getIntType());
	((IntValue*) val)->setValue(value);
	return val;
}

void ValueHeap::free(Value* v) {

	//If it is a complex type just delete it.
	if (v->type()->getType() == StructureType || v->type()->getSubtype() != nullptr) {
		delete v;
		return;
	}

	//Otherwise lock the heap and then add it on

	lock_.lock();

	if (valueStore_[v->type()->getType()].size() < ValueStackMax) {
		valueStore_[v->type()->getType()].push(v);
	} else {
		delete v;
	}

	lock_.unlock();

}

void ValueHeap::freeAll() {

	for (unsigned int i = 0; i < ValueTypeMax; ++i) {

		while (valueStore_[i].size() > 0) {
			delete valueStore_[i].pop();
		}

	}

}