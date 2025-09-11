#pragma once
#include <TEA/AST/PrototypeAST.hpp>
#include <TEA/AST/ExprAST.hpp>
#include <memory>

namespace TEA {
    // Represents a function definition itself
    class FunctionAST {
        std::unique_ptr<PrototypeAST> Proto;
        std::unique_ptr<ExprAST> Body;

public:
        FunctionAST(std::unique_ptr<PrototypeAST> proto, std::unique_ptr<ExprAST> body)
            : Proto(std::move(proto)), Body(std::move(body)) {}
    };
}