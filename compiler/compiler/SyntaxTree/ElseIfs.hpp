
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class ElseIfs : public SyntaxTree {
    
    public:
    
		ElseIfs(SyntaxTree *conditions, SyntaxTree *statements) {
        	children.push_back(conditions);
        	children.push_back(statements);

        }
        
        virtual ~ElseIfs() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "elsif ";
			code += children[0]->toCode() + " then\n";
			
			code += children[1]->toCode();
			
			if (children[2] != nullptr)
				code += children[2]->toCode();

        	return code;
        }
    };
}
