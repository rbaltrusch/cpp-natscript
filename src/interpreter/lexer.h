/*
Author: R. Baltrusch
*/

#pragma once
#ifndef LEXER_H
#define LEXER_H

#include <iostream>
#include <vector>
#include <string>

#include "tokenfactory.h"

class Lexer
{

    TokenFactory tokenFactory;

public:
    Lexer(TokenFactory);
    std::vector<Token> lex(std::string);

private:
    static std::vector<std::string> split(std::string);
};

#endif
