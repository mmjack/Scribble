/*
 * GetStructureElementStatement.hpp
 *
 *  Created on: 26 May 2013
 *      Author: blake
 */

#ifndef GETSTRUCTUREELEMENTSTATEMENT_HPP_
#define GETSTRUCTUREELEMENTSTATEMENT_HPP_
#include "Statement.hpp"
#include <string>

namespace ScribbleCore {

class GetStructureElementStatement: public Statement {
  private:

    SafeStatement statement_;

    std::string elementName_;
    int elementIndex_;
    TypeReference elementType_;

  public:
    GetStructureElementStatement(int yylineno, std::string sym,
                                 SafeStatement stmt, std::string elementName);
    virtual ~GetStructureElementStatement();

    virtual void checkTree(Type* functionType);
    virtual TypeReference type();
    virtual void fix();

    virtual int generateCode(int resultRegister, std::stringstream& generated);
};

}

#endif /* GETSTRUCTUREELEMENTSTATEMENT_HPP_ */
