/*
 * FunctionSignature.hpp
 *
 *  Created on: 26 Mar 2014
 *      Author: blake
 */

#ifndef FUNCTIONSIGNATURE_HPP_
#define FUNCTIONSIGNATURE_HPP_
#include <Scribble/Parser/TypeReference.hpp>

namespace ScribbleCore {

/**
 * Signatures are equal if the arguments and the return type are the same
 */

class FunctionSignature {
  private:

    std::vector<TypeReference> arguments_;
    TypeReference returnType_;

  public:
    FunctionSignature(std::vector<TypeReference> arguments, TypeReference returnType);
    virtual ~FunctionSignature();

    std::vector<TypeReference> getArguments();
    TypeReference getReturnType();
    bool equalTo(FunctionSignature other);
    bool argumentsEqual(std::vector<Type*> args);

};


} /* namespace ScribbleCore */
#endif /* FUNCTIONSIGNATURE_HPP_ */
