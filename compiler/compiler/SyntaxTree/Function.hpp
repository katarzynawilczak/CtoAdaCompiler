
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Function : public SyntaxTree {
    
    public:
    
		Function(SyntaxTree *type, SyntaxTree *name, SyntaxTree *argument_list, SyntaxTree *statements) {
        	children.push_back(type);
        	children.push_back(name);
        	children.push_back(argument_list);
        	children.push_back(statements);
        }
        
        virtual ~Function() {}
        
        virtual std::string toCode() const {
        	std::string code;
			
			if (!(children[0]->toCode() == "int" && children[1]->toCode() == "main")) {
				code += "function " + children[1]->toCode() + "(";
				code += children[2]->toCode();
				code += ") is\n";
			}
				
			code += "begin\n";
			
			if (children[3] != nullptr)
				code += children[3]->toCode();
			//code += children[2]->toCode();
        	/*for (SyntaxTree *node : children)
        		if (node != nullptr) {
        			code += node->toCode();
        		}*/
        	if (children[0]->toCode() == "int" && children[1]->toCode() == "main")
        		code += "end Output;";
        	else
        		code += "end " + children[1]->toCode() + ";\n\n";
        	return code;
        }
    };
}
