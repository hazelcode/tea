#include <TEA/Lexer.hpp>
#include <cstdlib>
#include <cctype>
#include <cstring>

TEA::Lexer::Lexer(std::string contents) {
    Contents = contents;
    Index = 0;
    C = Contents[Index];
}

void TEA::Lexer::Advance() {
    if(C != '\0' && Index < Contents.length()) {
        Index += 1;
        C = Contents[Index];
    }
}

void TEA::Lexer::SkipWhitespace() {
    if(C == ' ' || C == 10) {
        Advance();
    }
}

TEA::Token* TEA::Lexer::GetNextToken() {
    while(C != '\0' && Index < Contents.length()) {
        // If whitespace
        if(C == ' ' || C == 10) {
            SkipWhitespace();
        }

        // If alpha-numeric
        if(isalnum(C)) {
            return CollectId();
        }

        // If double quote
        if(C == '"') {
            return CollectString();
        }

        switch(C) {
            case '=':
                return ADV_WITH_TK(EQUALS);
                break;
            case ';':
                return ADV_WITH_TK(SEMI);
                break;
            case ':':
                return ADV_WITH_TK(COLON);
                break;
            case '(':
                return ADV_WITH_TK(LPAREN);
                break;
            case ')':
                return ADV_WITH_TK(RPAREN);
                break;
            case '{':
                return ADV_WITH_TK(LCURLBRACE);
                break;
            case '}':
                return ADV_WITH_TK(RCURLBRACE);
                break;
            case ',':
                return ADV_WITH_TK(COMMA);
                break;
        }
    }

    return new Token(TK_EOF, "\0");
}

TEA::Token* TEA::Lexer::CollectString() {
    Advance();

    char* value = (char*) calloc(1, sizeof(char));
    value[0] = '\0';

    while(C != '"') {
        char* s = CurrentCharAsString();
        value = (char*) realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        Advance();
    }

    Advance();

    return new Token(STRING, value);
}

TEA::Token* TEA::Lexer::CollectId() {
    char* value = (char*) calloc(1, sizeof(char));
    value[0] = '\0';

    while(isalnum(C)) {
        char* s = CurrentCharAsString();
        value = (char*) realloc(value, (strlen(value) + strlen(s) + 1) * sizeof(char));
        strcat(value, s);

        Advance();
    }

    return new Token(ID, value);
}

TEA::Token* TEA::Lexer::AdvanceWithToken(Token* token) {
    Advance();
    return token;
}

char* TEA::Lexer::CurrentCharAsString() {
    char* str = (char*) calloc(2, sizeof(char));
    str[0] = C;
    str[1] = '\0';

    return str;
}