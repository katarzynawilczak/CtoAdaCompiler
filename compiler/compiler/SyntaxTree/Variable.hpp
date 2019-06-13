
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
			
			std::string type = children[0]->toCode();
			if 		(type == "int") code += "Integer";
			else if (type == "char") code += "Character";
			else if (type == "bool") code += "Boolean";
			else if (type == "float") code += "Float";
			else if (type == "double") code += "Float";
			
			if (children[2] == nullptr)
				code += ";\n";
			else
				code += " := " + children[2]->toCode() + ";\n";
			
			
        	return code;
        }
    };
}
