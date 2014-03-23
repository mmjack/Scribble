/*
 * TernaryStatement.cpp
 *
 *  Created on: 21 Mar 2014
 *      Author: blake
 */

#include "TernaryStatement.hpp"
#include <VM/Constants.hpp>

namespace ScribbleCore {

TernaryStatement::TernaryStatement(int line, std::string sym,
		SafeStatement test, SafeStatement lhs, SafeStatement rhs) :
		Statement(line, sym), test_(test), lhs_(lhs), rhs_(rhs) {

}

TernaryStatement::~TernaryStatement() {
}

Type* TernaryStatement::type() {
	return lhs_->type();
}

void TernaryStatement::checkTree(Type* functionType) {

	test_->checkTree(functionType);
	lhs_->checkTree(functionType);
	rhs_->checkTree(functionType);

	if (test_->type()->getType() != Boolean) {
		throw StatementException(this,
				"Ternary test should be a boolean expression");
	}

	if (!lhs_->type()->Equals(rhs_->type())) {
		throw StatementException(this,
				"Ternary options have to be the same type");
	}

}

int TernaryStatement::generateCode(int resultRegister,
		std::stringstream& generated) {

	std::stringstream lhsCode;
	int lhsNum = lhs_->generateCode(resultRegister, lhsCode);

	std::stringstream rhsCode;
	int rhsNum = rhs_->generateCode(resultRegister, rhsCode);

	int instrs = test_->generateCode(VM::vmTempRegisterOne, generated);

	generated << "eqz $" << VM::vmTempRegisterOne << "\n";
	instrs++;

	generated << "jmpr " << lhsNum + 2 << "\n";
	instrs++;

	generated << lhsCode.str();
	instrs += lhsNum;

	generated << "jmpr " << rhsNum + 1 << "\n";
	instrs++;

	generated << rhsCode.str();
	instrs += rhsNum;

	return instrs;
}

} /* namespace ScribbleCore */
