
#pragma once

#include <iostream>
#include "SyntaxTree.hpp"

namespace compiler {
    class Library : public SyntaxTree {
    
    public:
    
		Library(SyntaxTree *name, SyntaxTree *h) {
        	children.push_back(name);
        	children.push_back(h);
        }
        
        virtual ~Library() {}
        
        virtual std::string toCode() const {
        	std::string code;

			if (children[0]->toCode()=="stdio" && children[1]->toCode()=="h")
				code += "with Ada.Text_IO;\n\n";

        	return code;
        }
    };
}
