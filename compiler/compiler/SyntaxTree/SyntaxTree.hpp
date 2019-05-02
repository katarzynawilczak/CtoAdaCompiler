
#pragma once
#include <vector>
#include <string>

namespace compiler {
    class SyntaxTree {
    
    public:
        SyntaxTree();
        
        virtual ~SyntaxTree();
        
        virtual std::string toCode() const;
    
    protected:
        std::vector << std::unique_ptr<SyntaxTree> > children;
    };
}
