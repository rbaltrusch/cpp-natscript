/*
Author: R. Baltrusch
*/

#pragma once
#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H

#include <map>
#include <regex>
#include <string>
#include <memory>

#include "Token.hpp"
#include "Value.hpp"

class TokenFactory
{

    ConstructorMap tokens, regexTokens;
    std::map<std::string, std::regex> compiledRegexPatterns;
    int lineNumber;

public:
    TokenFactory(ConstructorMap tokens, ConstructorMap regexTokens);
    std::shared_ptr<Token> create_token(const std::string& string);
    static Variable create_variable(const std::string string);
    static Value create_value(const std::string string);
};

#endif
