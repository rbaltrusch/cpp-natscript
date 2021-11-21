/*
Author: R. Baltrusch
*/

#include <any>
#include <map>
#include <string>
#include <memory>

#include "../interpreter/headers/Token.hpp"
#include "Tokens.hpp"

//template <class T>
//Token create(std::any *value, int line) { return T(value, line); }
//Token *(*createToken)(std::any *value, int line) = create<Token>(value, line);

class TrueToken : public Token
{
public:
    TrueToken(std::any value, int line) : Token(value, line) //{ this->value = 1; };
    {
        this->value = 1;
        for (auto expectedToken : this->getExpectedTokens())
        {
            this->expectedTokensCopy.push_back(expectedToken);
        }
    };

protected:
    std::vector<ExpectedToken> getExpectedTokens(void)
    {
        std::vector<ExpectedToken> expectedTokens;
        expectedTokens.push_back(ExpectedToken({2}, 1, false));
        return expectedTokens;
    };

    int getType(void)
    {
        return 1;
    };
};

class TestToken : public Token
{
public:
    TestToken(std::any value, int line) : Token(value, line) { this->value = 2; };

protected:
    int getType(void)
    {
        return 2;
    };
};

ConstructorMap createTokensMap(void)
{
    //Token token = create<Token>(&value, 1);

    //std::unique_ptr<Token> *(*createToken)(std::any * value, int line) = create<Token>(value, line);
    ConstructorMap tokens;
    tokens["this"] = create<Token>;
    tokens["is"] = create<Token>;
    tokens["a"] = create<Token>;
    tokens["true"] = create<TrueToken>;
    tokens["test"] = create<TestToken>;
    //{{"a", &createToken}};
    return tokens;
};

ConstructorMap createRegexTokensMap(void)
{
    ConstructorMap regexTokens;
    //{{"a", &createToken}};
    return regexTokens;
};
