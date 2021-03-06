/*
 * RandomInt.hpp
 *
 *  Created on: 18 Mar 2013
 *      Author: blake
 */

#ifndef RANDOMINT_HPP_
#define RANDOMINT_HPP_
#include "Function.hpp"

/**
 * Random integer implementation. Returns a random integer between zero and n
 */
class RandomInt: public Function {
  private:
  public:
    RandomInt(std::string ns);
    virtual ~RandomInt();


    virtual APIValue execute(API::APIValue* values, VM::VirtualMachine* virt);

};

#endif /* RANDOMINT_HPP_ */
