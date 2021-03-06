/*
 * CallTypes.hpp
 *
 *  Created on: 2 Sep 2013
 *      Author: blake
 */

#ifndef CALLTYPES_HPP_
#define CALLTYPES_HPP_

namespace VM {

/**
 * Defines whether the call is a constant reference or a reference stored in a register.
 */
enum CallType {
    Constant = 0,
    Register
};

}

#endif /* CALLTYPES_HPP_ */
