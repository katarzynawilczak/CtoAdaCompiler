
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Input : public SyntaxTree {
    
    public:
    
        Input(SyntaxTree *name, SyntaxTree *statements) {
        	children.push_back(name);
        	children.push_back(statements);
        }
        
        virtual ~Input() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	for (SyntaxTree *node : children)
        		if (node != nullptr)
        			code += node->toCode();
        	return code;
        }
    };
}
