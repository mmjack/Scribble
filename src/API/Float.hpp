/*
 * Float.hpp
 *
 *  Created on: 17 Nov 2013
 *      Author: blake
 */

#ifndef FLOAT_HPP_
#define FLOAT_HPP_
#include "Function.hpp"

namespace API {

class Float32FromInt: public Function {
  public:
    Float32FromInt(std::string ns);
    virtual ~Float32FromInt();

    API::APIValue execute(API::APIValue* values,
                          VM::VirtualMachine* virt);

};

} /* namespace API */
#endif /* FLOAT_HPP_ */
