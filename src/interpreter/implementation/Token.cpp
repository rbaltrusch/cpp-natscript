/*
Author: R. Baltrusch
*/

#include <any>
#include <iostream>

#include "../headers/Token.hpp"

Token::Token(std::any value, int line)
    : value{value},
      line{line},
      run_order{0}
      {
          for (auto expectedToken : this->expectedTokens)
          {
              this->expectedTokensCopy.push_back(expectedToken);
          }
      };

void Token::print(void)
{
    std::cout << this->line;
    std::cout << std::any_cast<int>(this->value);
}
