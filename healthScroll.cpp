#include "HeirsOfAnItem.h"

void HealthScroll::use(Hero& hero)
{
    hero.addHealth(health);
}

std::string HealthScroll::getName()
{
    return name;
}

int HealthScroll::getPrice()
{
    return price;
}

std::string HealthScroll::info()
{
    return "+" + std::to_string(health);
}
