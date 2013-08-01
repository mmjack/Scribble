#include "IntStatement.hpp"
#include <sstream>
#include <Scribble/Statement/Heap.hpp>

IntStatement::IntStatement(int lineNo, std::string sym, int intValue) :
		Statement(lineNo, sym) {
	intValue_ = intValue;
}

Value* IntStatement::execute(std::vector<Value*> const& variables) {
	IntValue* gen = (IntValue*) valueHeap.make(getIntType());
	gen->setValue(intValue_);
	return gen;
}

void IntStatement::checkTree(Type* functionType) {

}

int IntStatement::generateCode(int resultRegister,
		std::stringstream& generated) {

	if (resultRegister != -1) {

		generated << "load " << intValue_ << " $" << resultRegister << " #"
				<< resultRegister << "\n";

	}

	return 1;
}