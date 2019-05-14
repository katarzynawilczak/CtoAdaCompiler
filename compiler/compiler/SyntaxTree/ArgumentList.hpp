
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class ArgumentList : public SyntaxTree {
    
    public:
        ArgumentList(SyntaxTree *tree, SyntaxTree *othertree) {
        	children.push_back(tree);
        	children.push_back(othertree);
        }
        
        virtual ~ArgumentList() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	if (children[0] != nullptr)
        		code += children[0]->toCode();
			
			if (children[1] != nullptr)
				code += ", " + children[1]->toCode();

        	return code;
        }
    };
}
