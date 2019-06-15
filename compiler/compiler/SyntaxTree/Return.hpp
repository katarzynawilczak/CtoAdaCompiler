
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Return : public SyntaxTree {

    public:
    
    	Return() {}
        
        Return(SyntaxTree *returnStatement) {
        	children.push_back(returnStatement);
        }
        
        virtual ~Return() {}
        
        virtual std::string toCode() const {
        	std::string code;

        	return code;
        }
        
    };
}
