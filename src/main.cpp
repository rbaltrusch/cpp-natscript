/*
Author: R. Baltrusch
*/

#include <any>
#include <vector>
#include <memory>
#include <string>
#include <iostream>

#include "interpreter/headers/Token.hpp"
#include "interpreter/headers/Lexer.hpp"
#include "interpreter/headers/Parser.hpp"
#include "interpreter/headers/TokenFactory.hpp"
#include "interpreter/headers/Interpreter.hpp"
#include "tokens/tokens.hpp"

using namespace std;

int main()
{
    ConstructorMap tokens = createTokensMap();
    ConstructorMap regexTokens = createRegexTokensMap();
    TokenFactory tokenFactory(tokens, regexTokens);

    Lexer lexer(tokenFactory);
    string text = "this is a true test";
    for (std::shared_ptr<Token> tok : lexer.lex(text))
    {
        tok->print();
    }

    Parser parser;
    Interpreter interpreter;
    cout << "done!";
}
