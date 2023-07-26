#pragma once

#include "Parser.tab.hh"
#include <Lexer/Lexer.h>
#include <ASM/Publisher.h>
#include <ASM/Exceptions.h>

namespace yy
{
    class ASM final
    {
    private:
        Lexer _lexer;
        parser _parser;
        ::Publisher _publisher;
        ::ExceptionContainer _exceptions;

    public:
        ASM(std::istream &in, std::ostream &out);

        Lexer &GetLexer() noexcept;
        ::Publisher &GetPublisher() noexcept;
        ::ExceptionContainer &GetEC() noexcept;

        int Parse();
        location GetLocation() const;

        ~ASM() = default;
    };
}