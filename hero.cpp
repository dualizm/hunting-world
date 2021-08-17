#include "Hero.h"
#include "Color.h"
#include <iomanip>
#include <memory>

void Hero::Upday() { day++; }

void Hero::PaymentTavern()
{
	gold -= 150 * day;
}

void Hero::Buy(int price)
{
	gold -= price;
}

int Hero::GetDay()
{ 
	return day;
}

void Hero::AddGold(int newGold) 
{ 
	gold += newGold;
}

void Hero::Health(int health)
{ 
	this->health += health;
}

int Hero::GetAttack() 
{ 
	return weapon->getDamage();
}

std::string Hero::GetWeaponName() 
{ 
	return weapon->getName();
}

int Hero::GetWeaponAttack() 
{
	return weapon->getDamage();
}

int Hero::GetWeaponAttackS()
{
    return weapon->getDamageSpecialAttack();
}

void Hero::LvlUp(float exp)
{
	lvl += exp; 
}

void Hero::SwapWeapon(std::shared_ptr<Weapon> alt_w)
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
	std::cout << std::setw(4) << health;
	SetColor(ConsoleColor::White, ConsoleColor::Black);

	std::cout << " | " << " Level: ";
	SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
	std::cout << GetLvl();
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

void Hero::AttackEnemy(Hero& hero, Enemy* enemy, int damageInt)
{
    if (damageInt == weapon->getDamageSpecialAttack())
	{
        std::cout << " Special Attack Charge! " + weapon->getInfo(hero) << std::endl;
		weapon->resultSpecialAttack(hero);
	}
	std::cout << " You attack the enemy!" << std::endl;

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chc = 0 + mersenne() % 100;

	if (chc > weapon->getChance())
	{
		std::cout << " You missed! =(" << std::endl;
	}
	else
	{
		std::cout << " You hit him at -" + std::to_string(damageInt) + " health!" << std::endl;
		enemy->SetHealth(enemy->GetHealth() - damageInt);
	}
}

void Hero::DebugcheatMode(int& health, int& gold, float& lvl, int& day)
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
