
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Expression : public SyntaxTree {
    private:
    	std::string what;
    
    public:
        Expression(std::string str, SyntaxTree *tree) {
        	what = str;
        	children.push_back(tree);
        }
        
        Expression(std::string str, SyntaxTree *tree, SyntaxTree *otherTree) {
        	what = str;
        	children.push_back(tree);
        	children.push_back(otherTree);
        }
        
        virtual ~Expression() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	if (what == "exp") {
        		code += "(" + children[0]->toCode() + ")";
        	}
        	
        	else if (what == "+") {
        		code += children[0]->toCode() + " + " + children[1]->toCode();
        	}
        	
        	else if (what == "-") {
        		code += children[0]->toCode() + " - " + children[1]->toCode();
        	}

        	else if (what == "*") {
        		code += children[0]->toCode() + " * " + children[1]->toCode();
        	}
        	
        	else if (what == "/") {
        		code += children[0]->toCode() + " / " + children[1]->toCode();
        	}
        	return code;
        }
    };
}
