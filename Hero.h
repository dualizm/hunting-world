#pragma once
#include <list>
#include <memory>
#include "Sms.h"
#include "Person.h"

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
    const size_t sizeInv{6};
    size_t resetSp;

    list_item inventory; // INVENTORY

    Hero(std::string name, int health, int gold, float lvl, int day, std::shared_ptr<Weapon> weapon)
        : Person(name, health, gold, lvl), day(day), weapon(weapon) {
        this->resetSp = 0;
    }
	
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
