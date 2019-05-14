
#pragma once
#include "SyntaxTree.hpp"

namespace compiler {
    class Type : public SyntaxTree {
    
	public:
        Type(const std::string &type) : type(type) {}
        
        virtual ~Type() = default;
        
        virtual std::string toCode() const {
        	return type;
        }
    
	private:
        std::string type;
    };
}
