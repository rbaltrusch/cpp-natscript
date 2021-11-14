/*
Author: R. Baltrusch
*/

#include <string>
#include <vector>
#include <memory>

#include "../headers/Token.hpp"
#include "../headers/Lexer.hpp"
#include "../headers/TokenFactory.hpp"

Lexer::Lexer(TokenFactory &tokenFactory)
    : tokenFactory{tokenFactory} {};

std::vector<std::shared_ptr<Token>> Lexer::lex(std::string &text)
{
    std::vector<std::shared_ptr<Token>> tokens;
    std::vector<std::string> strings = this->split(text);
    for ( const std::string& string : strings)
    {
        std::shared_ptr<Token> token = this->tokenFactory.create_token(string);
        tokens.push_back(token);
    }
    return tokens;
};

std::vector<std::string> Lexer::split(std::string &text)
{
    std::vector<std::string> tokens;
    std::string delim = " ";

    auto start = 0U;
    auto end = text.find(delim);
    while (end != std::string::npos)
    {
        std::string element = text.substr(start, end - start);
        tokens.push_back(element);

        start = end + delim.length();
        end = text.find(delim, start);
    }

    std::string lastElement = text.substr(start, end);
    tokens.push_back(lastElement);

    return tokens;
};
