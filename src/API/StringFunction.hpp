/*
 * StringFunction.hpp
 *
 *  Created on: 10 Mar 2013
 *      Author: blake
 */

#ifndef STRINGFUNCTION_HPP_
#define STRINGFUNCTION_HPP_
#include "Function.hpp"
#include <Scribble/Value/TypeManager.hpp>
#include <sstream>

class IntToStringFunction: public Function {
  public:
    IntToStringFunction(std::string ns);
    virtual ~IntToStringFunction();

    virtual API::APIValue execute(API::APIValue* values,
                                  VM::VirtualMachine* virt);
};

class Float32ToStringFunction: public Function {
  public:
    Float32ToStringFunction(std::string ns);
    virtual ~Float32ToStringFunction();

    virtual API::APIValue execute(API::APIValue* values,
                                  VM::VirtualMachine* virt);

};

class BoolToStringFunction: public Function {
  public:
    BoolToStringFunction(std::string ns);
    virtual ~BoolToStringFunction();

    virtual API::APIValue execute(API::APIValue* values,
                                  VM::VirtualMachine* virt);

};

class StringCompare: public Function {
  public:
    StringCompare(std::string ns);
    virtual ~StringCompare();

    virtual API::APIValue execute(API::APIValue* values,
                                  VM::VirtualMachine* virt);

};

#endif /* STRINGFUNCTION_HPP_ */
