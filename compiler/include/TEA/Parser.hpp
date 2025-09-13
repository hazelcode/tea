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

        /**
         * Eats the first token of the list, grabs it, and returns it.
         * Note: After the call to this function, the shifted token is always stored.
         * Keep that in mind!
         */
        Token* GetNextToken();

        /**
         * Send an error report to the stderr stream.
         */
        std::unique_ptr<ExprAST> LogError(const char* str);

        /**
         * Send an error report to the stderr stream.
         */
        std::unique_ptr<PrototypeAST> LogErrorP(const char* str);

        /**
         * Parses the token to a Number expression AST
         */
        std::unique_ptr<ExprAST> ParseNumberExpr();

        /**
         * Parses the parenthesis tokens to an expression.
         */
        std::unique_ptr<ExprAST> ParseParenExpr();

public:
        Parser(std::list<Token*> tokens);
    };
}