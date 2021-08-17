#pragma once
#include "Weapon.h"


class Fists : public Weapon
{
public:
	Fists() : Weapon(10, "Fists", 100.0f, 0) {}
};

class Sword : public Weapon
{
public:
	Sword() : Weapon(25, "Sword", 70.0f, 800) {}
};

class Gun : public Weapon
{
public:
	Gun() : Weapon(20, "Gun", 80.0f, 800) {}

};

class BigSword : public Weapon
{
public:
	BigSword() : Weapon(70, "BigSword", 60.0f, 1600) {}

};

class Crossbow : public Weapon
{
public:
	Crossbow() : Weapon(55, "Crossbow", 90.0f, 2000) {}

};
