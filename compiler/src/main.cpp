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
    auto tokens = lexer->GenTokensList();

    for(auto& token : tokens) {
        cout << token->Type << " : " << token->Value << endl;
    }
}