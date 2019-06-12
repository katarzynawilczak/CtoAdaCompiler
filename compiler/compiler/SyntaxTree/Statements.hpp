
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Statements : public SyntaxTree {
    
    public:
        Statements(SyntaxTree *tree, SyntaxTree *othertree) {
        	children.push_back(tree);
        	children.push_back(othertree);
        }
        
        virtual ~Statements() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	for (SyntaxTree *node : children)
        		if (node != nullptr)
        			code += node->toCode();
        	//if (children[0] == nullptr) code += "nullptr\n";
        	//else code += children[0]->toCode();
        	//code+=children[1]->toCode();
        	return code;
        }
    };
}
