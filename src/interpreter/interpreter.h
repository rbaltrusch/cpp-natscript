/*
Author: R. Baltrusch
*/

#pragma once
#ifndef INTERPRETER_H
#define INTERPRETER_H

#include <map>
#include <string>
#include <vector>

#include "value.h"
#include "token.h"

class Interpreter
{

    std::vector<std::vector<Value>> stacks;
    std::vector<std::map<std::string, Variable>> variables;

public:
    Interpreter();
    void interpret(Token);
    void addStack();
    void removeStack();
    void stackPop();
    void stackAppend();
    bool checkVariable(std::string);
    Variable getVariable(std::string);
    void setVariable(std::string, Value);
};

#endif
