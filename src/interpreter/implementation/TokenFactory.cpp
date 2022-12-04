/*
Author: R. Baltrusch
*/

#include <map>
#include <regex>
#include <memory>
#include <string>
#include <sstream>
#include <stdexcept>

#include "../headers/Token.hpp"
#include "../headers/TokenFactory.hpp"

TokenFactory::TokenFactory(ConstructorMap tokens, ConstructorMap regexTokens)
    : tokens(tokens),
      regexTokens(regexTokens){};

std::shared_ptr<Token> TokenFactory::createToken(const std::string& string)
{
    ConstructorMap::iterator iterator = this->tokens.find(string);
    if (iterator != this->tokens.end())
    {
        std::any value = 0;
        int line = 1;
        std::shared_ptr<Token> token = iterator->second(value, line);
        return token;
    }

    ConstructorMap::iterator regexIterator;
    for ( regexIterator = this->regexTokens.begin(); regexIterator != this->regexTokens.end(); regexIterator++)
    {
        std::regex pattern(regexIterator->first);

        if (std::regex_match(string, pattern))
        {
            std::any value = string;
            int line = 1;
            std::shared_ptr<Token> token = regexIterator->second(value, line);
            return token;
        }
    }

    std::stringstream messageStream;
    messageStream << "Invalid Token: " << string;
    std::string message = messageStream.str();
    throw std::invalid_argument(message);
};

std::shared_ptr<Value> TokenFactory::createVariable(const std::string &name)
{
    Variable variable(name);
    return std::shared_ptr<Value>(&variable);
};

std::shared_ptr<Value> TokenFactory::createValue(std::any &value)
{
    Value variable(value);
    return std::shared_ptr<Value>(&variable);
};
