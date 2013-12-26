/*
 * RegisterPackages.cpp
 *
 *  Created on: 26 Dec 2013
 *      Author: blake
 */

#include "RegisterPackages.hpp"
#include <Scribble/Value/StructureInfo.hpp>

void registerPackages(std::map<std::string, NamespaceType>& allNames,
		VM::VirtualMachine& vm) {

	std::vector < std::pair<std::string, SP<VM::VMStructureField>>>postResolveList;

	for (auto selectedNamespaceIter = allNames.begin();
			selectedNamespaceIter != allNames.end(); selectedNamespaceIter++) {

		vm.logMessage(VM::Log,
				std::string("Registering namespace ")
				+ selectedNamespaceIter->first + std::string("\n"));

		VM::VMNamespace newSpace;

		NamespaceType names = selectedNamespaceIter->second;

		for (auto iterator = names.begin(); iterator != names.end();
				iterator++) {

			if (iterator->second.type() == FunctionSetEntry) {

				FunctionSet functionSet = iterator->second.getFunctionSet();

				for (unsigned int i = 0; i < functionSet.size(); i++) {
					SP<Function> function = functionSet[i];

					std::stringstream code;
					function->debugCode(code);

					newSpace.insert(function->getName(), VM::NamespaceEntry(function->generateVMFunction()));

					vm.logMessage(VM::Log, std::string("Registered string ") + function->getName());

					vm.logMessage(VM::Log, std::string(" {\n") + code.str() + std::string("\n}\n"));
				}

			} else if (iterator->second.type() == TypeEntry) {

				if (iterator->second.getType()->type->getType() == StructureType) {
					vm.logMessage(VM::Log, std::string("Registering Type ") + selectedNamespaceIter->first + VM::vmNamespaceSeperator + iterator->first + " {\n");

					TypeReference type = iterator->second.getType();
					StructureInfo* info = (StructureInfo*) iterator->second.getType()->type;

					std::vector<SP<VM::VMStructureField>> fields;

					for (unsigned int i = 0; i < info->getNumIndexs(); i++) {

						Type* fieldType = info->getIndex(i).second->type;

						std::string fullTypeName = info->getIndex(i).second->type->getTypeName();

						vm.logMessage(VM::Log, info->getIndex(i).first + " : " + ((StructureInfo*) info->getIndex(i).second->type)->getTypeName() + "\n");

						SP<VM::VMStructureField> newField = SP<VM::VMStructureField>(new VM::VMStructureField(info->getIndex(i).first, nullptr));
						postResolveList.push_back(std::pair<std::string, SP<VM::VMStructureField>>(fullTypeName, newField));
						fields.push_back( newField );
					}

					newSpace.insert(info->getName(), VM::NamespaceEntry(SP<VM::VMEntryType>(new VM::VMEntryType(info->getName(), fields))));

					vm.logMessage(VM::Log, "}\n");
				}

			}

		}

		vm.registerEntry(selectedNamespaceIter->first,
				VM::NamespaceEntry(newSpace));

	}

	for (auto iter = postResolveList.begin(); iter != postResolveList.end(); iter++) {

		auto resolvedType = vm.findType(iter->first);

		if (resolvedType != nullptr) {
			iter->second->setType(vm.findType(iter->first));
		} else {
			printf("FATAL ERROR: Type could not be resolved ( %s not registered )", iter->first.c_str());
			exit(-1);
		}

	}

}

