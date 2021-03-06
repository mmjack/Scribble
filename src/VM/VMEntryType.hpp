/*
 * VMEntryType.hpp
 *
 *  Created on: Jul 21, 2013
 *      Author: blake
 */

#ifndef VMENTRYTYPE_HPP_
#define VMENTRYTYPE_HPP_
#include <Pointers/SmartPointer.hpp>
#include <string>
#include <vector>

namespace VM {

/**
 * The base type of the VMEntry changes how the garbage collector sees it and what instructions can use it.
 */

enum VMEntryBaseType {
    VMPrimitive, VMArray, VMStructure
};

/**
 * Pre declare VMEntryType so VMStructureField can see it
 */

class VMEntryType;

class VMStructureField {
  private:
    std::string name_;
    SmartPointer<VMEntryType> type_;

  public:

    VMStructureField(std::string name, SmartPointer<VMEntryType> type) : name_(name), type_(type) {
    }

    std::string getName() {
        return name_;
    }

    SmartPointer<VMEntryType> getType() {
        return type_;
    }

    void setType(SmartPointer<VMEntryType> type) {
        type_ = type;
    }

};

class VMEntryType {
  private:

    std::string name_;
    unsigned int size_;

    bool reference_;

    VMEntryBaseType baseType_;

    SmartPointer<VMEntryType> arraySubtype_;

    std::vector<SmartPointer<VMStructureField>> structureFields_;
    int* structureFieldOffsets_;

    unsigned int structureSizeBytes_;
    bool structureSizeDirty_;
    bool structureFieldsDirty_;

    int cacheFieldOffsets();

  public:

    VMEntryType(std::string name, unsigned int size, bool reference);
    VMEntryType(std::string name, SmartPointer<VMEntryType> subtype);
    VMEntryType(std::string name, std::vector<SmartPointer<VMStructureField>> fields);
    virtual ~VMEntryType();

    /**
     * Return the name of this VMEntryType ( Such as array(int) or int ).
     */

    std::string typeName();

    /**
     * Returns the size of the element. Will be either 1, 2, 4, or 8
     */

    unsigned int getElementSize();

    /**
     * If base type is VMPrimitive and the VMPrimitive is a heap reference then this will return true.
     */

    bool isReference();

    /**
     * Return the base type of this VMEntryType ( VMStructure, VMPrimtive, VMArray ).
     */

    VMEntryBaseType getBaseType() {
        return baseType_;
    }

    /**
     * If this object is of the base type VMArray then this function will return a VMEntryType with the subtype of the array.
     */

    SmartPointer<VMEntryType> arraySubtype();

    /**
     * Return a text description of the VMEntryType
     */

    std::string debugType();

    /**
     * Return the list of fields in a structure.
     */

    std::vector<SmartPointer<VMStructureField>> const& getStructureFields() {
        return structureFields_;
    }

    /**
     * Return the offset in bytes of the start of a structure element
     * or -1 if the id value is greater than the number of fields.
     */

    int getStructureFieldOffset(unsigned int id);

    /**
     * Get the size in bytes of the structure.
     */

    unsigned int getStructureSize();

};

}
/* namespace VM */

#endif /* VMENTRYTYPE_HPP_ */
