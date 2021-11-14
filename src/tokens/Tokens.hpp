/*
Author: R. Baltrusch
*/

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

ConstructorMap createTokensMap(void);
ConstructorMap createRegexTokensMap(void);

#endif
