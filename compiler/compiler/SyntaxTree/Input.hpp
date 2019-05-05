
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Input : public SyntaxTree {
    
    public:
    
        Input(SyntaxTree *libraries, SyntaxTree *mainFunction, SyntaxTree *functions) {
            children.push_back(libraries);
        	children.push_back(mainFunction);
        	children.push_back(functions);
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
