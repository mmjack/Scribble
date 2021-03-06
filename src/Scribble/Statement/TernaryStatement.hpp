/*
 * TernaryStatement.hpp
 *
 *  Created on: 21 Mar 2014
 *      Author: blake
 */

#ifndef TERNARYSTATEMENT_HPP_
#define TERNARYSTATEMENT_HPP_
#include "Statement.hpp"

namespace ScribbleCore {

/**
 * Implementation of the ternary ( Expr ? TrueRes : FalseRes ) operator
 */

class TernaryStatement: public Statement {
  private:
    SafeStatement test_;
    SafeStatement lhs_, rhs_;
  public:
    TernaryStatement(int line, std::string sym, SafeStatement test, SafeStatement lhs, SafeStatement rhs);
    virtual ~TernaryStatement();

    TypeReference type();
    void checkTree(Type* functionType);
    int generateCode(int resultRegister, std::stringstream& generated);
};


} /* namespace ScribbleCore */

#endif /* TERNARYSTATEMENT_HPP_ */
