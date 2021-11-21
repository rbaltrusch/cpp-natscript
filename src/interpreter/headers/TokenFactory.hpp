/*
Author: R. Baltrusch
*/

#pragma once
#ifndef TOKENFACTORY_H
#define TOKENFACTORY_H

#include <any>
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
    std::shared_ptr<Token> createToken(const std::string& string);
    static Variable createVariable(const std::string &name);
    static Value createValue(std::any &value);
};

#endif
