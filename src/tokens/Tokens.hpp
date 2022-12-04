/*
Author: R. Baltrusch
*/

#include <any>
#include <map>
#include <string>
#include <memory>
#include <iostream>

#include "../interpreter/headers/TokenFactory.hpp"

#include "../interpreter/headers/Token.hpp"
#include "../interpreter/headers/Interpreter.hpp"

#pragma once
#ifndef TOKENS_H
#define TOKENS_H

class ValueToken : public Token
{

public:
    ValueToken();

protected:
    void runSelf(Interpreter interpreter);
};

class TrueToken : public Token
{
public:
    TrueToken(std::any value, int line) : Token(value, line)
    {
        this->value = 1;
        this->expectedTokensCopy.push_back(ExpectedToken({2}, 1, false));
    };

    int getType(void) { return 1; };
};

class TestToken : public Token
{
public:
    TestToken(std::any value, int line) : Token(value, line) { this->value = 2; };

protected:
    int getType(void) { return 2; };
};

class Integer : public Token
{
public:
    Integer(std::any value, int line) : Token(value, line) { this->value = 3; };
    int getType(void) { return 3; };
};

class VarName : public Token
{
public:
    VarName(std::any value, int line) : Token(value, line) { this->value = 3; };
    int getType(void) { return 4; };
    void print(void) { Token::print(); };

protected:
    void runSelf(Interpreter &interpreter)
    {
        auto name = std::any_cast<std::string>(this->value);
        auto variable = (interpreter.checkVariable(name))
                            ? interpreter.getVariable(name)
                            : this->tokenFactory->createVariable(name);
        interpreter.stackAppend(variable);

        std::string itName = "it";
        interpreter.setVariable(itName, variable);
    };
};

class AssignRight : public Token
{
public:
    AssignRight(std::any value, int line) : Token(value, line) { this->value = 4; };
    int getType(void) { return 5; };
};

class AssignLeft : public Token
{
public:
    AssignLeft(std::any value, int line) : Token(value, line)
    {
        this->value = 5;
        this->expectedTokensCopy.push_back(ExpectedToken({4}, 2, false));
        this->expectedTokensCopy.push_back(ExpectedToken({5}, 1, false));
        this->expectedTokensCopy.push_back(ExpectedToken({3}, 0, false));
    };
    int getType(void) { return 6; };

protected:
    void runSelf(Interpreter &interpreter)
    {
        auto variable = interpreter.stackPop();
        auto value = interpreter.stackPop();
        variable->value = value->value;
        auto name = variable->getName();
        interpreter.setVariable(name, variable);
    }
};

class Print : public Token
{
public:
    Print(std::any value, int line) : Token(value, line)
    {
        this->value = 6;
        this->expectedTokensCopy.push_back(ExpectedToken({3}, 0, false));
    };
    int getType(void) { return 7; };

protected:
    void runSelf(Interpreter &interpreter)
    {
        auto value = interpreter.stackPop();
        std::cout << std::any_cast<int>(value->value);
    }
};

ConstructorMap createTokensMap(void);
ConstructorMap createRegexTokensMap(void);

#endif
