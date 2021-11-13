/*
Author: R. Baltrusch
*/

#pragma once
#ifndef VALUE_H
#define VALUE_H

class Value
{
};

class Integer : public Value
{

    int value;

public:
    Integer(int);
};

class Variable
{

public:
    Variable(std::string);
    Value value;
    std::string name;
};

#endif
