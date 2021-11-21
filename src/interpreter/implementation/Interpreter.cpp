/*
Author: R. Baltrusch
*/

#include <stack>
#include <utility>
#include <stdexcept>

#include "../headers/Interpreter.hpp"

Interpreter::Interpreter() : stacks(), variables(){};

void Interpreter::interpret(Token &token)
{

};

void Interpreter::addStack(void)
{
    std::stack<Value> newStack;
    this->stacks.push(newStack);

    std::map<std::string, Variable> variableScope;
    this->variables.push_back(variableScope);
};

void Interpreter::removeStack(void)
{
    this->stacks.pop();
    this->variables.pop_back();
};

Value Interpreter::stackPop(void)
{
    Value value = this->stacks.top().top();
    this->stacks.top().pop();
    return value;
};

void Interpreter::stackAppend(Value &value)
{
    this->stacks.top().push(value);
};

bool Interpreter::checkVariable(std::string &name)
{
    auto iterator = this->variables.back().find(name);
    return (iterator != this->variables.back().end());
};

Variable Interpreter::getVariable(std::string &name)
{
    auto iterator = this->variables.back().find(name);
    if (iterator == this->variables.back().end())
    {
        throw std::invalid_argument("UndefinedVariableException: Tried to access undefined variable!");
    }
    return iterator->second;
};

void Interpreter::setVariable(std::string &name, Variable &value)
{
    this->variables.back().insert(std::pair<std::string, Variable>(name, value));
};
