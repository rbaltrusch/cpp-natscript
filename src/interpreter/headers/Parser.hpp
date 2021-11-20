/*
Author: R. Baltrusch
*/

#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <deque>

#include "Token.hpp"

class Parser
{

    std::stack<Token> token_stack;

public:
    Parser();
    std::vector<Token> parse(std::deque<std::shared_ptr<Token>> &tokens);
};

#endif
