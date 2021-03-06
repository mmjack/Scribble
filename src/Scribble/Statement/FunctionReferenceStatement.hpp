/*
 * FunctionReferenceStatement.hpp
 *
 *  Created on: 2 Apr 2014
 *      Author: blake
 */

#ifndef FUNCTIONREFERENCESTATEMENT_HPP_
#define FUNCTIONREFERENCESTATEMENT_HPP_
#include "Statement.hpp"
#include <Scribble/Function/FunctionReference.hpp>

namespace ScribbleCore {

class FunctionReferenceStatement: public Statement {
  private:
    SmartPointer<FunctionReference> func_;
    TypeReference _refType;

  public:
    FunctionReferenceStatement(int lineNo, std::string sym, SmartPointer<FunctionReference> func);
    virtual ~FunctionReferenceStatement();

    TypeReference type();
    void checkTree(Type* functionType);
    int generateCode(int resultRegister, std::stringstream& generated);
    void fix();
};

} /* namespace ScribbleCore */
#endif /* FUNCTIONREFERENCESTATEMENT_HPP_ */
