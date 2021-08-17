#pragma once
#include <string>
#include "Person.h"

class Weapon
{

protected:
	int damage;
	float chance;
	std::string name;
	int price;

public:

	Weapon(int damage, std::string name, float chance, int price)
	{
		this->damage = damage;
		this->name = name;
		this->chance = chance;
		this->price = price;
	}

	std::string getName() const;
	float getChance() const;
	int getDamage() const;
	int getPrice() const;

    int getDamageSpecialAttack();

	void resultSpecialAttack(Person& hero);

	virtual ~Weapon() {}
};
