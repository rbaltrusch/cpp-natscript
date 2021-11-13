/*
Author: R. Baltrusch
*/

#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <vector>
#include <string>

#include "TokenFactory.hpp"

class Lexer
{

    TokenFactory &tokenFactory;

public:
    Lexer(TokenFactory &tokenFactory);
    std::vector<Token> lex(std::string &text);

private:
    static std::vector<std::string> split(std::string &text);
};

#endif
