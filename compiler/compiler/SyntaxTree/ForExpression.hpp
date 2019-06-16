
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class ForExpression : public SyntaxTree {
    
    private:
    	std::string what;
    	
    public:
    	
    	ForExpression(SyntaxTree *conditions) {
        	children.push_back(conditions);
        }
        
        ForExpression(std::string str, SyntaxTree *tree, SyntaxTree *otherTree) {
        	what = str;
        	children.push_back(tree);
        	children.push_back(otherTree);
        }
        
		ForExpression(SyntaxTree *statement, SyntaxTree *condition, SyntaxTree *step) {
        	children.push_back(statement);
        	children.push_back(condition);
        	children.push_back(step);
        }
        
        virtual ~ForExpression() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	

        	return code;
        }
    };
}
