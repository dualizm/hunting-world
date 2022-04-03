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
