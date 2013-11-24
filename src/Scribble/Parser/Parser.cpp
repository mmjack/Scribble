#include "Parser.hpp"
#include "ParserException.hpp"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <Scribble/Function/ScriptedFunction.hpp>
#include <Scribble/Function/FunctionReference.hpp>
#include <Scribble/Value/Util.hpp>

#include <SHA3/sha3.h>
#include <limits.h> /* PATH_MAX */
#include <stdio.h>
#include <stdlib.h>

extern std::map<std::string, NamespaceType> Namespace;
extern NamespaceType Functions;

extern std::string currentNamespaceName;

extern map<std::string, std::string> ImportList;

extern std::vector<ParserReference> StatementReferences;
extern std::vector<SP<Variable>> VariableReferences;
extern std::vector<TypeReference> TypeReferences;

extern bool ParsingError;
extern int lastuid;

extern void scribble_parse();
extern void scribble__scan_string(char const*);
extern void scribble_lex_destroy();
extern void parser_free_all();

/**
 * This function should return the uniform relative path to a file ( For example test/dog and ./test/dog should both evaluate to test/dog )
 */

std::string Parser::getUniformPath(std::string const& currentPath) {
	//TODO: This needs improving. Currently provides absolute path if the file exists otherwise returns the currentPath handed
	char pBuf[PATH_MAX];

	if (realpath((currentPath + ScribbleFileSuffix).c_str(), pBuf) == 0) {
		return currentPath;
	}

	return std::string(pBuf);
}

SP<Function> Parser::findFunctionInSet(SP<FunctionReference> toFind,
		FunctionSet const& set) {

	//If the target set is empty return null
	if (set.size() == 0) {
		return 0;
	}

	//Grab a reference to the functions arguments.
	std::vector<SafeStatement> const& args = toFind->getArgs();

	//If the function takes zero arguments then there can only be one option.
	if (args.size() == 0) {

		SP<Function> fn = set[0];

		if (fn->numArgs() == 0) {
			return fn;
		} else {
			return 0;
		}

	}

	//Otherwise search through each function and do a thorough search.
	for (unsigned int i = 0; i < set.size(); ++i) {

		SP<Function> fn = set[i];

		if (fn->numArgs() == args.size()) {

			for (unsigned int i = 0; i < args.size(); ++i) {

				SafeStatement arg = args[i];

				if (fn->argType(i) != arg->type()) {
					break;
				}

				return fn;
			}

		}

	}

	return 0;
}

void Parser::printNamespace(NamespaceType const& ns) {

	for (auto iter = ns.begin(); iter != ns.end(); iter++) {
		printf("%s\n", iter->first.c_str());
	}

}

void Parser::printAllSpaces(std::map<std::string, NamespaceType> const& ns) {

	for (auto iter = ns.begin(); iter != ns.end(); iter++) {
		printf("--%s--\n", iter->first.c_str());
		printNamespace(iter->second);
		printf("--END--\n");
	}

}

std::string Parser::bufferText(std::string const& filePath) {

	FILE* fin = fopen(filePath.c_str(), "r");

	//If the file cannot be opened return an error
	if (fin == 0) {
		throw ParserException(filePath, "file could not be opened");
	}

	// Run to the end of the file
	fseek(fin, 0, SEEK_END);

	// Get the length of the file
	size_t f_size = ftell(fin);

	// Rewind to the beginning
	fseek(fin, 0, SEEK_SET);

	// Allocate space for the test
	char* buffer = new char[f_size + 1];

	// Read it in and null point the end
	fread(buffer, 1, f_size, fin);
	buffer[f_size] = '\0';

	//Close the file
	fclose(fin);

	//Create the inputSource from the buffer
	std::string inputSource = std::string(buffer);

	//Free the buffers
	delete[] buffer;

	//Check if the file size is zero.
	//if it is throw an empty file issue.
	if (f_size == 0) {
		throw ParserException(filePath, "Empty file");
	}

	return inputSource;
}

bool Parser::listContains(std::string target,
		std::vector<std::string> const& list) {

	//Check each member of the list to see if it contains the target string.
	for (unsigned int i = 0; i < list.size(); i++) {

		if (list[i].compare(target) == 0) {
			return true;
		}

	}

	return false;
}

bool Parser::functionSetAlreadyContainsEquivilent(SP<Function> function,
FunctionSet const& functionSet) {

	bool duplicate = false;

	//For each function in a set check to see if it has the same argument types as a given function and if it does return true.
		for (unsigned int i = 0; i < functionSet.size(); ++i) {

			auto compared = functionSet[i];

			if (compared.get() == function.get()) {
				return true;
			} else {

				if (function->numArgs() != compared->numArgs()) {
					return false;
				}

				duplicate = true;

				if (!function->getType()->Equals(compared->getType())) {
					duplicate = false;
				}

				for (unsigned int j = 0; j < function->numArgs(); ++j) {

					if (function->argType(j) != compared->argType(j)) {
						duplicate = false;
						break;
					}

				}

				if (duplicate) {
					return true;
				}

			}

		}

		return false;
	}

