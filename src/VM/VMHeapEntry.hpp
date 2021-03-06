/*
 * VMEntry.hpp
 *
 *  Created on: Jul 22, 2013
 *      Author: blake
 */

#ifndef VMENTRY_HPP_
#define VMENTRY_HPP_
#include "VMEntryType.hpp"

namespace VM {

struct VMHeapEntry {
    SmartPointer<VMEntryType> type;
    unsigned int sizeBytes;
    SmartPointer<uint8_t> pointer;
    bool flagged;
};

}


#endif /* VMENTRY_HPP_ */
