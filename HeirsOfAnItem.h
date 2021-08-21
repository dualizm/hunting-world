#pragma once
#include "ItemClass.h"
#include <list>

class BottleHealth : public Item
{
private:
	int health;

public:
	BottleHealth()
	{
		this->name = "Potion of Healing";
        this->price = 300;
		this->health = 50;
	}

    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

	~BottleHealth() override {}

};

class MedicinalHerb : public Item
{
private:
	int health;

public:

	MedicinalHerb()
	{
		this->name = "Medicative herb";
		this->price = 125;
        this->health = 30;
	}


    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

	~MedicinalHerb() override {}

};

class HealthScroll : public Item
{
private:
    int health;

public:

    HealthScroll()
    {
        this->name = "HealthScroll";
        this->price = 650;
        this->health = 100;
    }


    void use(Hero& hero) override;

    std::string getName() override;

    int getPrice() override;

    std::string info() override;

    ~HealthScroll() override {}
};

class Cake : public Item
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

    ~Cake() override {}
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
