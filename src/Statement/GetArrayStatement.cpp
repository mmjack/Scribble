/*
 * GetArrayStatement.cpp
 *
 *  Created on: 24 Apr 2013
 *      Author: blake
 */

#include "GetArrayStatement.hpp"
#include "Heap.hpp"
#include <Value/Array.hpp>
#include <Value/Int.hpp>
#include <VM/VirtualMachine.hpp>

GetArrayStatement::GetArrayStatement(int line, std::string sym,
		SafeStatement array, SafeStatement index) :
		Statement(line, sym), array_(array), index_(index) {

}

GetArrayStatement::~GetArrayStatement() {
}

Value* GetArrayStatement::execute(std::vector<Value*> const& variables) {
	IntValue* index = (IntValue*) index_->execute(variables);
	ArrayValue* array = (ArrayValue*) array_->execute(variables);

	if (index->value() < 0 || index->value() >= array->getLength()) {
		throw StatementException(this, "Index out of bounds");
	}

	Value* v =
			array->getArrayData()->index(array->getStart() + index->value())->clone();

	valueHeap.free(index);
	valueHeap.free(array);

	return v;
}

Type* GetArrayStatement::type() {
	return array_->type()->getSubtype();
}

void GetArrayStatement::checkTree(Type* functionType) {
	array_->checkTree(functionType);
	index_->checkTree(functionType);

	if (array_->type()->getType() != Array) {
		throw StatementException(this, "This supplied value is not an array");
	}

	if (index_->type()->getType() != Int) {
		throw StatementException(this, "Expected integer index");
	}
}

int GetArrayStatement::generateCode(int resultRegister,
		std::stringstream& generated) {

	int instrs = array_->generateCode(VM::vmTempRegisterOne, generated);
	instrs += index_->generateCode(VM::vmTempRegisterTwo, generated);

	generated << "aget $" << VM::vmTempRegisterOne << " $"
			<< VM::vmTempRegisterTwo << " $" << resultRegister << "\n";

	return instrs + 1;
}
