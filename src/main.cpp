/*
Author: R. Baltrusch
*/

#include <any>
#include <iostream>
#include <memory>

#include "interpreter/Token.hpp"
#include "interpreter/Lexer.hpp"
#include "interpreter/Parser.hpp"
#include "interpreter/TokenFactory.hpp"
#include "interpreter/Interpreter.hpp"
#include "tokens/tokens.hpp"

using namespace std;

void print(std::unique_ptr<Token> token) { token->print(); };

int main()
{
    ConstructorMap tokens = createTokensMap();
    ConstructorMap regexTokens = createRegexTokensMap();


    std::any value = 1;
    std::unique_ptr<Token> myToken = tokens["a"](value, 1);
    print(myToken);
    myToken->print();

    TokenFactory tokenFactory(tokens, regexTokens);
    Lexer lexer(tokenFactory);
    Parser parser;
    Interpreter interpreter;
    cout << "done!";
}
