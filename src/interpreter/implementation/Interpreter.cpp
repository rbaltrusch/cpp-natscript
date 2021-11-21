/*
Author: R. Baltrusch
*/

#include <stack>
#include <memory>
#include <utility>
#include <stdexcept>

#include "../headers/Interpreter.hpp"

Interpreter::Interpreter() : stacks(), variables(){};

void Interpreter::interpret(Token &token)
{

};

void Interpreter::addStack(void)
{
    std::stack<std::shared_ptr<Value>> newStack;
    this->stacks.push(newStack);

    std::map<std::string, std::shared_ptr<Value>> variableScope;
    this->variables.push_back(variableScope);
};

void Interpreter::removeStack(void)
{
    this->stacks.pop();
    this->variables.pop_back();
};

std::shared_ptr<Value> Interpreter::stackPop(void)
{
    std::shared_ptr<Value> value = this->stacks.top().top();
    this->stacks.top().pop();
    return value;
};

void Interpreter::stackAppend(std::shared_ptr<Value> value)
{
    this->stacks.top().push(std::shared_ptr<Value>(value));
};

bool Interpreter::checkVariable(std::string &name)
{
    auto iterator = this->variables.back().find(name);
    return (iterator != this->variables.back().end());
};

std::shared_ptr<Value> Interpreter::getVariable(std::string &name)
{
    auto iterator = this->variables.back().find(name);
    if (iterator == this->variables.back().end())
    {
        throw std::invalid_argument("UndefinedVariableException: Tried to access undefined variable!");
    }
    return iterator->second;
};

void Interpreter::setVariable(std::string &name, std::shared_ptr<Value> variable)
{
    this->variables.back().insert(std::pair<std::string, std::shared_ptr<Value>>(name, variable));
};
