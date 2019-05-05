
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Function : public SyntaxTree {
    
    public:
    
			Function(SyntaxTree *name, SyntaxTree *statements) {
        	children.push_back(name);
        	children.push_back(statements);
        }
        
        virtual ~Function() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	//code += "#include <stdio.h>\n";
        	//code += "int main () {\n";
        	for (SyntaxTree *node : children)
        		if (node != nullptr) {
        			std::cout << "Function" << std::endl;
        			code += node->toCode();
        		}
        	
        	//code += "}";
        	return "";
        }
    };
}
