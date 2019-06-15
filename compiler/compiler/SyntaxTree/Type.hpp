
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Type : public SyntaxTree {
        
	private:
        std::string type;
        
	public:
        Type(std::string typeArg) {type = typeArg;}
        
        virtual ~Type() = default;
        
        virtual std::string toCode() const {
        	return type;
        }

    };
}
