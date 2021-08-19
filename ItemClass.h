#pragma once
#include <string>
#include "ModulePerson.h"
class Hero;

class Item
{
protected:
	std::string name;
	int price;

public:
    virtual void use(Hero&) = 0;

    virtual std::string getName() = 0;

    virtual int getPrice() = 0;

    virtual std::string info() = 0;

	virtual ~Item() {};
};
