#include "HeirsOfAnItem.h"

void MedicinalHerb::use(Hero& hero)
{
    hero.addHealth(health);
}

std::string MedicinalHerb::getName()
{
	return name;
}

int MedicinalHerb::getPrice()
{
	return price;
}

std::string MedicinalHerb::info()
{
    return "+" + std::to_string(health);
}
