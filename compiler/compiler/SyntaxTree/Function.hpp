
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Function : public SyntaxTree {
    
    public:
    
    	Function(SyntaxTree *name, SyntaxTree *argument_list, SyntaxTree *variables, SyntaxTree *statements) {		// for procedure (without return)
        	children.push_back(name);
        	children.push_back(argument_list);
        	children.push_back(variables);
        	children.push_back(statements);
        }
    
		Function(SyntaxTree *name, SyntaxTree *argument_list, SyntaxTree *variables, SyntaxTree *statements, SyntaxTree *type) { // for function (with return)
        	children.push_back(name);
        	children.push_back(argument_list);
        	children.push_back(variables);
        	children.push_back(statements);
        	children.push_back(type);
        }
        
        virtual ~Function() {}
        
        virtual std::string toCode() const {
        	std::string code;
			
			
			if (children[4] == nullptr) {													// procedure (void)
				code += "procedure " + children[0]->toCode();
				if (children[1] != nullptr)
					code +=  "(" + children[1]->toCode() + ")";
				code += " is\n";
			}
			else if (!(children[4]->toCode() == "Integer" && children[0]->toCode() == "main")) {	// not main procedure (int main)
				code += "function " + children[0]->toCode();
				if (children[1] != nullptr)
					code += "(" + children[1]->toCode() + ")";
				code += " return " + children[4]->toCode() + " is\n";
			}
				
			if (children[2] != nullptr)
				code += children[2]->toCode();
			
			code += "begin\n";
			
			if (children[3] != nullptr)
				code += children[3]->toCode();

        	if (children[4] != nullptr && children[4]->toCode() == "Integer" && children[0]->toCode() == "main")
        		code += "\nend Output;";
       		else
       			code += "end " + children[0]->toCode() + ";\n\n";
        	return code;
        }
    };
}
