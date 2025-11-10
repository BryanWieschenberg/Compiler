#pragma once

#include "parser.hpp"

class Generator {
public:
    inline Generator(NodeReturn root) :
        root_(std::move(root))
    {}

    [[nodiscard]] std::string generate() const {
        std::stringstream output;
        output << "global _start\n_start:\n";
        output << "    mov rax, 60\n";
        output << "    mov rdi, " << root_.expr.INT_LITERAL.value.value() << "\n";
        output << "    syscall\n";
        return output.str();
    }

private:
    const NodeReturn root_;
};