unsigned int Parser::functionSetNumArguments(FunctionSet const& set) {
	SP<Function> fn = set[0];
	return fn->numArgs();
}

Type* Parser::functionSetType(FunctionSet const& functionSet) {
	SP<Function> fn = functionSet[0];
	return fn->getType();
}

void Parser::resolve(TypeReference reference, NamespaceType ns) {

	if (reference->type != nullptr) {
		return;
	}

	if (reference->typeNamespace.size() != 0) {
		ns = Namespace[reference->typeNamespace];
	}

	if (ns[reference->name].type() != TypeEntry) {
		std::string error = reference->name;
		throw StatementException(nullptr, error + " is not a type");
	}

	TypeReference ref = ns[reference->name].getType();
	resolve(ref, ns);

	reference->type = ref->type;
}

std::string Parser::includeText(std::string source, std::string const& filename,
		std::string const& path) {

	currentNamespaceName = getUniformPath(path + filename);

	//Check to see whether it is already loaded
	if (Namespace.find(currentNamespaceName) != Namespace.end()) {
		return currentNamespaceName;
	}

	//Pass the data to the parser.
	scribble__scan_string(source.c_str());
	scribble_parse();
	scribble_lex_destroy();

	//Check to see if any errors occured
	if (ParsingError) {
		throw ParserException(filename, "Parser error occurred");
	}

	Namespace[currentNamespaceName] = Functions;
	Functions = NamespaceType();

	std::map < std::string, std::string > imports = ImportList;
	ImportList.clear();

	std::vector<ParserReference> references = StatementReferences;
	std::vector<TypeReference> typeReferences = TypeReferences;
	std::vector < SP< Variable >> variableReferences = VariableReferences;

	StatementReferences.clear();
	TypeReferences.clear();
	VariableReferences.clear();

	//Look at the list of requested imports and attempt to resolve them.
	for (auto iter = imports.begin(); iter != imports.end(); iter++) {

		//Calculate the new path if it is any different ( For example sorts/quick is recalculated to quick with path += sorts/ )
		auto pathEnd = iter->second.find_last_of("/");

		//Set the import path to be empty and the importFile to be ier->second
		std::string toImportPath = "";
		std::string importFile = iter->second;

		//If the imported file is in another directory then update its path ( So ./examples/ will become ./examples/sorts/)
		if (pathEnd != std::string::npos) {
			toImportPath = importFile.substr(0, pathEnd + 1);
			importFile = importFile.substr(pathEnd + 1, importFile.size());
		}

		//Include can modify the include path based on where it finds the target.
		std::string includePath = path + toImportPath;

		//printf("Including file %s toImportPath %s existing path %s full path %s\n", importFile.c_str(), toImportPath.c_str(), path.c_str(), includePath.c_str());

		std::string resolvedImportPath = include(importFile, includePath);

		//Change imports[iter->first] to the location include found the file at ( includePath is the 
		imports[iter->first] = resolvedImportPath;

		//After each include change currentNamespaceName as it may have been changed by the include
		currentNamespaceName = getUniformPath(path + filename);

		Functions = NamespaceType();
	}

	Functions = Namespace[currentNamespaceName];

	for (unsigned int i = 0; i < typeReferences.size(); ++i) {

		if (imports.find(typeReferences[i]->typeNamespace) != imports.end()) {
			typeReferences[i]->typeNamespace = getUniformPath(
					imports.find(typeReferences[i]->typeNamespace)->second);
		}

		resolve(typeReferences[i], Functions);
		//printf("Resolved %s\n", typeReferences[i]->name.c_str());
	}

	for (unsigned int i = 0; i < variableReferences.size(); ++i) {

		variableReferences[i]->setValue(
				ValueUtil::generateValue(variableReferences[i]->getType()));

		//printf("TODO: Variable decl\n");

		if (variableReferences[i]->getType()->getType() == Void) {
			throw ParserException(filename,
					"cannot declare a variable as a void");
		}

	}

	//Loop through all of the references and resolve them.
	for (unsigned int i = 0; i < references.size(); ++i) {

		switch (references[i].type()) {

		case FunctionEvaluation: {

			SP<FunctionReference> ref = references[i].functionReference;

			NamespaceType selectedNamespace = Functions;

			if (ref->getNamespace().size() != 0) {

				//Check the namespace has been loaded. If not then do not resolve the reference.
				if (imports.find(ref->getNamespace()) != imports.end()) {
					selectedNamespace = Namespace[imports.find(ref->getNamespace())->second];
				} else {

					ref->setResolveIssue(
							std::string("Namespace ") + ref->getNamespace()
							+ " has not been imported.");

				}

			}

			//Search for function in namespace.
			auto it = selectedNamespace.find(ref->getName());

			//If the function is in the namespace then resolve it. otherwise leave it blank and the statement will throw an exception when checked.
			if (it == selectedNamespace.end()) {

				ref->setResolveIssue(
						std::string("the function ") + ref->getDebugName()
						+ " is not defined in " + ref->getNamespace());

			} else {

				if (it->second.type() != FunctionSetEntry) {

					ref->setResolveIssue(
							ref->getDebugName() + " is not a function");

				} else {

					SP<Function> searchResult = Parser::findFunctionInSet(ref,
							it->second.getFunctionSet());

					if (searchResult.get() != nullptr) {

						ref->setFunction(searchResult);

					} else {

						char errorText[256];

						sprintf(errorText,
								"the function %s is defined but does not have any versions which take the specified argument types.",
								ref->getDebugName().c_str());

						ref->setResolveIssue(errorText);

					}

				}

			}

			break;
		}

		case StructureElementTypeEvaluation: {
			references[i].structureElementType->fix();
			break;
		}

		case AssignElementTypeEvaluation: {
			references[i].assignElementType->fix();
			break;
		}

		case VariableTypeEvaluation: {
			AutoVariablePair p = references[i].autoVariableType;
			p.first->setType(p.second->type());
			p.first->setValue(ValueUtil::generateValue(p.second->type()));
			break;
		}

	}

}

	try {

		//Run the check function on all functions which will throw StatementExceptions if there is an issue.
		if (Functions.size() > 0) {

			for (auto it = Functions.begin(); it != Functions.end(); it++) {

				if (it->second.type() == FunctionSetEntry) {
					std::vector<SafeFunction> set = it->second.getFunctionSet();

					for (unsigned int i = 0; i < set.size(); ++i) {
						((ScriptedFunction *) set[i].get())->check();
					}
				}

			}

		}

	} catch (StatementException& e) {
		throw ParserException(filename, e.what());
	}

	return currentNamespaceName;

}

