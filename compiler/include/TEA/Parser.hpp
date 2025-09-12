#pragma once

#include <TEA/Token.hpp>
#include <TEA/AST/ExprAST.hpp>
#include <TEA/AST/PrototypeAST.hpp>
#include <memory>
#include <list>

namespace TEA {
    class Parser {
private:
        // The tokens provided from the lexer output
        std::list<Token*> m_tokens;

        // The current token that needs to be parsed
        Token* m_currentToken;
        Token* GetNextToken();
        std::unique_ptr<ExprAST> LogError(const char* str);
        std::unique_ptr<PrototypeAST> LogErrorP(const char* str);
        std::unique_ptr<ExprAST> ParseNumberExpr();

public:
        Parser(std::list<Token*> tokens);
    };
}