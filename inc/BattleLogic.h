#pragma once
#include "ModulePerson.h"
class StateMachine;

int MenuGo(Hero&);

void FindLocation(Hero&, StateMachine*);

void WeaponShop(Hero&);

void ItemStore(Hero&);

void Tavern(Hero&);

void LackOfGoldT(Hero&);

void Inventory(Hero&);
