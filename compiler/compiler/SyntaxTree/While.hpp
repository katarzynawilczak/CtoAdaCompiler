
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class While : public SyntaxTree {
    
    public:
    
		While(SyntaxTree *conditions, SyntaxTree *statements) {
        	children.push_back(conditions);
        	children.push_back(statements);
        }
        
        virtual ~While() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "\nwhile ";
			code += children[0]->toCode() + " loop\n";
			
			code += "end loop;\n\n";

        	return code;
        }
    };
}
