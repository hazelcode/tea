#pragma once
#include <TEA/AST/ExprAST.hpp>

namespace TEA {
    // For numeric literals like: 7.5
    class NumberExprAST : public ExprAST {
        double Value;

public:
        NumberExprAST(double value) : Value(value) {}
    };
}