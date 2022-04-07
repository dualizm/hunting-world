#include <iomanip>
#include <random>
#include <memory>


#include "Logic.h"
#include "console.hpp"
#include "Enum_List.h"
#include "HeirsOfAnItem.h"
#include "LogicShopFunction.h"
#include "InventoryLogic.h"
#include "FightLogic.h"
#include "HeirsOfAnWeapon.h"
#include "LocationLogic.h"
#include "Listgui.h"
#include "lpct.hpp"
#include "LocationLogic.h"
#include "StateMachine.h"

void Inventory(Hero& hero);

int MenuGo(Hero& h)
{
	FSL();

        std::cout << "\n " << h.getName() << " state:\n\n" <<
        " Health: " << std::setw(4);

        lpct::prcolor(lpct::colors::green, h.getHealth());

        std::cout << "  |  " << std::setw(9) << " Weapon: ";
        lpct::prcolor(lpct::colors::cyan, h.getWeaponName());

        std::cout << " |  " <<  " Gold: " << std::setw(6);
        lpct::prcolor(lpct::colors::yellow, h.getGold());

        std::cout << "  |  "  << std::setw(9) << " Attack: " << std::setw(-4);
        lpct::prcolor(lpct::colors::red, h.getAttack());

        std::cout << "\n\n" <<
            " Day: " << h.getDay() << "  |  " << "Level: " << h.getLvl();

        std::cout << "\n\n";

	FSL();
	std::cout << " Menu:\n";
	FSL();

	std::cout <<
    "\n " << static_cast<int>(List::ADVENTURE) << ")Go on an adventure\n" <<
    " " << static_cast<int>(List::TAVERN) << ")Go to the tavern\n" <<
    " " << static_cast<int>(List::WEAPON) << ")Weapon shop\n" <<
    " " << static_cast<int>(List::ITEMS) << ")Item store\n" <<
    " " << static_cast<int>(List::INVENTORY) << ")Inventory\n" <<
    " " << static_cast<int>(List::EXIT) << ")Exit to the main menu\n\n";
	FSL();
    std::cout << "\n Enter the number to select:\n > ";

    return checkInput();
}


void FindLocation(Hero& hero, StateMachine* sm)
{
	enum LocList
	{
		locMISTERYFOREST = 1,
		locOLDCASTLE = 2,
		locSACREDMOUNTAINS = 3,
        locCAVEOFTIME = 4,
		locExit = 0
	};

	bool fight{ true };
    sm->add(fight);
	short getchoice;

	while (fight)
	{
    clrcon();
        LocationChoice(getchoice);

		switch (getchoice)
		{
		case LocList::locMISTERYFOREST:
            GoOnLoc(hero, location_collection[0], sm);
			break;
		case LocList::locOLDCASTLE:
            GoOnLoc(hero, location_collection[1], sm);
			break;
		case LocList::locSACREDMOUNTAINS:
            GoOnLoc(hero, location_collection[2], sm);
			break;
        case LocList::locCAVEOFTIME:
            if(hero.getDay() % 15 == 0)
            {
                GoOnLoc(hero, location_collection[3], sm);
            }
            else
            {
                ErrorFindLocation();
            }
            break;
		case LocList::locExit:
            fight = false;
			break;
		default:
			ErrorMessage();
			break;
		}

	}
}

void Tavern(Hero& h)
{
  clrcon();
	FootnoteB();

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chance = 0 + mersenne() % 100;

	h.paymentTavern();
  if (chance >= 70)
	{
		std::cout << " WELL rested at the tavern!";
        h.SetHealth(h.getMaxHealth() + 100);
	}
	else
	{
		std::cout << " You rested in a tavern!";
        h.SetHealth(h.getMaxHealth());
	}

	h.upDay();

	sleep(2);
	DSTgo();
}

void LackOfGoldT(Hero& hero)
{
	Sms("You don't have enough gold to rest in the tavern!\n You need " + std::to_string(150 * hero.getDay()) + " gold");
	DSTgo();
}

enum class WeaponList
{
    weaponSWORD = 1,
    weaponGUN,
    weaponBIGSSWORD,
    weaponCROSSBOW,
    weaponSNAKEBLADE,
    weaponDRAGONSLAYER,
    weaponEXIT = 0
};

void WeaponShop(Hero& hero) // WEAPON SELECTOR STORE
{

	bool weaponShop{ true };
	short getchoice;

	while (weaponShop)
	{
    clrcon();
    WeaponChoice(getchoice);

        switch (getchoice)
		{
        case static_cast<int>(WeaponList::weaponSWORD):
            choiceWeapon(hero, std::make_shared<Sword>());
			break;
        case static_cast<int>(WeaponList::weaponGUN):
            choiceWeapon(hero,  std::make_shared<Gun>());
			break;
        case static_cast<int>(WeaponList::weaponBIGSSWORD):
            choiceWeapon(hero,  std::make_shared<StaffHealth>());
			break;
        case static_cast<int>(WeaponList::weaponCROSSBOW):
            choiceWeapon(hero,  std::make_shared<Cursedbow>());
			break;
        case static_cast<int>(WeaponList::weaponSNAKEBLADE):
            choiceWeapon(hero,  std::make_shared<SnakeBlade>());
            break;
        case static_cast<int>(WeaponList::weaponDRAGONSLAYER):
            choiceWeapon(hero,  std::make_shared<DragonSlayer>());
            break;
        case static_cast<int>(WeaponList::weaponEXIT):
			weaponShop = false;
			break;
		default:
			ErrorMessage();
			break;
		}

	}
}

enum class ItemList
{
    itemHERB = 1,
    itemPOTION = 2,
    itemHEALTHSCROLL = 3,
    itemCAKE = 4,
    itemEXIT = 0
};

void ItemStore(Hero& hero) // STORE SELECTION OF OBJECTS
{

	bool itemStore{ true };
	short getchoice;

	while (itemStore)
	{
    clrcon();
    ItemChoice(getchoice);

		switch (getchoice)
		{
        case static_cast<int>(ItemList::itemHERB):
            choiceItem(hero, std::make_shared<MedicinalHerb>());
			break;
        case static_cast<int>(ItemList::itemPOTION):
            choiceItem(hero, std::make_shared<BottleHealth>());
			break;
        case static_cast<int>(ItemList::itemHEALTHSCROLL):
            choiceItem(hero, std::make_shared<HealthScroll>());
            break;
        case static_cast<int>(ItemList::itemCAKE):
            choiceItem(hero, std::make_shared<Cake>());
            break;
        case static_cast<int>(ItemList::itemEXIT):
			itemStore = false;
			break;
		default:
			ErrorMessage();
			break;
		}

	}

}

void Inventory(Hero& hero)
{
	if (hero.inventory.empty())
	{
		clrcon();
		FootnoteB();
		std::cout << " Inventory is empty! " << std::endl;
		sleep(1);
	}
	else
	{
		InventoryChoice(hero);
	}
}
