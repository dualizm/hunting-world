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
    std::vector<std::string> sprite;
    int chance;
	int damage;
    ConsoleColor color;

public:

    Enemy(std::string name, int health, int gold, float lvl, int chance, int damage, ConsoleColor color, std::vector<std::string> sprite)
        : Person(name, health, gold, lvl), sprite(sprite), chance(chance), damage(damage), color(color) {}

public:

	void AttackHero(Person& hero);

	void showSprite();

	void showStatus();

	int generateStat(int param);

	float generateLvl(Person& h, float param);

    virtual ConsoleColor getColor() = 0;

	virtual float GetExp() = 0;

	virtual ~Enemy() {}
};
