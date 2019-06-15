
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Case : public SyntaxTree {
    
    public:
    
		Case(SyntaxTree *value, SyntaxTree *statements, SyntaxTree *breakClause) {
        	children.push_back(value);
        	children.push_back(statements);
        	children.push_back(breakClause);
        }
        
        virtual ~Case() {}
        
        virtual std::string toCode() const {
        	std::string code;

			code += "when " + children[0]->toCode() + " =>\n";
			code += children[1]->toCode();

        	return code;
        }
    };
}
