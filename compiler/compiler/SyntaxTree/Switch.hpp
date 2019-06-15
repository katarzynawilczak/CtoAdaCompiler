
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Switch : public SyntaxTree {

    public:
    
    	Switch(SyntaxTree *name, SyntaxTree *cases) {
        	children.push_back(name);
        	children.push_back(cases);
        }
        
        Switch(SyntaxTree *name, SyntaxTree *cases, SyntaxTree *defaultClause) {
        	children.push_back(name);
        	children.push_back(cases);
        	children.push_back(defaultClause);
        }
        
        virtual ~Switch() {}
        
        virtual std::string toCode() const {
        	std::string code;
        	
			code += "case " + children[0]->toCode() + " is\n";
			code += children[1]->toCode();
			if (children[2] != nullptr)
				code += children[2]->toCode();

			code += "end case;\n";
			
        	return code;
        }
        
    };
}
