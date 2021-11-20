/*
Author: R. Baltrusch
*/

#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <vector>

#include "Token.hpp"

class Parser
{

    std::stack<Token> token_stack;

public:
    Parser();
    std::vector<Token> parse(std::vector<Token> &tokens);
};

#endif
