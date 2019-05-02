
#include <iostream>
using namespace std;

extern int yyparse();
extern int yylineno;
    
int main() {
    int result = yyparse();
    if (result == 0)
        cout << "Valid input" << endl;
    else
        cout << "Invalid input" << endl;
    cout << "The input has " << yylineno << " lines" << endl;
    return result;
}
