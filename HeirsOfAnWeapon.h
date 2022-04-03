#pragma once
#include "Weapon.h"
#include "Hero.h"


class Fists final : public Weapon
{
public:
	Fists() : Weapon(10, "Fists", 100.0f, 0) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth());
    }

    std::string getInfo(Hero& hero) override
    {
        hero.SetHealth(hero.getHealth()); // plug
        return " ";
    }

    std::string shopInfo() override
    {
        return " *2 dmg";
    }
};

class Sword final : public Weapon
{
public:
    Sword() : Weapon(20, "Sword", 85.0f, 800) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth());
    }

    std::string getInfo(Hero& hero) override
    {
        hero.SetHealth(hero.getHealth()); // plug
        return " ";
    }

    std::string shopInfo() override
    {
        return " *2 dmg";
    }
};

class Gun final : public Weapon
{
public:
    Gun() : Weapon(25, "Gun", 75.0f, 800) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth());
    }

    std::string getInfo(Hero& hero) override
    {
        hero.SetHealth(hero.getHealth()); // plug
        return " ";
    }

    std::string shopInfo() override
    {
        return " *2 dmg";
    }

};

class Cursedbow final : public Weapon
{
public:
    Cursedbow() : Weapon(70, "Cursedbow", 65.0f, 2500) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth() - (10 + hero.getLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(10 + hero.getLvl()) + " your health";
    }

    std::string shopInfo() override
    {
        return " *2 dmg";
    }

};

class StaffHealth final : public Weapon
{
public:
    StaffHealth() : Weapon(55, "Staff", 90.0f, 1500) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 0.5;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth() + (30 + hero.getLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "+" + std::to_string(30 + hero.getLvl()) + " your health";
    }

    std::string shopInfo() override
    {
        return " *0.5 dmg";
    }

};

class SnakeBlade final : public Weapon
{
public:
    SnakeBlade() : Weapon(100, "SnakeBlade", 80.0f, 5000) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 3;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth() - (50 + hero.getLvl()));
    }

    std::string getInfo(Hero& hero) override
    {
        return "-" + std::to_string(50 + hero.getLvl()) + " your health";
    }

    std::string shopInfo() override
    {
        return " *3 dmg";
    }
};

class DragonSlayer final : public Weapon
{
public:
    DragonSlayer() : Weapon(200, "DragonSlayer", 80.0f, 8000) {}

    int getDamageSpecialAttack() override
    {
        return this->getDamage() * 2;
    }

    void resultSpecialAttack(Person& hero) override
    {
        hero.SetHealth(hero.getHealth());
    }

    std::string getInfo(Hero& hero) override
    {
        hero.SetHealth(hero.getHealth()); // plug
        return "";
    }

    std::string shopInfo() override
    {
        return " *2 dmg";
    }
};
