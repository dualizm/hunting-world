#pragma once
#include "Person.h"
#include "Hero.h"
#include "Sprites.h"
#include "Sms.h"
#include "Color.h"
#include <vector>
#include <random>
class Person;
class Hero;


class Enemy : public Person
{
protected:
    int chance;
	int damage;
    ConsoleColor color;
    std::vector<std::string> sprite;

    int generateStat(int param);

    float generateLvl(Person& h, float param);

public:

    Enemy(std::string name, int health, int gold, float lvl)
        : Person(name, health, gold, lvl) {}

public:

    void attackHero(Person& hero);

	void showSprite();

	void showStatus();

    virtual ConsoleColor getColor() = 0;

    virtual float getExp() = 0;

	virtual ~Enemy() {}
};
