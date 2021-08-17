#include "HeirsOfAnItem.h"

void MedicinalHerb::Use(Hero& hero)
{
	if (hero.GetHealth() < 100)
		hero.Health(15);
}

std::string MedicinalHerb::GetName()
{
	return name;
}

int MedicinalHerb::GetPrice()
{
	return price;
}

std::string MedicinalHerb::Info()
{
	return std::to_string(health);
}