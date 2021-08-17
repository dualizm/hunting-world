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
		this->price = 400;
		this->health = 50;
	}

	void Use(Hero& hero) override;

	std::string GetName() override;

	int GetPrice() override;

	std::string Info() override;

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
		this->health = 15;
	}


	void Use(Hero& hero) override;

	std::string GetName() override;

	int GetPrice() override;

	std::string Info() override;

	~MedicinalHerb() override {}

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
