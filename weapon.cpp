#include "Weapon.h"

std::string Weapon::getName() const
{
	return name; 
}

float Weapon::getChance() const
{
	return chance;
}

int Weapon::getDamage() const 
{
	return damage;
}

int  Weapon::getPrice() const 
{
	return price; 
}

int Weapon::getDamageSpecialAttack()
{
	return this->getDamage() * 2;
}

void Weapon::resultSpecialAttack(Person& hero)
{
	hero.SetHealth(hero.GetHealth() - (5 + hero.GetLvl()));
}
