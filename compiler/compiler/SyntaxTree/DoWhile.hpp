
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class DoWhile : public SyntaxTree {
    
    public:
    
		DoWhile(SyntaxTree *statements, SyntaxTree *conditions) {
        	children.push_back(statements);
        	children.push_back(conditions);
        }
        
        virtual ~DoWhile() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "\nloop\n";
			code += children[0]->toCode();
			
			code += "exit when " + children[1]->toCode() + ";\n";
			code += "end loop;\n";

        	return code;
        }
    };
}
