#pragma once
#include <TEA/Token.hpp>

namespace TEA {
    class Lexer {
        public:
            char C;
            uint Index;
            std::string Contents;

            /**
             * Initializes the TEA Lexer
             */
            Lexer(std::string contents);

            /**
             * If the current char isn't null character and the index is minor
             * compared to the length of the lexer contents, increments the current index
             * and sets the current character to the next one.
             */
            void Advance();

            /**
             * The lexer advances while the current char is a whitespace or a new line.
             */
            void SkipWhitespace();

            /**
             * Gets the next token.
             */
            Token* GetNextToken();

            /**
             * Collects a string until the lexer detects a double quote
             */
            Token* CollectString();

            /**
             * Collects an identifier until the lexer detects a non-alpha-numeric character.
             */
            Token* CollectId();

            /**
             * Makes the lexer advance, and returns the provided token.
             */
            Token* AdvanceWithToken(Token* token);

            /**
             * Get current char as string;
             */
            char* CurrentCharAsString();
    };
}