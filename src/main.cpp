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
    Parser parser;
    Interpreter interpreter;
    string text = "this is a true test";
    auto lexedTokens = lexer.lex(text);
    auto parsedTokens = parser.parse(lexedTokens);
    for (auto tok : parsedTokens)
    {
        tok.print();
    }

    cout << "done!";
}
