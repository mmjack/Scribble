/*
 * FunctionReferenceStatement.cpp
 *
 *  Created on: 2 Apr 2014
 *      Author: blake
 */

#include "FunctionReferenceStatement.hpp"

namespace ScribbleCore {

FunctionReferenceStatement::FunctionReferenceStatement(int lineNo,
        std::string sym, SmartPointer<FunctionReference> func) : Statement(lineNo, sym), func_(func) {
    _refType = makeTypeReference(getTypeManager().getType(TypeUnresolved));
}

FunctionReferenceStatement::~FunctionReferenceStatement() {
}

void FunctionReferenceStatement::checkTree(Type* functionType) {

    if (func_->getFunction().get() == nullptr) {

        std::string error = "";

        if (func_->getNamespace().length() > 0) {
            error = std::string("Function ") + func_->getNamespace() + "."
                    + func_->getName() + " could not be resolved. "
                    + func_->getResolveIssue();
        } else {
            error = std::string("Function ") + func_->getName()
                    + " could not be resolved. " + func_->getResolveIssue();
        }

        throw StatementException(this,
                                 std::string("Function ") + func_->getNamespace() + "."
                                 + func_->getName() + " could not be resolved. "
                                 + func_->getResolveIssue());
    }

    StatementAssert(this,
                    func_->getFunction()->getSignature().argumentsEqual(
                        func_->getTargetArguments()),
                    "The resolved function has incorrect arguments. This is an internal compiler issue.");
}

TypeReference FunctionReferenceStatement::type() {
    return _refType;
}

int FunctionReferenceStatement::generateCode(int resultRegister,
        std::stringstream& generated) {

    generated
            << "loadfn \"" + func_->getFunction()->getNamespace()
            + VM::vmNamespaceSeperator + func_->getFunction()->getName()
            + "\" $" << resultRegister << "\n";

    return 1;
}

void FunctionReferenceStatement::fix() {

    _refType->setType(
        getTypeManager().getType(
            func_->getFunction()->getSignature().getArguments(),
            func_->getFunction()->getSignature().getReturnType()));

}

} /* namespace ScribbleCore */
