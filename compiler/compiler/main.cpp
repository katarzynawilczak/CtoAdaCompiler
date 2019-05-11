
#include <iostream>
#include <memory>
#include <stdio.h>
#include "SyntaxTree/SyntaxTree.hpp"
using namespace std;

extern int yyparse();
extern int yylineno;
extern std::unique_ptr<compiler::SyntaxTree> root;
    
int main() {
    int result = yyparse();

    if (result == 0)
        cout << "\nValid input" << endl;
    else
        cout << "Invalid input" << endl;
    //cout << "The input has " << yylineno << " lines\n\n" << endl;
    
    cout << root->toCode() << endl;
    
    return result;
}
