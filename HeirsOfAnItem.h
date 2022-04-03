#pragma once
#include "ItemClass.h"
#include <list>

class BottleHealth final : public Item
{
private:
	int health;

public:
	BottleHealth()
	{
		this->name = "Potion of Healing";
        this->price = 300;
        this->health = 60;
	}

    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

    ~BottleHealth() = default;

};

class MedicinalHerb final : public Item
{
private:
	int health;

public:

	MedicinalHerb()
	{
		this->name = "Medicative herb";
		this->price = 125;
        this->health = 40;
	}


    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

    ~MedicinalHerb() = default;

};

class HealthScroll final : public Item
{
private:
    int health;

public:

    HealthScroll()
    {
        this->name = "HealthScroll";
        this->price = 650;
        this->health = 125;
    }


    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

    ~HealthScroll() = default;
};

class Cake final : public Item
{
public:
    Cake()
    {
        this->name = "Cake";
        this->price = 1000;
    }


    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

    ~Cake() = default;
};


#if 0
class TeleportScroll : public Item
{
	void Use(Hero& hero) override {}
	void Info() override
	{
		system("cls");
		FootnoteB();
		std::cout << "This Scroll of Teleportation will teleport you out of battle with a 100% chance.";
		DSTgo();
	}

};

#endif
