/*
 * CallFunctionReference.cpp
 *
 *  Created on: 5 Jun 2014
 *      Author: blake
 */

#include "CallFunctionReference.hpp"

namespace ScribbleCore {

CallFunctionReference::CallFunctionReference(int lineNo, std::string sym,
		SafeStatement fn, std::vector<SafeStatement> args) :
		Statement(lineNo, sym) {

}

CallFunctionReference::~CallFunctionReference() {
}

void CallFunctionReference::checkTree(Type* functionType) {

	fn_->checkTree(functionType);

	for (unsigned int i = 0; i < args_.size(); i++) {
		args_[i]->checkTree(functionType);
	}

}

TypeReference CallFunctionReference::type() {
}

int CallFunctionReference::generateCode(int resultRegister,
		std::stringstream& generated) {

}

} /* namespace ScribbleCore */
