#include "HeirsOfAnItem.h"

void BottleHealth::use(Hero& hero)
{
    hero.addHealth(health);
}

std::string BottleHealth::getName()
{
	return name;
}

int BottleHealth::getPrice()
{
	return price;
}

std::string BottleHealth::info()
{
    return "+" + std::to_string(health);
}
