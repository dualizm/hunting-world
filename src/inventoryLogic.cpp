#include "SupportFunctions.h"
#include "ModulePerson.h"
#include "Logic.h"
#include "lpct.hpp"
#include "ItemClass.h"
#include "console.hpp"
#include <iomanip>

void DisplayInventory(Hero& hero)
{
    FSL();
    std::cout << "\n\n";
    std::cout << "\033[41m" << " " << "Inventory: " << "\033[0m" << std::endl;
    std::cout << "\n\n";
    FSL();

    int i = 1;
	std::cout << "\n";
	for (auto& o : hero.inventory)
	{
        std::cout << " [" << i << "] |" << o->getName() << "\n\n";
        i++;
	}
    std::cout << std::endl;
	FSL();
}

void notFoundInInventory()
{
  clrcon();
	FootnoteB();
	std::cout << " Not found in inventory." << std::endl;
	sleep(2);
	DSTgo();
}

enum class InvCh
{
    EXIT = 0,
    SLOT1,
    SLOT2,
    SLOT3,
    SLOT4,
    SLOT5,
    SLOT6
};

void useItemInInventory(Hero& hero, list_item::iterator it,int place)
{
    if(hero.getHealth() >= hero.getMaxHealth())
    {
        Sms("You are already at maximum health!");
    }
    else
    {
        std::advance(it, place);
        (*it)->use(hero);
        hero.inventory.erase(it);
    }
}

void InventoryChoice(Hero& hero)
{
	bool start = true;
	while (start)
	{
    clrcon();
		DisplayInventory(hero);

		std::cout << " Select the item number to use or exit by entering 0"
			<< "\n > ";

		std::string choice; std::cin >> choice;
		int ch = choice[0] - '0';
		if (ch < 0 || ch > static_cast<int>(hero.inventory.size()))
		{
			notFoundInInventory();
		}
		else
		{
			auto inv_it = hero.inventory.begin();
			switch (ch)
			{
                case static_cast<int>(InvCh::SLOT1):
					useItemInInventory(hero, inv_it, 0);
					break;
                case static_cast<int>(InvCh::SLOT2):
					useItemInInventory(hero, inv_it, 1);
					break;
                case static_cast<int>(InvCh::SLOT3):
					useItemInInventory(hero, inv_it, 2);
					break;
                case static_cast<int>(InvCh::SLOT4):
					useItemInInventory(hero, inv_it, 3);
					break;
                case static_cast<int>(InvCh::SLOT5):
					useItemInInventory(hero, inv_it, 4);
					break;
                case static_cast<int>(InvCh::SLOT6):
					useItemInInventory(hero, inv_it, 5);
					break;
                case static_cast<int>(InvCh::EXIT):
					start = false;
					break;
				default:
					notFoundInInventory();
					break;
			}
		}
	}
}
