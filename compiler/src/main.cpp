#include <iostream>
#include <TEA/Token.hpp>
#include <TEA/Lexer.hpp>

using namespace std;
using namespace TEA;

int main(int argc, char** argv) {
    Lexer* lexer = new Lexer(
        "var text: string = \"Hello World!\";"
        "println(text);"
    );
    Token* tk;
    do {
        tk = lexer->GetNextToken();
        cout << tk->Type << " : " << tk->Value << endl;
    } while(tk->Type != TK_EOF);
}