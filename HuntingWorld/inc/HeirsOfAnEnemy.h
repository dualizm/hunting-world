#pragma once
#include "Enemy.h"
#include "Logic.h"
#include "lpct.hpp"

// Mysterious_Forest
    // common enemy

class Slime final : public Enemy
{
public:
    Slime(Hero& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Slime";
        this->lvl = generateLvl(h, 1);

        this->health = generateStat(h, 30);
        this->gold = 50;
        this->chance = generateStat(h, 90);
        this->damage = generateStat(h, 3);
        this->color = lpct::colors::green;
        this->sprite = sprites::Mysterious_Forest::slime;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.2f;
    }

};

class Goblin final : public Enemy
{
public:
    Goblin(Hero& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Goblin";
        this->lvl = generateLvl(h, 1);

        this->health = generateStat(h, 25);
        this->gold = 80;
        this->chance = generateStat(h, 100);
        this->damage = generateStat(h, 5);
        this->color = lpct::colors::green;
        this->sprite = sprites::Mysterious_Forest::goblin;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.2f;
    }
};


class FSlime final : public Enemy
{
public:
    FSlime(Hero& h) : Enemy("", 0, 0, 0)
    {
        this->name = "Fire slime";
        this->lvl = generateLvl(h, 2);

        this->health = generateStat(h, 50);
        this->gold = 200;
        this->chance = generateStat(h, 80);
        this->damage = generateStat(h, 7);
        this->color = lpct::colors::bright_red;
        this->sprite = sprites::Mysterious_Forest::fire_slime;
    }

    lpct::colors getColor() override
    {
        return color;
    }

	float getExp() override
	{
        return 0.3f;
	}
};

    // boss enemy

class SlimeBoss final : public Enemy
{
public:
    SlimeBoss(Hero& h)  : Enemy("", 0, 0, 0)
	{
        this->name = "Big slime";
        this->lvl = generateLvl(h, 5);

        this->health = generateStat(h, 100);
        this->gold = 400;
        this->chance = generateStat(h, 90);
        this->damage = generateStat(h, 6);
        this->color = lpct::colors::magenta;
        this->sprite = sprites::Mysterious_Forest::bigSlime;
	}

    lpct::colors getColor() override
    {
        return color;
    }

	float getExp() override
	{
		return 0.5f;
	}
};

    // uncommon enemy

class RSlimeBoss final : public Enemy
{
public:
    RSlimeBoss(Hero& h)  : Enemy("", 0, 0, 0)
    {
        this->name = "Big slime";
        this->lvl = generateLvl(h, 5);

        this->health = generateStat(h, 400);
        this->gold = 500;
        this->chance = generateStat(h, 100);
        this->damage = 1;
        this->color = lpct::colors::cyan;
        this->sprite = sprites::Mysterious_Forest::rare_bigSlime;
    }

    lpct::colors getColor() override
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

class Ghost final : public Enemy
{
public:
    Ghost(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "Ghost";
        this->lvl = generateLvl(h, 6);

        this->health = generateStat(h, 150);
        this->gold = 500;
        this->chance = generateStat(h, 100);
        this->damage = generateStat(h, 8);
        this->color = lpct::colors::bright_white;
        this->sprite = sprites::Old_Castle::ghost;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.2f;
    }
};

class Skeleton final : public Enemy
{
public:
    Skeleton(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "Skeleton";
        this->lvl = generateLvl(h, 7);

        this->health = generateStat(h, 100);
        this->gold = 670;
        this->chance = generateStat(h, 80);
        this->damage = generateStat(h, 10);
        this->color = lpct::colors::white;
        this->sprite = sprites::Old_Castle::skeleton;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 0.5f;
    }
};

    // boss enemy

class Knight final : public Enemy
{
public:
    Knight(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "Knight";
        this->lvl = generateLvl(h, 15);

        this->health = generateStat(h, 150);
        this->gold = 1287;
        this->chance = generateStat(h, 78);
        this->damage = generateStat(h, 14);
        this->color = lpct::colors::bright_white;
        this->sprite = sprites::Old_Castle::knight;
    }

    lpct::colors getColor() override
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

class StoneGolem final : public Enemy
{
public:
    StoneGolem(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "StoneGolem";
        this->lvl = generateLvl(h, 20);

        this->health = generateStat(h, 400);
        this->gold = 1500;
        this->chance = generateStat(h, 78);
        this->damage = generateStat(h, 17);
        this->color = lpct::colors::bright_white;
        this->sprite = sprites::Sacred_mountains::stone_golem;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 1.0f;
    }
};

class Angel final : public Enemy
{
public:
    Angel(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "Angel";
        this->lvl = generateLvl(h, 25);

        this->health = generateStat(h, 450);
        this->gold = 1600;
        this->chance = generateStat(h, 88);
        this->damage = generateStat(h, 13);
        this->color = lpct::colors::bright_yellow;
        this->sprite = sprites::Sacred_mountains::angel;
    }

    lpct::colors getColor() override
    {
        return color;
    }

    float getExp() override
    {
        return 1.0f;
    }
};

    // boss enemy

class FireSpirit final : public Enemy
{
public:
    FireSpirit(Hero& h) : Enemy("",0, 0, 0)
    {
        this->name = "FireSpirit";
        this->lvl = generateLvl(h, 30);

        this->health = generateStat(h, 300);
        this->gold = 3000;
        this->chance = generateStat(h, 78);
        this->damage = generateStat(h, 15);
        this->color = lpct::colors::red;
        this->sprite = sprites::Sacred_mountains::fire_spirit;
    }

    lpct::colors getColor() override
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

class GreatDragon final : public Enemy
{
public:
    GreatDragon(Hero& h) : Enemy("", 0, 0, 0)
    {
        this->name = "GreatDragon";
        this->lvl = generateLvl(h, 100);

        this->health = generateStat(h, 600);
        this->gold = 0;
        this->chance = generateStat(h, 80);
        this->damage = generateStat(h, 20);
        this->color = lpct::colors::yellow;
        this->sprite = sprites::Cave_of_time::great_dragon;
    }

    lpct::colors getColor() override
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
