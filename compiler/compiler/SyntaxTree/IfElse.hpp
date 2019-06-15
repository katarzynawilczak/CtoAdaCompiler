
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class IfElse : public SyntaxTree {

    public:
    
    	IfElse(SyntaxTree *conditions, SyntaxTree *statements, SyntaxTree *elseifs) {
        	children.push_back(conditions);
        	children.push_back(statements);
        	children.push_back(elseifs);
        }
        
        IfElse(SyntaxTree *conditions, SyntaxTree *statements, SyntaxTree *elseifs, SyntaxTree *elseStatements) {
        	children.push_back(conditions);
        	children.push_back(statements);
        	children.push_back(elseifs);
        	children.push_back(elseStatements);
        }
        
        virtual ~IfElse() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
			code += "\nif ";
			
			code += children[0]->toCode() + " then\n";
			
			code += children[1]->toCode();
			
			if (children[2] != nullptr)
				code += children[2]->toCode();
			
			if (children[3] != nullptr)
				code += "else\n" + children[3]->toCode();
			
			
			code += "end if;\n\n";

        	return code;
        }
        
    };
}
