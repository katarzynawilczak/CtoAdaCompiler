
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Variable : public SyntaxTree {
    
    public:
    
		Variable(SyntaxTree *type, SyntaxTree *name, SyntaxTree *expression) {
        	children.push_back(type);
        	children.push_back(name);
        	children.push_back(expression);
        }
        
        Variable(SyntaxTree *type, SyntaxTree *name) {
        	children.push_back(type);
        	children.push_back(name);
        }
        
        virtual ~Variable() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
			code += children[1]->toCode() + " : ";
			
			code += children[0]->toCode();
			
			if (children[2] == nullptr)
				code += ";\n";
			else
				code += " := " + children[2]->toCode() + ";\n";
			
			
        	return code;
        }
    };
}