std::string Parser::include(std::string const& filename,
		std::string const& path) {

	currentNamespaceName = getUniformPath(path + filename);

	//Check to see if its already loaded
	if (Namespace.find(currentNamespaceName) != Namespace.end()) {
		return currentNamespaceName;
	}

	std::string inputSource;

	//If the path is root and the file is not found then search the root.
	if (path.size() > 0) {

		try {
			//Create the inputSource from the buffer
			inputSource = bufferText(currentNamespaceName);
		} catch (ParserException& ex) {
			//printf("Parser exception looking for %s, looking in the top level\n", (currentNamespaceName).c_str());
			return include(filename, "");
		}

	} else {

		//If path is root and the file is not found then let the resolution fail ( So the import path  is CURRENT/file then if that fails it checks /file and if that fails it throws an error.
		inputSource = bufferText(filename);

	}

	//Clear and previous errors
	ParsingError = false;

	//Copy the input source to a buffer and then parse it ( As Bison/Flex only work with C strings)
	char* a = strdup(inputSource.c_str());
	std::string packagePath = includeText(a, filename, path);
	delete[] a;

	return currentNamespaceName;
}

std::map<std::string, NamespaceType> Parser::compile(std::string const& file,
		std::map<std::string, NamespaceType> builtinNamespace) {
	parser_free_all();

//For calculate the path to the file
	auto pathEnd = file.find_last_of("/");
	std::string path = "";
	std::string filename = file;

	if (pathEnd != std::string::npos) {
		path = filename.substr(0, pathEnd + 1);
		filename = file.substr(pathEnd + 1, file.size());
	}

	Namespace = builtinNamespace;
	include(filename, path);

	std::map<std::string, NamespaceType> result = Namespace;

	parser_free_all();

	return result;
}

std::map<std::string, NamespaceType> Parser::compileText(
		std::string const& text, std::string const& file,
		std::map<std::string, NamespaceType> builtinNamespace) {
	parser_free_all();

//For calculate the path to the file
	auto pathEnd = file.find_last_of("/");
	std::string path = "";
	std::string filename = file;

	if (pathEnd != std::string::npos) {
		path = filename.substr(0, pathEnd + 1);
		filename = file.substr(pathEnd + 1, file.size());
	}

	Namespace = builtinNamespace;
	includeText(text, filename, path);

	std::map<std::string, NamespaceType> result = Namespace;

	parser_free_all();

	return result;
}

