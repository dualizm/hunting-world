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
	virtual void Use(Hero&) = 0;

	virtual std::string GetName() = 0;

	virtual int GetPrice() = 0;

	virtual std::string Info() = 0;

	virtual ~Item() {};
};