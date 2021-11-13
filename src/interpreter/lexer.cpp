/*
Author: R. Baltrusch
*/

#include "Lexer.hpp"
#include "TokenFactory.hpp"

Lexer::Lexer(TokenFactory &tokenFactory)
    : tokenFactory{tokenFactory} {};
