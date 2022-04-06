#pragma once
#include <vector>
#include <memory>
class Hero;
class Weapon;
class Item;

void ItemChoice(short& gch);
void WeaponChoice(short& gch);
short checkInput();

void choiceItem(Hero& hero,std::shared_ptr<Item> item);
void choiceWeapon(Hero& hero, std::shared_ptr<Weapon> weapon);
