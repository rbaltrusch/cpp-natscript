/*
Author: R. Baltrusch
*/

#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <any>
#include <map>
#include <deque>
#include <vector>
#include <string>
#include <memory>

#include "Value.hpp"

struct ExpectedToken
{
public:
    std::vector<int> types{};
    int runOrder{};
    bool optional{};
    ExpectedToken(std::vector<int> types, int runOrder, bool optional)
        : runOrder{runOrder},
          optional{optional}
    {
        for (auto type : types)
        {
            this->types.push_back(type);
        }
    }
};

class BaseToken;
class TokenFactory;
class Interpreter;

typedef std::any *(*ValueFactory)(void);
typedef void *(*RunFunction)(Interpreter);

class Token
{
protected:
    static ValueFactory *valueFactory;
    static TokenFactory *tokenFactory;

    std::any value;
    int line;
    int runOrder;
    std::vector<Token> tokens;
    std::deque<ExpectedToken> expectedTokensCopy;

public:
    Token(std::any value, int line);
    void print(void);
    virtual void run(Interpreter &interpreter);
    bool checkOptionalToken(Token &token);
    void addToken(Token &token);
    virtual std::vector<Token> popTokens(std::deque<std::shared_ptr<Token>> &tokens);
    virtual void updateTokenFactory(TokenFactory &tokenFactory){};
    void setRunOrder(int runOrder);
    int getRunOrder(void);
    virtual void setValue(std::any &value);
    std::any getValue(void);
    virtual bool getFull(void);
    virtual bool getSatisfied(void);
    virtual int getType(void);
    static bool checkMatchingTypes(Token &token, ExpectedToken &expectedToken);

protected:
    virtual std::vector<ExpectedToken> getExpectedTokens(void);
    virtual void runSelf(Interpreter &interpreter){};
    std::vector<RunFunction> getRunFunctions(void);
    void checkTypes(Token &token);
};

template <class T>
std::unique_ptr<Token> create(std::any value, int line)
{
    return std::unique_ptr<T>(new T(value, line));
};

typedef std::unique_ptr<Token> (*TokenConstructor)(std::any value, int line);
typedef std::map<std::string, TokenConstructor> ConstructorMap;

#endif
