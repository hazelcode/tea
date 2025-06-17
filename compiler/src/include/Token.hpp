#pragma once
#include <iostream>

namespace TEA
{
    enum TokenType
    {
        ID,
        EQUALS,
        STRING,
        SEMI,
        LPAREN,
        RPAREN,
        LCURLBRACE,
        RCURLBRACE,
        COMMA,
        TK_EOF
    };

    class Token
    {
    public:
        TokenType Type;

        std::string Value;

        Token(TokenType type, std::string value);
    };
}