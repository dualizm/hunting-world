#pragma once
#include <string>

class Person;
class Hero;

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

    virtual int getDamageSpecialAttack() = 0;

    virtual void resultSpecialAttack(Person& hero) = 0;

    virtual std::string getInfo(Hero& hero) = 0;

	virtual ~Weapon() {}
};
