
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Cases : public SyntaxTree {
    
    public:
        Cases(SyntaxTree *case1) {
        	children.push_back(case1);
        }
        
        Cases(SyntaxTree *case1, SyntaxTree *cases) {
        	children.push_back(case1);
        	children.push_back(cases);
        }
        
        virtual ~Cases() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	for (SyntaxTree *node : children)
        		if (node != nullptr)
        			code += node->toCode();
        	return code;
        }
    };
}
