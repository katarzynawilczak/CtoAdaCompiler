
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Libraries : public SyntaxTree {
    
    public:
        Libraries(SyntaxTree *tree, SyntaxTree *othertree) {
        	children.push_back(tree);
        	children.push_back(othertree);
        }
        
        virtual ~Libraries() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	for (SyntaxTree *node : children)
        		if (node != nullptr)
        			code += node->toCode();
        	return code;
        }
    };
}
