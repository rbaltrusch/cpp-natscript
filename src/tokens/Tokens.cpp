/*
Author: R. Baltrusch
*/

#include <any>
#include <map>
#include <string>
#include <memory>

#include "../interpreter/headers/TokenFactory.hpp"
#include "../interpreter/headers/Token.hpp"
#include "Tokens.hpp"

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

ConstructorMap createTokensMap(void)
{
    ConstructorMap tokens;
    tokens["this"] = create<Token>;
    tokens["is"] = create<Token>;
    tokens["a"] = create<Token>;
    tokens["true"] = create<TrueToken>;
    tokens["test"] = create<TestToken>;
    return tokens;
};

ConstructorMap createRegexTokensMap(void)
{
    ConstructorMap regexTokens;
    regexTokens["^\\d+$"] = create<Integer>;
    regexTokens["^\\w+$"] = create<VarName>;
    return regexTokens;
};
