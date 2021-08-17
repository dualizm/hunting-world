#pragma once
#include "Enemy.h"

class FSlime : public Enemy
{
public:
    FSlime(Person& h) : Enemy
    (	"Fire slime",
        generateLvl(h, 1), //lvl
		generateStat(40), //health
        generateStat(50), //gold
		generateStat(80), //chance
		generateStat(5), //damage
        ConsoleColor::LightRed,
        sprite_fire_slime)
	{

	}

    ConsoleColor getColor() override
    {
        return color;
    }

	float GetExp() override
	{
		return 0.2f;
	}
};

class SlimeBoss : public Enemy
{
public:
	SlimeBoss(Person& h) : Enemy
	(	"Big slime",
        generateLvl(h, 5), //lvl
		generateStat(100), //health
		generateStat(150), //gold
		generateStat(90), //chance
		generateStat(15), //damage
        ConsoleColor::Magenta,
		sprite_bigSlime)
	{

	}

    ConsoleColor getColor() override
    {
        return color;
    }

	float GetExp() override
	{
		return 0.5f;
	}
};

class Goblin : public Enemy
{
public:
	Goblin(Person& h) : Enemy
	(	"Goblin",
        generateLvl(h, 1), //lvl
		generateStat(25), //health
		generateStat(50), //gold
		generateStat(100), //chance
		generateStat(8), //damage
        ConsoleColor::Green,
		sprite_goblin)
	{

	}

    ConsoleColor getColor() override
    {
        return color;
    }

	float GetExp() override
	{
		return 0.2f;
	}
};
