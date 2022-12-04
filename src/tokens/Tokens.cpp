/*
Author: R. Baltrusch
*/

#include <string>

#include "../interpreter/headers/Token.hpp"
#include "Tokens.hpp"

ConstructorMap createTokensMap(void)
{
    ConstructorMap tokens;
    tokens["this"] = create<Token>;
    tokens["is"] = create<Token>;
    tokens["true"] = create<TrueToken>;
    tokens["test"] = create<TestToken>;

    tokens["set"] = create<AssignLeft>;
    tokens["to"] = create<AssignRight>;
    tokens["print"] = create<Print>;

    return tokens;
};

ConstructorMap createRegexTokensMap(void)
{
    ConstructorMap regexTokens;
    regexTokens["^\\d+$"] = create<Integer>;
    regexTokens["^\\w+$"] = create<VarName>;
    return regexTokens;
};
