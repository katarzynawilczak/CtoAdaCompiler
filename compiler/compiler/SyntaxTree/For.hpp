
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class For : public SyntaxTree {
    
    public:
    
		For(SyntaxTree *forExpression, SyntaxTree *statements) {
        	children.push_back(forExpression);
        	children.push_back(statements);
        }
        
        virtual ~For() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "for" + children[0]->toCode() + "loop\n";
			code += children[1]->toCode();
			code += "end loop;\n\n";

        	return code;
        }
    };
}
