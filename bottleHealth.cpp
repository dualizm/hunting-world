#include "HeirsOfAnItem.h"

void BottleHealth::Use(Hero& hero)
{
	if (hero.GetHealth() < 100)
	{
		hero.Health(30);
	}
}

std::string BottleHealth::GetName()
{
	return name;
}

int BottleHealth::GetPrice()
{
	return price;
}

std::string BottleHealth::Info()
{
	return std::to_string(health);
}