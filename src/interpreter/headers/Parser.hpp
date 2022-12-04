/*
Author: R. Baltrusch
*/

#pragma once
#ifndef PARSER_H
#define PARSER_H

#include <stack>
#include <deque>

#include "Token.hpp"

typedef std::vector<std::shared_ptr<Token>> TokenVector;
typedef std::stack<std::shared_ptr<Token>> TokenStack;

class Parser
{

    TokenStack tokenStack;

public:
    Parser();
    TokenVector parse(std::deque<std::shared_ptr<Token>> tokens);
};

#endif
