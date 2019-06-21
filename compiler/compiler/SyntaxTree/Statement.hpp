
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
        		code += name + " := " + name + " + 1;\n";
        	}
        	
        	else if (what == "--") {
        		std::string name = children[0]->toCode();
        		code += name + " := " + name + " - 1;\n";
        	}
        	
        	else if (what == "=") {
        		code += children[0]->toCode() + " := " + children[1]->toCode() + ";\n";
        	}
        	
        	else if (what == "+=") {
        		std::string name = children[0]->toCode();
        		code += name + " := " + name + " + " + children[1]->toCode() + ";\n";
        	}
        	
        	else if (what == "-=") {
        		std::string name = children[0]->toCode();
        		code += name + " := " + name + " - " + children[1]->toCode() + ";\n";
        	}
        	
        	else if (what == "*=") {
        		std::string name = children[0]->toCode();
        		code += name + " := " + name + " * " + children[1]->toCode() + ";\n";
        	}
        	
        	else if (what == "/=") {
        		std::string name = children[0]->toCode();
        		code += name + " := " + name + " / " + children[1]->toCode() + ";\n";
        	}
        	
        	else if (what == "printf") {
        		code += "Ada.Text_IO.Put_Line(\"" + children[0]->toCode() + "\");\n";
        		if (children[0] == nullptr) code += "\n\nNullptr in Statement->toCode->printf\n\n";
        	}
        	return code;
        }
    };
}
