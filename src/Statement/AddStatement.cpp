#include "AddStatement.hpp"
#include <Value/Value.hpp>

AddStatement::AddStatement(Statement* lhs, Statement* rhs) {
	lhs_ = lhs;
	rhs_ = rhs;
}

AddStatement::~AddStatement() {
	delete lhs_;
	delete rhs_;
}

Value AddStatement::Execute() {
	Value lhsValue = lhs_->Execute();
	Value rhsValue = rhs_->Execute();
	
	return Value(lhsValue.FloatValue() + rhsValue.FloatValue());
}
