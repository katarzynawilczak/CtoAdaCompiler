
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Condition : public SyntaxTree {
    
    private:
    	std::string what;
    	
    public:
    
		Condition(std::string str, SyntaxTree *name) {
        	what = str;
        	children.push_back(name);
        }
        
        Condition(std::string str, SyntaxTree *exp1, SyntaxTree *op, SyntaxTree *exp2) {
        	what = str;
        	children.push_back(exp1);
        	children.push_back(op);
        	children.push_back(exp2);
        }
        
        virtual ~Condition() {}
        
        virtual std::string toCode() const {
        	std::string code;
			
			if (what == "name op exp")
        		code += children[0]->toCode() + " " + children[1]->toCode() + " " + children[2]->toCode();
        		
        	else if (what == "(name) op exp")
        		code += "(" + children[0]->toCode() + ") " + children[1]->toCode() + " " + children[2]->toCode();
        		
        	else if (what == "(name) op (name)")
        		code += "(" + children[0]->toCode() + ") " + children[1]->toCode() + " (" + children[2]->toCode() + ")";
        		
        	else if (what == "name op (name)")
        		code += children[0]->toCode() + " " + children[1]->toCode() + " (" + children[2]->toCode() + ")";
        		
        	else if (what == "string")
        		code += "\"" + children[0]->toCode() + "\"";
        		
        	return code;
        }
    };
}
