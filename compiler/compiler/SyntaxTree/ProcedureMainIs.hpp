
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class ProcedureMainIs : public SyntaxTree {
    
    public:
        ProcedureMainIs() {}
        
        virtual ~ProcedureMainIs(){};
        
        virtual std::string toCode() const {
        	return "procedure Output Is\n\n";
        }
    
    };
}
