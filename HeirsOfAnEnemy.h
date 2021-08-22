#pragma once
#include "Enemy.h"
#include "Logic.h"

// Mysterious_Forest
    // common enemy

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

class Goblin : public Enemy
{
public:
    Goblin(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Goblin";
        this->lvl = generateLvl(h, 1);

        this->health = generateStat(25);
        this->gold = generateStat(65);
        this->chance = generateStat(100);
        this->damage = generateStat(5);
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


class FSlime : public Enemy
{
public:
    FSlime(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Fire slime";
        this->lvl = generateLvl(h, 2);

        this->health = generateStat(35);
        this->gold = generateStat(100);
        this->chance = generateStat(80);
        this->damage = generateStat(7);
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

    // boss enemy

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
        this->damage = generateStat(6);
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

    // uncommon enemy

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

// Old_Castle
    // common enemy

class Ghost : public Enemy
{
public:
    Ghost(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "Ghost";
        this->lvl = generateLvl(h, 6);

        this->health = generateStat(150);
        this->gold = generateStat(200);
        this->chance = generateStat(100);
        this->damage = generateStat(5);
        this->color = ConsoleColor::DarkGray;
        this->sprite = sprites::Old_Castle::ghost;
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

class Skeleton : public Enemy
{
public:
    Skeleton(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "Skeleton";
        this->lvl = generateLvl(h, 7);

        this->health = generateStat(100);
        this->gold = generateStat(250);
        this->chance = generateStat(80);
        this->damage = generateStat(14);
        this->color = ConsoleColor::White;
        this->sprite = sprites::Old_Castle::skeleton;
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

    // boss enemy

class Knight : public Enemy
{
public:
    Knight(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "Knight";
        this->lvl = generateLvl(h, 10);

        this->health = generateStat(300);
        this->gold = generateStat(300);
        this->chance = generateStat(78);
        this->damage = generateStat(7);
        this->color = ConsoleColor::LightGray;
        this->sprite = sprites::Old_Castle::knight;
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

// Sacred mountains
    // common enemy

class StoneGolem : public Enemy
{
public:
    StoneGolem(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "StoneGolem";
        this->lvl = generateLvl(h, 15);

        this->health = generateStat(1);
        this->gold = generateStat(300);
        this->chance = generateStat(78);
        this->damage = generateStat(10);
        this->color = ConsoleColor::LightGray;
        this->sprite = sprites::Sacred_mountains::stone_golem;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 1.0f;
    }
};

class Angel : public Enemy
{
public:
    Angel(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "Angel";
        this->lvl = generateLvl(h, 15);

        this->health = generateStat(1);
        this->gold = generateStat(300);
        this->chance = generateStat(78);
        this->damage = generateStat(10);
        this->color = ConsoleColor::Brown;
        this->sprite = sprites::Sacred_mountains::angel;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 1.0f;
    }
};

class FireSpirit : public Enemy
{
public:
    FireSpirit(Person& h) : Enemy("",0, 0, 0)
    {
        this->name = "FireSpirit";
        this->lvl = generateLvl(h, 15);

        this->health = generateStat(1);
        this->gold = generateStat(300);
        this->chance = generateStat(78);
        this->damage = generateStat(10);
        this->color = ConsoleColor::LightRed;
        this->sprite = sprites::Sacred_mountains::fire_spirit;
    }

    ConsoleColor getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 1.0f;
    }
};

// Cave of time
    // legendary boss

class GreatDragon : public Enemy
{
public:
    GreatDragon(Person& h) : Enemy("", 0, 0, 0)
    {
        this->name = "GreatDragon";
        this->lvl = generateLvl(h, 100);

        this->health = generateStat(500);
        this->gold = 0;
        this->chance = generateStat(80);
        this->damage = generateStat(20);
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
