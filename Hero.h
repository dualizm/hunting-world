#pragma once
#include <list>
#include <memory>
#include "Sms.h"
#include "Person.h"

class Item;
class Enemy;
class Weapon;

using list_item = std::list<std::shared_ptr<Item>>;

class Hero final : public Person
{

private:
    int day;  // GAME DAY
    std::shared_ptr<Weapon> weapon; // WEAPON

public:
    size_t resetSp{0};

    list_item inventory; // INVENTORY

    Hero(std::string name, int health, int gold, float lvl, int day, std::shared_ptr<Weapon> weapon)
        : Person(name, health, gold, lvl), day(day), weapon(weapon) {
    }
	
    void upDay();
    void paymentTavern();
    void buy(int price);
    int getMaxHealth();
    int getDay();
    void addGold(int newGold);
    void addHealth(int health);
    int getAttack();
    std::string getWeaponName();
    int getWeaponAttack();
    int getWeaponAttackS();
    void lvlUp(float exp);
    size_t getMaxSizeInventory();

    void swapWeapon(std::shared_ptr<Weapon> alt_w);

	void showStatus();

    void attackEnemy(Hero& hero, Enemy* enemy, int damageInt);

    static void debugcheatMode(int& health, int& gold, float& lvl, int& day);

    ~Hero() = default;

};
