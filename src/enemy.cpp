#include "Enemy.h"
#include "lpct.hpp"
#include <iomanip>

void Enemy::attackHero(Person& hero)
{
	std::cout << " The enemy is attacking you!" << std::endl;

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chc = 0 + mersenne() % 100;

	if (chc > chance)
	{
        std::cout << " He missed! :)" << std::endl;
	}
	else
	{
        std::mt19937 randAttack(static_cast<unsigned int>(time(0)));
        int spEnemy = 0 + randAttack() % 100;
        if(spEnemy > 90)
        {
            std::cout << " He used a special attack!" << std::endl;
            std::cout << " He hit you at -" + std::to_string(damage * 2) + " health!" << std::endl;
            hero.SetHealth(hero.getHealth() - damage * 2);
        }
        else
        {
            std::cout << " He hit you at -" + std::to_string(damage) + " health!" << std::endl;
            hero.SetHealth(hero.getHealth() - damage);
        }
	}

}

void Enemy::showSprite()
{
	for (auto& str : sprite)
	{
    lpct::prcolorln(color, str);
	}
}

void Enemy::showStatus()
{

	std::cout << " Race: ";
  std::cout << std::setw(10) <<  lpct::get_colorstr<std::string>(color, std::move(name));

	std::cout << " | " << " Health: ";
  std::cout << std::setw(4) <<  lpct::get_colorstr<std::string>(lpct::colors::green, std::to_string(health));

	std::cout << " | " << " Level: ";
  std::cout << lpct::get_colorstr<std::string>(lpct::colors::yellow, std::to_string(getLvl()));

	std::cout << " | " << " Damage: ";
  std::cout << lpct::get_colorstr<std::string>(lpct::colors::red, std::to_string(damage));

	std::cout << " | " << " Reward: ";
  std::cout << lpct::get_colorstr<std::string>(lpct::colors::yellow, std::to_string(gold));

	std::cout << " | " << std::endl;

}

int Enemy::generateStat(Hero& h, int param)
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
    return static_cast<int>(
		param + mersenne() %
        static_cast<int>((param + ((float)param / 100) * (((lvl + 100) * (20 * h.getLvl()) / 2) ) ) / 4)) ;
}

float Enemy::generateLvl(Person& h, float param)
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

    return static_cast<int>(param) + mersenne() % h.getLvl();
}
