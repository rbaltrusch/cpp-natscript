/*
Author: R. Baltrusch
*/

#pragma once
#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H

#include <map>
#include <regex>
#include <iostream>

#include "token.h"
#include "value.h"

class TokenFactory {

    std::map<std::string, Token> tokens, regexTokens;
    std::map<std::string, std::regex> compiledRegexPatterns;
    int lineNumber;

    public:
        Token create_token (std::string);
        static Variable create_variable(std::string);
        static Value create_value(std::string);
};

#endif
