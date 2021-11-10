/*
Author: R. Baltrusch
*/

#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <vector>

#include "token.h"

class Parser
{

    std::stack<Token> token_stack;

public:
    std::vector<Token> parse(std::vector<Token>);

private:
    static void popLeadingTokens(std::vector<Token>);
};

#endif
