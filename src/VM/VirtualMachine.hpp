/*
 * VirtualMachine.hpp
 *
 *  Created on: 28 May 2013
 *      Author: blake
 */

#ifndef VIRTUALMACHINE_HPP_
#define VIRTUALMACHINE_HPP_
#include "InstructionSet.hpp"
#include "VMFunc.hpp"
#include <vector>
#include <map>
#include <stack>
#include "Stack.hpp"
#include "Heap.hpp"
#include "VMNamespace.hpp"
#include "VMEntryType.hpp"

namespace VM {

enum VMLogLevel {
    Log, Debug, Warn, Fatal
};

class VMState {
  public:
    SmartPointer<VMFunc> func_;
    long pc_;

    VMState() :
        pc_(0) {
    }

    VMState(SmartPointer<VMFunc> func, long pc) :
        func_(func), pc_(pc) {
    }
};

class VirtualMachine {
  private:

    /**
     * Pointer to the actual stack memory
     */
    uint8_t* stack_;

    /**
     * Current max stack height
     */
    long currentStackHeight_;

    /**
     * A list of the location of each reference on the stack.
     */
    std::vector<long> stackReferences_;

    /**
     * The virtual machine state stack is pushed every time a function call is made with the new instruction set and popped on return. The storedPc is used to store the value of the PC register on a function call so on return it can be restored.
     */
    std::stack<VMState> currentVmState_;

    /**
     * Pointer to registers and whether they are a reference.
     */
    long currentInstruction;
    long stackBasePointer;
    long stackCurrentPointer;

    bool shouldReturn;

    int64_t* registers_;
    bool* registerReference_;

    /**
     * The VM heap.
     */
    Heap heap_;

    /**
     * The parent namespace node.
     */
    VMNamespace namespace_;

    SmartPointer<VMFunc> currentFunction;

    unsigned int gcStat_;

    bool returnToPreviousFunction(SmartPointer<VMFunc>& fn, InstructionSet& set);

    void opMove(InstructionSet& instructionSet);
    void opJump(InstructionSet& instructionSet);
    void opAdd(InstructionSet& instructionSet);
    void opLoadConstant(InstructionSet& instructionSet);
    void opSub(InstructionSet& instructionSet);
    void opMul(InstructionSet& instructionSet);
    void opDiv(InstructionSet& instructionSet);
    void opInc(InstructionSet& instructionSet);
    void opDec(InstructionSet& instructionSet);
    void opAddFloat32(InstructionSet& instructionSet);
    void opSubFloat32(InstructionSet& instructionSet);
    void opMulFloat32(InstructionSet& instructionSet);
    void opDivFloat32(InstructionSet& instructionSet);
    void opCmpFloat32(InstructionSet& instructionSet);
    void opEqual(InstructionSet& instructionSet);
    void opNotEqual(InstructionSet& instructionSet);
    void opEqualZero(InstructionSet& instructionSet);
    void opLessThan(InstructionSet& instructionSet);
    void opGreaterThan(InstructionSet& instructionSet);
    void opGreaterThanOrEqual(InstructionSet& instructionSet);
    void opPushRegisters(InstructionSet& instructionSet);
    void opPopRegisters(InstructionSet& instructionSet);
    void opPopNil(InstructionSet& instructionSet);
    void opLessThanOrEqual(InstructionSet& instructionSet);
    void opStructGetField(InstructionSet& instructionSet);
    void opStructSetField(InstructionSet& instructionSet);
    void opArraySet(InstructionSet& instructionSet);
    void opArrayGet(InstructionSet& instructionSet);
    void opNewStruct(InstructionSet& instructionSet);
    void opNewArray(InstructionSet& instructionSet);
    void opArrayLength(InstructionSet& instructionSet);
    void opCallFn(InstructionSet& instructionSet);
    void opReturn(InstructionSet& instructionSet);
    void opNot(InstructionSet& instructionSet);

  public:
    VirtualMachine();
    virtual ~VirtualMachine();

    virtual long stackLong(int64_t pos);
    virtual void stackSetLong(int64_t pos, int64_t v);
    virtual void popStackLong(int64_t& val, bool& ref);
    virtual void pushStackLong(int64_t v);
    virtual void expandStack();
    virtual void markStackReference();
    virtual void pushRegister(uint8_t reg);

    void getRegister(uint8_t reg, int64_t& val, bool& isReg);
    void setRegister(uint8_t reg, int64_t val, bool ref);

    virtual Heap& getHeap() {
        return heap_;
    }

    virtual SmartPointer<VMEntryType> findType(std::string const& name);

    virtual void registerEntry(std::string const& name, NamespaceEntry entry) {
        namespace_.set(name, entry);
    }

    virtual void execute(std::string function);
    virtual void garbageCollection();

    virtual void printState();
    virtual void hitGc() {
        gcStat_++;
    }

    virtual void logMessage(VMLogLevel, std::string message);
};

} /* namespace VM */

#endif /* VIRTUALMACHINE_HPP_ */
