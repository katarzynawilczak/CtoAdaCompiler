
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Variables : public SyntaxTree {
    
    public:
        Variables(SyntaxTree *tree, SyntaxTree *othertree) {
        	children.push_back(tree);
        	children.push_back(othertree);
        }
        
        virtual ~Variables() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	for (SyntaxTree *node : children)
        		if (node != nullptr)
        			code += node->toCode();
        	return code;
        }
    };
}
