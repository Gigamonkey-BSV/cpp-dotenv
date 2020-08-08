#pragma once


#include "ReplaceStack.h"
#include "SymbolsTable.h"
#include "LineBaseListener.h"
#include "LineParser.h"

#include <string>


namespace dotenv
{
    class ResolverListener final: public LineBaseListener
    {
    public:

        ResolverListener(const std::string& key, SymbolsTable& symbols_table);
        ResolverListener(const ResolverListener& resovler_listener) = default;
        virtual ~ResolverListener() = default;

        virtual void enterLine(LineParser::LineContext* ctx) override;
        virtual void exitLine(LineParser::LineContext* ctx) override;

        virtual void exitVariable(LineParser::VariableContext* ctx) override;

    private:

        const std::string& key;
        SymbolsTable& symbols_table;
        ReplaceStack resolve_stack;

    };
}
