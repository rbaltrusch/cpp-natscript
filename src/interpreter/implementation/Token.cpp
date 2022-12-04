/*
Author: R. Baltrusch
*/

#include <any>
#include <iostream>
#include <stdexcept>
#include <algorithm>

#include "../headers/Token.hpp"
#include "../../tokens/Tokens.hpp"

Token::Token(std::any value, int line)
    : value{value},
      line{line},
      runOrder{0} {};

void Token::print(void)
{
    std::cout << "line: " << this->line << std::endl;
    std::cout << "value: " << std::any_cast<int>(this->value) << std::endl;
    std::cout << "type: " << this->getType() << std::endl;
    std::cout << "inside:" << std::endl;
    for (auto token : this->tokens)
    {
        std::cout << "----";
        token.print();
        std::cout << "----";
    }
    std::cout << std::endl;
};

bool Token::checkOptionalToken(Token &token)
{
    for (auto expectedToken : this->expectedTokensCopy)
    {
        if (this->checkMatchingTypes(token, expectedToken))
        {
            return true;
        };
    }
    return false;
};

void Token::addToken(Token &token)
{
    if (this->getFull())
    {
        throw std::invalid_argument("InternalParseError: Token is already full!");
    }

    this->checkTypes(token);
    this->tokens.push_back(token);
};

bool Token::getFull(void)
{
    return this->expectedTokensCopy.empty();
};

bool Token::getSatisfied(void)
{
    for (auto token : this->expectedTokensCopy)
    {
        if (!token.optional)
        {
            return false;
        }
    }
    return true;
};

bool Token::checkMatchingTypes(Token &token, ExpectedToken &expectedToken)
{
    for (auto type : expectedToken.types)
    {
        if (token.getType() == type)
        {
            return true;
        }
    }
    return false;
}

void Token::checkTypes(Token &token)
{
    /* This function has side effects!
    It modifies this->expectedTokensCopy until a type match was found for token.
    */
    while (!this->expectedTokensCopy.empty())
    {
        auto expectedToken = this->expectedTokensCopy.front();
        this->expectedTokensCopy.pop_front();
        if (this->checkMatchingTypes(token, expectedToken))
        {
            token.setRunOrder(expectedToken.runOrder);
            return;
        }

        if (!expectedToken.optional)
        {
            token.print();
            throw std::invalid_argument("InternalParseTypeError: Mandatory token could not be matched!");
        }
    }
    throw std::invalid_argument("ParseException: token did not match any types!");
};

void Token::setRunOrder(int runOrder)
{
    this->runOrder = runOrder;
};

int Token::getRunOrder(void)
{
    return this->runOrder;
};

int Token::getType(void)
{
    int TOKEN_BASE_TYPE = 0;
    return TOKEN_BASE_TYPE;
};

std::vector<Token> Token::popTokens(std::deque<std::shared_ptr<Token>> &tokens)
{
    std::vector<Token> poppedTokens;
    return poppedTokens;
};

std::vector<ExpectedToken> Token::getExpectedTokens(void)
{
    std::vector<ExpectedToken> expectedTokens;
    return expectedTokens;
};

void Token::setValue(std::any &value)
{
    this->value = value;
};

std::any Token::getValue(void)
{
    return this->value;
};

void Token::run(Interpreter &interpreter){
    if (!this->getSatisfied())
    {
        throw std::invalid_argument("SyntaxException: token is not satisfied");
    }

/*     std::sort(this->tokens.begin(),
              this->tokens.end(),
              [](auto a, auto b) {return a.runOrder < b.runOrder; }); */
    for (auto token : this->tokens)
    {
        std::cout << "running: " << token.getType() << std::endl;
        token.run(interpreter);
    }
    this->runSelf(interpreter);
};
