
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Return : public SyntaxTree {

    public:
        
        Return() {
        	children.push_back(nullptr);
        }
        
        Return(SyntaxTree *returnStatement) {
        	children.push_back(returnStatement);
        }
        
        virtual ~Return() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	if (children[0] != nullptr)
        		code += "return " + children[0]->toCode() + ";\n";
        	else
        		code += "return;\n";

        	return code;
        }
        
    };
}
