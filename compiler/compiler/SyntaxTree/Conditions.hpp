
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Conditions : public SyntaxTree {
    
    private:
    	std::string what;
    
    public:
        Conditions(std::string str, SyntaxTree *conditions) {
        	what = str;
        	children.push_back(conditions);
        }
        
        Conditions(std::string str, SyntaxTree *conditions, SyntaxTree *otherConditions) {
        	what = str;
        	children.push_back(conditions);
        	children.push_back(otherConditions);
        }
        
        virtual ~Conditions() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
        	if (what == "()")
        		code += "(" + children[0]->toCode() + ")";
        	else if (what == "and")
        		code += children[0]->toCode() + " and " + children[1]->toCode();
        	else if (what == "or")
        		code += children[0]->toCode() + " or " + children[1]->toCode();
        	return code;
        }
    };
}
