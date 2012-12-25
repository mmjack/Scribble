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

std::string AddStatement::GenerateBytecode() {
	std::string resultingString;
	resultingString = lhs_->GenerateBytecode();
	resultingString += rhs_->GenerateBytecode();
	resultingString += "add\n";
	return resultingString;
}
