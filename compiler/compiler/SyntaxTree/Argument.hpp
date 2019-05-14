
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Argument : public SyntaxTree {
    
    public:
        Argument(SyntaxTree *type, SyntaxTree *name) {
        	children.push_back(type);
        	children.push_back(name);
        }
        
        virtual ~Argument() {}
        
        virtual std::string toCode() const {
			std::string code;
			
			code += children[1]->toCode() + " : ";
			
			std::string type = children[0]->toCode();
			if 		(type == "int") code += "Integer";
			else if (type == "char") code += "Character";
			else if (type == "bool") code += "Boolean";
			else if (type == "float") code += "Float";
			else if (type == "double") code += "Float";
			
        	return code;
        }
    };
}
