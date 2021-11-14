/*
Author: R. Baltrusch
*/

#include "Token.hpp"
#include "TokenFactory.hpp"

TokenFactory::TokenFactory(ConstructorMap tokens, ConstructorMap regexTokens)
    : tokens(tokens),
      regexTokens(regexTokens){};
