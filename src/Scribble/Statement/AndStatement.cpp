/*
 * AndStatement.cpp
 *
 *  Created on: Nov 3, 2013
 *      Author: blake
 */

#include "AndStatement.hpp"
#include <Scribble/Value/TypeManager.hpp>
#include <VM/Constants.hpp>
#include <sstream>

namespace ScribbleCore {

AndStatement::AndStatement(int lineNo, std::string sym,
                           SafeStatement leftHandSide, SafeStatement rightHandSide) :
    Statement(lineNo, sym), lhs_(leftHandSide), rhs_(rightHandSide) {}

AndStatement::~AndStatement() {}

void AndStatement::checkTree(Type* functionType) {
    lhs_->checkTree(functionType);
    rhs_->checkTree(functionType);

    StatementAssert(this,
                    lhs_->type()->type()->Equals(getTypeManager().getType(Boolean))
                    && rhs_->type()->type()->Equals(
                        getTypeManager().getType(Boolean)),
                    std::string("and on types ") + lhs_->type()->type()->getTypeName()
                    + " and " + rhs_->type()->type()->getTypeName()
                    + " is not possible. and comparison can only be performed on two booleans");
}

TypeReference AndStatement::type() {
    return makeTypeReference(getTypeManager().getType(Boolean));
}

int AndStatement::generateCode(int resultRegister,
                               std::stringstream& generated) {
                                                          
    /**
     * The AND statement code generator will place a 0 in the result register if the left or right expression are falsey (0)
     * Otherwise it will place a 1 in the result register
     */

    //If the result of the and statement is to be ignored then place the result in temp register 1 ( In this case the and statement should still be executed in case the functions involved had desired side
    //effects, though anything that causes this would be very badly written code )
    if (resultRegister == -1) {
        resultRegister = VM::vmTempRegisterOne;
    }

    int instrs = 0;

    generated << "--And test\n";

    std::stringstream firstStatement;
    int firstInstrs = lhs_->generateCode(resultRegister, firstStatement);

    std::stringstream secondStatement;
    int secondInstrs = rhs_->generateCode(resultRegister, secondStatement);

    //Add the first statement to the code
    generated << firstStatement.str();
    instrs += firstInstrs;

    //If the result of the first statement equals zero then jump out as the second statement doesn't need to be tested.
    generated << "eqz $" << resultRegister << "\n";
    instrs++;

    generated << "jmpr " << 1 + secondInstrs << "\n";
    instrs++;

    //Add the second statement test to the code.
    generated << secondStatement.str();
    instrs += secondInstrs;

    generated << "--End of and test\n";

    return instrs;
}

}
