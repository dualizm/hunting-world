#include "HeirsOfAnItem.h"
#include "Sms.h"

void Cake::use(Hero& hero)
{
    Sms("It's a lie! add +" + std::to_string(hero.getHealth() + 50));
    hero.addHealth(hero.getHealth() + 50);
    DSTgo();
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
    return " add +500 hp";
}
