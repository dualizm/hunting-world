#pragma once
#include <list>
#include <memory>

#include "ItemClass.h"
#include "Weapon.h"
#include "Enemy.h"
#include "Sms.h"
class Item;
class Enemy;
class Weapon;

using list_item = std::list<std::shared_ptr<Item>>;

class Hero : public Person
{

private:
    int day;  // GAME DAY
    std::shared_ptr<Weapon> weapon; // WEAPON

public:
    const short sizeInv = 6;

    list_item inventory; // INVENTORY

    Hero(std::string name, int health, int gold, float lvl, int day, std::shared_ptr<Weapon> weapon)
		: Person(name, health, gold, lvl), day(day), weapon(weapon) {}
	
	void Upday();
	void PaymentTavern();
	void Buy(int price);

	int GetDay();
	void AddGold(int newGold);
	void Health(int health);
	int GetAttack();
	std::string GetWeaponName();
	int GetWeaponAttack();
    int GetWeaponAttackS();
	void LvlUp(float exp);

    void SwapWeapon(std::shared_ptr<Weapon> alt_w);

	void showStatus();

	void AttackEnemy(Hero& hero, Enemy* enemy, int damageInt);

	static void DebugcheatMode(int& health, int& gold, float& lvl, int& day);

};
