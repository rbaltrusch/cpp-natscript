/*
Author: R. Baltrusch
*/

#include <any>
#include <map>
#include <string>
#include <memory>

#include "../interpreter/Token.hpp"
#include "Tokens.hpp"

//template <class T>
//Token create(std::any *value, int line) { return T(value, line); }
//Token *(*createToken)(std::any *value, int line) = create<Token>(value, line);

ConstructorMap createTokensMap(void)
{
    //Token token = create<Token>(&value, 1);

    //std::unique_ptr<Token> *(*createToken)(std::any * value, int line) = create<Token>(value, line);
    TokenConstructor createToken = create<Token>;
    ConstructorMap tokens;
    tokens["this"] = createToken;
    tokens["is"] = createToken;
    tokens["a"] = createToken;
    tokens["test"] = createToken;
    //{{"a", &createToken}};
    return tokens;
};

ConstructorMap createRegexTokensMap(void)
{
    ConstructorMap regexTokens;
    //{{"a", &createToken}};
    return regexTokens;
};
