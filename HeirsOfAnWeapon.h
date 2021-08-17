#pragma once
#include "Weapon.h"
#include "Hero.h"


class Fists : public Weapon
{
public:
	Fists() : Weapon(10, "Fists", 100.0f, 0) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.GetHealth() - (5 + hero.GetLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(5 + hero.GetLvl()) + " your health";
    }
};

class Sword : public Weapon
{
public:
	Sword() : Weapon(25, "Sword", 70.0f, 800) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.GetHealth() - (5 + hero.GetLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(5 + hero.GetLvl()) + " your health";
    }
};

class Gun : public Weapon
{
public:
	Gun() : Weapon(20, "Gun", 80.0f, 800) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.GetHealth() - (5 + hero.GetLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(5 + hero.GetLvl()) + " your health";
    }

};

class BigSword : public Weapon
{
public:
	BigSword() : Weapon(70, "BigSword", 60.0f, 1600) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() + 5;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.GetHealth() - (hero.GetLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(hero.GetLvl()) + " your health";
    }

};

class Crossbow : public Weapon
{
public:
	Crossbow() : Weapon(55, "Crossbow", 90.0f, 2000) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 0.5;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.GetHealth() + (10 + hero.GetLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "+" + std::to_string(10 + hero.GetLvl()) + " your health";
    }

};
