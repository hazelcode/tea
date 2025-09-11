#pragma once
#include <TEA/AST/ExprAST.hpp>
#include <string>
#include <vector>
#include <memory>

namespace TEA {
    // For function calls
    class CallExprAST : public ExprAST {
        std::string Callee;
        std::vector<std::unique_ptr<ExprAST>> Args;

public:
        CallExprAST(const std::string& callee, std::vector<std::unique_ptr<ExprAST>> args)
            : Callee(callee), Args(std::move(args)) {}
    };
}