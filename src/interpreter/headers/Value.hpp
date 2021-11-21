/*
Author: R. Baltrusch
*/

#pragma once
#ifndef VALUE_H
#define VALUE_H

#include <any>
#include <string>
#include <stdexcept>

class Value
{
public:
    std::any value;

    Value(std::any value)
        : value{value} {};

    virtual std::string getName(void)
    {
        throw std::runtime_error("Not implemented.");
    };
};

class Variable : public Value
{
    std::string name;

public:
    Variable(const std::string &name)
        : Value(0),
          name{name} {};

    std::string getName(void)
    {
        return this->name;
    };
};

#endif
