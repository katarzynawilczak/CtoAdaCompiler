
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Default : public SyntaxTree {
    
    public:
    
		Default(SyntaxTree *statements, SyntaxTree *breakClause) {
        	children.push_back(statements);
        	children.push_back(breakClause);
        }
        
        virtual ~Default() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "when others =>\n";
			code += children[0]->toCode();

        	return code;
        }
    };
}
