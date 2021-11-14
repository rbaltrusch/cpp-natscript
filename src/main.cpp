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

void print(std::shared_ptr<Token> &token) { token->print(); };

int main()
{
    ConstructorMap tokens = createTokensMap();
    ConstructorMap regexTokens = createRegexTokensMap();


    std::any value = 1;
    std::shared_ptr<Token> myToken = tokens["a"](value, 1);
    print(myToken);
    myToken->print();

    TokenFactory tokenFactory(tokens, regexTokens);

    Lexer lexer(tokenFactory);
    string text = "this is a test";
    for (std::shared_ptr<Token> tok : lexer.lex(text))
    {
        tok->print();
    }

    Parser parser;
    Interpreter interpreter;
    cout << "done!";
}
