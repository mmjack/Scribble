/*
 * NotStatement.hpp
 *
 *  Created on: 5 Sep 2014
 *      Author: blake
 */

#ifndef NOTSTATEMENT_HPP_
#define NOTSTATEMENT_HPP_
#include "Statement.hpp"

namespace ScribbleCore {

class NotStatement: public Statement {
  private:
    SafeStatement exp_;

  public:
    NotStatement(int lineno, std::string symb, SafeStatement exp);
    virtual ~NotStatement();

    void checkTree(Type* functionType);
    TypeReference type();
    int generateCode(int resultRegister, std::stringstream& generated);
};

} /* namespace ScribbleCore */
#endif /* NOTSTATEMENT_HPP_ */
