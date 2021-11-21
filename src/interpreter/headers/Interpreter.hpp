/*
Author: R. Baltrusch
*/

#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <stack>
#include <string>
#include <vector>
#include <memory>

#include "Value.hpp"
#include "Token.hpp"

class Interpreter
{

    std::stack<std::stack<std::shared_ptr<Value>>> stacks;
    std::vector<std::map<std::string, std::shared_ptr<Value>>> variables;

public:
    Interpreter();
    void interpret(Token &token);
    void addStack(void);
    void removeStack(void);
    std::shared_ptr<Value> stackPop(void);
    void stackAppend(std::shared_ptr<Value> value);
    bool checkVariable(std::string &name);
    std::shared_ptr<Value> getVariable(std::string &name);
    void setVariable(std::string &name, std::shared_ptr<Value> value);
};

#endif
