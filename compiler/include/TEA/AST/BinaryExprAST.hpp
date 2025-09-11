#pragma once
#include <TEA/AST/ExprAST.hpp>
#include <memory>

namespace TEA {
    // For a binary operator
    class BinaryExprAST : public ExprAST {
        char Op;
        std::unique_ptr<ExprAST> Left, Right;

public:
        BinaryExprAST(char op, std::unique_ptr<ExprAST> left, std::unique_ptr<ExprAST> right)
            : Op(op), Left(std::move(left)), Right(std::move(right)) {}
    };
}