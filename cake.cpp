#include "HeirsOfAnItem.h"

void Cake::use(Hero& hero)
{
    hero.addHealth(666);
}

std::string Cake::getName()
{
    return name;
}

int Cake::getPrice()
{
    return price;
}

std::string Cake::info()
{
    return "It's a lie!";
}
