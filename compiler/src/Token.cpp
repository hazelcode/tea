#include <Token.hpp>
#include <cstdlib>
#include <iostream>

TEA::Token::Token(TEA::TokenType type, std::string value) {
    this->Type = type;
    this->Value = value;
}