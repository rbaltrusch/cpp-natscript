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
#include "tokens/Tokens.hpp"

using namespace std;

int main()
{
    ConstructorMap tokens = createTokensMap();
    ConstructorMap regexTokens = createRegexTokensMap();
    TokenFactory tokenFactory(tokens, regexTokens);

    Lexer lexer(tokenFactory);
    Parser parser;
    Interpreter interpreter;
    //string text = "set a to 1 and print 2";
    string text = "1";
    auto lexedTokens = lexer.lex(text);
    auto parsedTokens = parser.parse(lexedTokens);
    for (auto token : parsedTokens)
    {
        //interpreter.interpret(token);
        //token->run(interpreter);
        token->print();
    }

    cout << "done!" << std::endl;
}
