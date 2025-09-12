#include <TEA/Parser.hpp>
#include <TEA/AST/NumberExprAST.hpp>

TEA::Parser::Parser(std::list<Token*> tokens) : m_tokens(tokens) {}

TEA::Token* TEA::Parser::GetNextToken() {
    m_currentToken = m_tokens.front();
    m_tokens.pop_front();
}

std::unique_ptr<TEA::ExprAST> TEA::Parser::LogError(const char* str) {
    fprintf(stderr, "ERROR: %s", str);
    return nullptr;
}

std::unique_ptr<TEA::PrototypeAST> TEA::Parser::LogErrorP(const char* str) {
    fprintf(stderr, "ERROR: %s", str);
    return nullptr;
}

std::unique_ptr<TEA::ExprAST> TEA::Parser::ParseNumberExpr() {
    GetNextToken(); // consume the number
    auto Result = std::make_unique<TEA::NumberExprAST>(std::atof(m_currentToken->Value.c_str()));
    return std::move(Result);
}