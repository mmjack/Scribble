/*
 * NilStatement.hpp
 *
 *  Created on: 27 Feb 2014
 *      Author: blake
 */

#ifndef NILSTATEMENT_HPP_
#define NILSTATEMENT_HPP_

#include "Statement.hpp"

namespace ScribbleCore {

class NilStatement: public Statement {
  public:
    NilStatement(int lineNo, std::string symbol);
    virtual ~NilStatement();

    virtual void checkTree(Type* functionType);
    virtual TypeReference type();
    int generateCode(int resultRegister, std::stringstream& generated);
};

} /* namespace ScribbleCore */
#endif /* NILSTATEMENT_HPP_ */
