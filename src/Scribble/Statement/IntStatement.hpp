#ifndef _INT_STATEMENT_DEF_H_
#define _INT_STATEMENT_DEF_H_
#include <sstream>
#include "Statement.hpp"
#include <Scribble/Value/TypeManager.hpp>

namespace ScribbleCore {

class IntStatement: public Statement {
  private:
    int intValue_;

  public:
    IntStatement(int lineNo, std::string sym, int intValue);

    TypeReference type() {
        return makeTypeReference(getTypeManager().getType(Int));
    }

    void checkTree(Type* functionType);

    int generateCode(int resultRegister, std::stringstream& generated);
};

}

#endif //_INT_STATEMENT_DEF_H_
