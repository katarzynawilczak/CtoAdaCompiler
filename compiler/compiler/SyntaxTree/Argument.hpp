
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
			
			code += children[0]->toCode();
			
        	return code;
        }
    };
}
