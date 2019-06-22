
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class ArgsCallFunc : public SyntaxTree {
    
    public:
        ArgsCallFunc(SyntaxTree *tree, SyntaxTree *othertree) {
        	children.push_back(tree);
        	children.push_back(othertree);
        }
        
        virtual ~ArgsCallFunc() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	code += children[0]->toCode() + ", ";
			
			code += children[1]->toCode();

        	return code;
        }
    };
}
