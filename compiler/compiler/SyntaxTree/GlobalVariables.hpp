
//#pragma once

#include <iostream>

namespace global {
    class GlobalVariables {
    
    public:
    
    	GlobalVariables() {		// for procedure (without return)
        }
        
        virtual ~GlobalVariables() {}
        
        bool declarationPlace = true;
    };
}
