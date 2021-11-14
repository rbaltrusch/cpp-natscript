/*
Author: R. Baltrusch
*/

#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <string>
#include <vector>

#include "Value.hpp"
#include "Token.hpp"

class Interpreter
{

    std::vector<std::vector<Value>> stacks;
    std::vector<std::map<std::string, Variable>> variables;

public:
    Interpreter();
    void interpret(Token *token);
    void addStack(void);
    void removeStack(void);
    void stackPop(void);
    void stackAppend(void);
    bool checkVariable(std::string &name);
    Variable getVariable(std::string &name);
    void setVariable(std::string &name, Value value);
};

#endif
