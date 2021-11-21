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

#include "Value.hpp"
#include "Token.hpp"

class Interpreter
{

    std::stack<std::stack<Value>> stacks;
    std::vector<std::map<std::string, Variable>> variables;

public:
    Interpreter();
    void interpret(Token &token);
    void addStack(void);
    void removeStack(void);
    Value stackPop(void);
    void stackAppend(Value &value);
    bool checkVariable(std::string &name);
    Variable getVariable(std::string &name);
    void setVariable(std::string &name, Variable &value);
};

#endif
