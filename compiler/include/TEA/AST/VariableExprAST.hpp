#pragma once
#include <TEA/AST/ExprAST.hpp>
#include <string>

namespace TEA {
    // For referencing a variable, like: "x"
    class VariableExprAST : public ExprAST {
        std::string Name;

public:
        VariableExprAST(std::string& name) : Name(name) {}
    };
}