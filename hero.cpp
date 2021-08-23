#include "Hero.h"
#include "Color.h"
#include "Weapon.h"
#include <iomanip>
#include <memory>
#include <random>
#include "Enemy.h"

void Hero::upDay() { day++; }

void Hero::paymentTavern()
{
	gold -= 150 * day;
}

void Hero::buy(int price)
{
	gold -= price;
}

int Hero::getDay()
{ 
	return day;
}

int Hero::getMaxHealth()
{
    return (100 - 30) + ( 30 * getLvl());
}

void Hero::addGold(int newGold)
{ 
	gold += newGold;
}

void Hero::addHealth(int health)
{ 
	this->health += health;
}

int Hero::getAttack()
{ 
	return weapon->getDamage();
}

std::string Hero::getWeaponName()
{ 
	return weapon->getName();
}

int Hero::getWeaponAttack()
{
	return weapon->getDamage();
}

int Hero::getWeaponAttackS()
{
    return weapon->getDamageSpecialAttack();
}

size_t Hero::getMaxSizeInventory()
{
    return 6;
}

void Hero::lvlUp(float exp)
{
	lvl += exp; 
}

void Hero::swapWeapon(std::shared_ptr<Weapon> alt_w)
{
    std::swap(weapon, alt_w);
}

void Hero::showStatus()
{
	std::cout << " Name: ";
	SetColor(ConsoleColor::LightMagenta, ConsoleColor::Black);
	std::cout << std::setw(10) << name;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Health: ";
	SetColor(ConsoleColor::Green, ConsoleColor::Black);
    std::cout << std::setw(4) << getHealth();
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Level: ";
	SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
    std::cout << getLvl();
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Damage: ";
	SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
	std::cout << weapon->getDamage();
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << "   " << " Chance: ";
	SetColor(ConsoleColor::Cyan, ConsoleColor::Black);
	std::cout << weapon->getChance();
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << std::endl;

}

void Hero::attackEnemy(Hero& hero, Enemy* enemy, int damageIn)
{
    if (damageIn == weapon->getDamageSpecialAttack())
	{
        std::cout << " Special Attack Charge! " + weapon->getInfo(hero) << std::endl;
		weapon->resultSpecialAttack(hero);
        hero.resetSp = 3;
	}
	std::cout << " You attack the enemy!" << std::endl;

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chc = 0 + mersenne() % 100;

	if (chc > weapon->getChance())
	{
        std::cout << " You missed! :(" << std::endl;
	}
	else
	{
        std::cout << " You hit him at -" + std::to_string(damageIn) + " health!" << std::endl;
        enemy->SetHealth(enemy->getHealth() - damageIn);
	}

    hero.resetSp == 0 ? hero.resetSp : hero.resetSp--;
}

void Hero::debugcheatMode(int& health, int& gold, float& lvl, int& day)
{
	int chek;
    std::cout << " Enter game mode (0 - gamemod, 1 - godmode, 2 - auto godmode): ";
    chek = checkInput();
	if (chek == 0)
		return;
	else if (chek == 1)
	{
        std::cout << "Enter health: ";
        std::cin >> health;
        std::cout << "Enter gold: ";
        std::cin >> gold;
        std::cout << "Enter lvl: ";
        std::cin >> lvl;
        std::cout << "Enter day: ";
        std::cin >> day;
	}
	else if (chek == 2)
	{
		health = 9999;
		gold = 9999;
		lvl = 1.0f;
		day = 1;
	}
}
