/*
 * WhileStatement.hpp
 *
 *  Created on: 18 Mar 2013
 *      Author: blake
 */

#ifndef WHILESTATEMENT_HPP_
#define WHILESTATEMENT_HPP_
#include "Statement.hpp"
#include <vector>

namespace ScribbleCore {

class WhileStatement: public Statement {
  private:
    SafeStatement condition_;
    std::vector<SafeStatement> statements_;

  public:
    WhileStatement(int lineNumber, std::string symbol, SafeStatement condition,
                   std::vector<SafeStatement> statements);
    virtual ~WhileStatement();

    void checkTree(Type* functionType);
    TypeReference type();

    int generateCode(int resultRegister, std::stringstream& generated);
};

}

#endif /* WHILESTATEMENT_HPP_ */
