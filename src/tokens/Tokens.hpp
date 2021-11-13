/*
Author: R. Baltrusch
*/

#include "../interpreter/Token.hpp"
#include "../interpreter/Interpreter.hpp"

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
