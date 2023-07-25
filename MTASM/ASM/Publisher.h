#pragma once

#include <ostream>
#include <queue>
#include <memory>

#include "Expressions.h"
#include "TypeDefs.h"

namespace yy
{
    class ASM;
}

class Publisher final
{
private:
    friend yy::ASM;

    std::queue<Expr> _qexpr;
    uint32_t _cexprs;
    std::ostream _out;

private:
    Publisher(std::ostream &out);

    void Write();

public:
    Publisher(const Publisher &) = delete;
    Publisher &operator=(const Publisher &) = delete;

    Publisher(Publisher &&) = delete;
    Publisher &operator=(Publisher &&) = delete;

    ~Publisher();

public:
    void Push(Expr &&expr);
    void Push(std::queue<Expr> &qexpr);

    uint32_t Size() const noexcept;
};
