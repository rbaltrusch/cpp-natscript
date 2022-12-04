/*
Author: R. Baltrusch
*/

#include <stack>
#include <vector>
#include <deque>

#include "../headers/Token.hpp"
#include "../headers/Parser.hpp"

Parser::Parser() : tokenStack(){};

TokenVector Parser::parse(std::deque<std::shared_ptr<Token>> tokens)
{
    TokenVector parsedTokens;

    while (!tokens.empty())
    {
        auto poppedTokens = tokens[0]->popTokens(tokens);
        if (!poppedTokens.empty())
        {
            continue;
        }

        auto token = tokens[0];
        tokens.pop_front();
        if (this->tokenStack.empty())
        {
            tokenStack.push(token);
            continue;
        }

        if (!this->tokenStack.top()->getSatisfied() || this->tokenStack.top()->checkOptionalToken(*token))
        {
            this->tokenStack.top()->addToken(*token);
        }
        else
        {
            parsedTokens.push_back(this->tokenStack.top());
            this->tokenStack.pop();
        }
        this->tokenStack.push(token);

        while (this->tokenStack.top()->getFull())
        {
            auto token = this->tokenStack.top();
            this->tokenStack.pop();
            if (this->tokenStack.empty())
            {
                parsedTokens.push_back(token);
                break;
            }
        }
    }

    while (!this->tokenStack.empty())
    {
        auto token = this->tokenStack.top();
        this->tokenStack.pop();
        parsedTokens.push_back(token);
    }

    return parsedTokens;
};
