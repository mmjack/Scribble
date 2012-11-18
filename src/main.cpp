#include <VirtualMachine/VirtualMachine.hpp>

int main(int argc, char** argv) {

	unsigned char* instructions = new unsigned char[2 + sizeof(int)];
	instructions[0] = LoadConst;
	instructions[1] = Integer;
	*((int*)instructions+2) = 94;

	SP<InstructionList> aList = new InstructionList(instructions, 5);
	SP<InstructionList> bList = new InstructionList(instructions, 5);
	SP<InstructionList> cList = new InstructionList(instructions, 5);

	VirtualMachine a;
	a.setInstructions(aList);

	VirtualMachine b;
	b.setInstructions(bList);

	VirtualMachine c;
	c.setInstructions(cList);

	a.execute();
	b.execute();
	c.execute();

}
