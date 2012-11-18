#ifndef _VIRTUAL_MACHINE_DEF_H_
#define _VIRTUAL_MACHINE_DEF_H_

#include <Pointers/SmartPointer.hpp>
#include <Value/Value.hpp>
#include <Stack/Stack.hpp>

#include "InstructionList.hpp"
#include "OpCodes.hpp"
#include "Types.hpp"

/**
 *
 * Virtual machine definition. Executes instruction lists.
 *
 */
class VirtualMachine {
private:
	static int lastInstanceID__;

	int vmID_;

	SP<InstructionList> currentCode_;
	size_t position_;
	bool running_;

	Stack<Value> stack_;

public:
	VirtualMachine();
	~VirtualMachine();

	void setInstructions(SP<InstructionList> code);
	void execute();
};

#endif //_VIRTUAL_MACHINE_DEF_H_
