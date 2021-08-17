#include <iomanip>
#include <random>
#include <memory>


#include "Logic.h"
#include "Enum_List.h"
#include "HeirsOfAnItem.h"
#include "LogicShopFunction.h"
#include "InventoryLogic.h"
#include "FightLogic.h"
#include "HeirsOfAnWeapon.h"
#include "LocationLogic.h"
#include "Listgui.h"

void Inventory(Hero& hero);

int MenuGo(Hero& h)
{
	FSL();

        std::cout << "\n " << h.GetName() << " state:\n\n" <<
        " Health: " << std::setw(4);

        SetColor(ConsoleColor::Green, ConsoleColor::Black);
        std::cout << h.GetHealth();
        SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << "  |  " << std::setw(9) << " Weapon: ";
        SetColor(ConsoleColor::Cyan, ConsoleColor::Black);
        std::cout << h.GetWeaponName();
        SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << "\n" << " Gold: " << std::setw(6);
        SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
        std::cout << h.GetGold();
        SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << "  |  "  << std::setw(9) << " Attack: " << std::setw(-4);
        SetColor(ConsoleColor::Red, ConsoleColor::Black);
        std::cout << h.GetAttack();
        SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << "\n\n" <<
            " Day: " << h.GetDay() << "  |  " << "Level: " << h.GetLvl();

        std::cout << "\n\n";

	FSL();
	std::cout << " Menu:\n";
	FSL();

	std::cout <<
	"\n " << List::ADVENTURE << ")Go on an adventure\n" <<
	" " << List::TAVERN << ")Go to the tavern\n" <<
	" " << List::WEAPON << ")Weapon shop\n" <<
	" " << List::ITEMS << ")Item store\n" <<
	" " << List::INVENTORY << ")Inventory\n" <<
	" " << List::EXIT << ")Exit to the main menu\n\n";
	FSL();
	std::cout << "\n > ";

    return checkInput();
}


void FindLocation(Hero& hero)
{
	enum LocList
	{
		locMISTERYFOREST = 1,
		locOLDCASTLE = 2,
		locSACREDMOUNTAINS = 3,
		locExit = 0
	};

	bool fight{ true };
	short getchoice;

	while (fight)
	{
		system("cls");
        LocationChoice(getchoice);

		switch (getchoice)
		{
		case LocList::locMISTERYFOREST:
            GoOnLoc(hero, location_collection[0]);
			break;
		case LocList::locOLDCASTLE:
            GoOnLoc(hero, location_collection[1]);
			break;
		case LocList::locSACREDMOUNTAINS:
            GoOnLoc(hero, location_collection[2]);
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
	system("cls");
	FootnoteB();

	if (h.GetDay() >= 30)
		WinThisGame();

    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chance = 0 + mersenne() % 100;

	h.PaymentTavern();
	if (chance >= 80)
	{
		std::cout << " WELL rested at the tavern!";
		h.SetHealth(150);
	}
	else
	{
		std::cout << " You rested in a tavern!";
		h.SetHealth(100);
	}

	h.Upday();

	Sleep(2000);
	DSTgo();
}

void LackOfGoldT(Hero& hero)
{
	Sms("You don't have enough gold to rest in the tavern!\n You need " + std::to_string(150 * hero.GetDay()) + " gold");
	DSTgo();
}

void WeaponShop(Hero& hero) // WEAPON SELECTOR STORE
{
	enum WeaponList
	{
		weaponSWORD = 1,
		weaponGUN = 2,
		weaponBIGSSWORD = 3,
		weaponCROSSBOW = 4,
		weaponEXIT = 0
	};

	bool weaponShop{ true };
	short getchoice;

	while (weaponShop)
	{
		system("cls");
        WeaponChoice(getchoice);

		switch (getchoice)
		{
		case WeaponList::weaponSWORD:
            choiceWeapon(hero, std::make_shared<Sword>());
			break;
		case WeaponList::weaponGUN:
            choiceWeapon(hero,  std::make_shared<Gun>());
			break;
		case WeaponList::weaponBIGSSWORD:
            choiceWeapon(hero,  std::make_shared<BigSword>());
			break;
		case WeaponList::weaponCROSSBOW:
            choiceWeapon(hero,  std::make_shared<Crossbow>());
			break;
		case WeaponList::weaponEXIT:
			weaponShop = false;
			break;
		default:
			ErrorMessage();
			break;
		}

	}
}

void ItemStore(Hero& hero) // STORE SELECTION OF OBJECTS
{
	enum ItemList
	{
		itemHERB = 1,
		itemPOTION = 2,
		itemEXIT = 0
	};

	bool itemStore{ true };
	short getchoice;

	while (itemStore)
	{
		system("cls");
        ItemChoice(getchoice);

		switch (getchoice)
		{
		case ItemList::itemHERB:
            choiceItem(hero, std::make_shared<MedicinalHerb>());
			break;
		case ItemList::itemPOTION:
            choiceItem(hero, std::make_shared<BottleHealth>());
			break;
		case ItemList::itemEXIT:
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
		system("cls");
		FootnoteB();
		std::cout << " Inventory is empty! " << std::endl;
		Sleep(1000);
	}
	else
	{
		InventoryChoice(hero);
	}
}
