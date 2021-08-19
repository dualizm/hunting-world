#pragma once
#include "Enemy.h"
#include "Logic.h"

class Slime : public Enemy
{
public:
    Slime(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Slime";
        this->lvl = generateLvl(h, 1);

        this->health = generateStat(30);
        this->gold = generateStat(40);
        this->chance = generateStat(90);
        this->damage = generateStat(3);
        this->color = ConsoleColor::LightGreen;
        this->sprite = sprites::Mysterious_Forest::slime;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.2f;
    }

};


class FSlime : public Enemy
{
public:
    FSlime(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Fire slime";
        this->lvl = generateLvl(h, 2);

        this->health = generateStat(40);
        this->gold = generateStat(50);
        this->chance = generateStat(80);
        this->damage = generateStat(5);
        this->color = ConsoleColor::LightRed;
        this->sprite = sprites::Mysterious_Forest::fire_slime;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

	float getExp() override
	{
        return 0.3f;
	}
};

class SlimeBoss : public Enemy
{
public:
    SlimeBoss(Person& h)  : Enemy("", 0, 0, 0)
	{
        this->name = "Big slime";
        this->lvl = generateLvl(h, 5);

        this->health = generateStat(100);
        this->gold = generateStat(150);
        this->chance = generateStat(90);
        this->damage = generateStat(15);
        this->color = ConsoleColor::Magenta;
        this->sprite = sprites::Mysterious_Forest::bigSlime;
	}

    ConsoleColor getColor() override
    {
        return color;
    }

	float getExp() override
	{
		return 0.5f;
	}
};

class RSlimeBoss : public Enemy
{
public:
    RSlimeBoss(Person& h)  : Enemy("", 0, 0, 0)
    {
        this->name = "Big slime";
        this->lvl = generateLvl(h, 5);

        this->health = generateStat(500);
        this->gold = generateStat(150);
        this->chance = generateStat(100);
        this->damage = generateStat(1);
        this->color = ConsoleColor::Cyan;
        this->sprite = sprites::Mysterious_Forest::rare_bigSlime;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.5f;
    }
};

class Goblin : public Enemy
{
public:
    Goblin(Person& h) : Enemy("", 0, 0, 0)
	{
        this->name = "Goblin";
        this->lvl = generateLvl(h, 1);

        this->health = generateStat(25);
        this->gold = generateStat(50);
        this->chance = generateStat(100);
        this->damage = generateStat(8);
        this->color = ConsoleColor::Green;
        this->sprite = sprites::Mysterious_Forest::goblin;
	}

    ConsoleColor getColor() override
    {
        return color;
    }

	float getExp() override
	{
		return 0.2f;
	}
};

class GreatDragon : public Enemy
{
public:
    GreatDragon(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "GreatDragon";
        this->lvl = generateLvl(h, 45);

        this->health = 1000;
        this->gold = generateStat(5000);
        this->chance = 80;
        this->damage = 20;
        this->color = ConsoleColor::Yellow;
        this->sprite = sprites::Cave_of_time::great_dragon;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.2f;
    }


    ~GreatDragon()
    {
        WinThisGame();
    }

};
