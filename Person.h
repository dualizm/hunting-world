#pragma once
#include <string>
#include "SupportFunctions.h"

class Person
{
protected:
    int health;	   // HEALTH
    int gold;		   // GOLD
    float lvl;		   // LEVEL
    std::string name; // NAME

public:

	Person(std::string name, int health, int gold, float lvl)
		: health(health), gold(gold), lvl(lvl), name(name) {}

    std::string getName() { return name; }
    int getHealth() { return health; }
    int getGold() { return gold; }
    int getLvl() { return static_cast<int>(lvl); }
	void SetHealth(int health) { this->health = health; }

	virtual ~Person() {}
};
