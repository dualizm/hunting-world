#include "SupportFunctions.h"
#include "Logic.h"
#include "BattleLogic.h"
#include "Enum_List.h"
#include "Weapon.h"
#include "HeirsOfAnWeapon.h"
#include "StateMachine.h"
#include "console.hpp"

void GetName(std::string& name)
{
	bool correct = false;

	do
	{

		FootnoteB();
		std::cout << " Enter your name (1-10 characters):\n > ";
		std::cin >> name;
		if (name.length() > 10 || name.length() <= 0)
		{
      clrcon();
			FootnoteB();
			std::cout << "\nNot correct input!\n"
				<< "Try again!";
			sleep(1);
      clrcon();
		}
		else
			correct = true;

	} while (!correct);
}

void BattleMode(StateMachine* sm)
{
	int health{ 100 }, gold{ 0 }, day{ 1 }; float lvl{ 1.0f };
    Hero::debugcheatMode(health, gold, lvl, day); 
    clrcon();

    std::string name; GetName(name);     // Get the player's name
    Hero hero(name, health, gold, lvl, day, std::make_shared<Fists>()); // Create a hero

	bool battle{ true };
    sm->add(battle);

	while (battle)
	{
    clrcon();
        int go = MenuGo(hero); // Selection menu in the game! REALIZED

		switch (go)
		{
        case static_cast<int>(List::ADVENTURE): // Search for locations! PROCESS
            FindLocation(hero, sm);
			break;
        case static_cast<int>(List::TAVERN): // Rest in the tavern! REALIZED
            if (hero.getGold() < 150 * hero.getDay())
				LackOfGoldT(hero);
			else
				Tavern(hero);
            if(hero.getDay() > 30)
                BadEnd();
			break;
        case static_cast<int>(List::WEAPON): // Weapon shop! REALIZED
			WeaponShop(hero);
			break;
        case static_cast<int>(List::ITEMS): // Shop with items! REALIZED
			ItemStore(hero);
			break;
        case static_cast<int>(List::INVENTORY): // Player Inventory! REALIZED
			Inventory(hero);
			break;
        case static_cast<int>(List::EXIT): // Exit to the main menu! REALIZED
			Exit(battle);
			break;
		default:
            ErrorMessage(); // Displays a message about a non-existent command! REALIZED
			break;
		}
	}

}
