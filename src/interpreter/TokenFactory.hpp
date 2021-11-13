/*
Author: R. Baltrusch
*/

#pragma once
#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H

#include <map>
#include <regex>
#include <string>

#include "Token.hpp"
#include "Value.hpp"

class BaseToken;
class TokenFactory
{

    ConstructorMap tokens, regexTokens;
    std::map<std::string, std::regex> compiledRegexPatterns;
    int lineNumber;

public:
    TokenFactory(ConstructorMap tokens, ConstructorMap regexTokens);
    BaseToken create_token(std::string);
    static Variable create_variable(std::string);
    static Value create_value(std::string);
};

#endif
