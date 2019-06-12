
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Statement : public SyntaxTree {
    private:
    	std::string what;
    
    public:
        Statement(std::string str, SyntaxTree *tree) {
        	what = str;
        	children.push_back(tree);
        }
        
        Statement(std::string str, SyntaxTree *tree, SyntaxTree *otherTree) {
        	what = str;
        	children.push_back(tree);
        	children.push_back(otherTree);
        }
        
        virtual ~Statement() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	if (what == "++") {
        		std::string name = children[0]->toCode();
        		code += name + " = " + name + " + 1;\n";
        	}
        	
        	if (what == "--") {
        		std::string name = children[0]->toCode();
        		code += name + " = " + name + " - 1;\n";
        	}
        	
        	if (what == "=") {
        		//std::string name = children[0]->toCode();
        		//code += name + " = " + name + " + 1;\n";
        	}
        	
        	if (what == "+=") {
        		std::string name = children[0]->toCode();
        		//code += name + " = " + name + " + " + children[1]->toCode() + ";";
        	}
        	
        	if (what == "-=") {
        		std::string name = children[0]->toCode();
        		//code += name + " = " + name + " - " + children[1]->toCode() + ";";
        	}
        	
        	if (what == "*=") {
        		std::string name = children[0]->toCode();
        		//code += name + " = " + name + " * " + children[1]->toCode() + ";";
        	}
        	
        	if (what == "/=") {
        		std::string name = children[0]->toCode();
        		//code += name + " = " + name + " / " + children[1]->toCode() + ";";
        	}
        	return code;
        }
    };
}
