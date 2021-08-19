#include "Enemy.h"
#include "Color.h"
#include <iomanip>

void Enemy::AttackHero(Person& hero)
{
	std::cout << " The enemy is attacking you!" << std::endl;

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chc = 0 + mersenne() % 100;

	if (chc > chance)
	{
		std::cout << " He missed!" << std::endl;
	}
	else
	{
        std::mt19937 randAttack(static_cast<unsigned int>(time(0)));
        int spEnemy = 0 + randAttack() % 100;
        if(spEnemy > 80)
        {
            std::cout << " He used a special attack!" << std::endl;
            std::cout << " He hit you at -" + std::to_string(damage * 2) + " health!" << std::endl;
            hero.SetHealth(hero.GetHealth() - damage * 2);
        }
        else
        {
            std::cout << " He hit you at -" + std::to_string(damage) + " health!" << std::endl;
            hero.SetHealth(hero.GetHealth() - damage);
        }
	}

}

void Enemy::showSprite()
{
	for (auto& str : sprite)
	{
		std::cout << str << std::endl;
	}
}

void Enemy::showStatus()
{

	std::cout << " Race: ";
    SetColor(color, ConsoleColor::Black);
	std::cout << std::setw(10) << name;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Health: ";
	SetColor(ConsoleColor::Green, ConsoleColor::Black);
	std::cout << std::setw(4) << health;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Level: ";
	SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
	std::cout << GetLvl();
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Damage: ";
	SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
	std::cout << damage;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Reward: ";
	SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
	std::cout << gold;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << std::endl;

}

int Enemy::generateStat(int param)
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	return static_cast<int>(
		param + mersenne() %
        static_cast<int>((param + (param / 100) * (lvl * 20))));
}

float Enemy::generateLvl(Person& h, float param)
{
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

	return static_cast<int>(param) + mersenne() % h.GetLvl();
}
