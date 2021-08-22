#include "SupportFunctions.h"
#include "ModulePerson.h"
#include "HeirsOfAnItem.h"
#include "HeirsOfAnWeapon.h"
#include "Logic.h"
#include "Color.h"
#include "ItemClass.h"

#include <iomanip>
#include <memory>
#include <vector>

void ItemChoice(short& gch)
{
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
    std::cout << " Rabbit's Foot " << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FootnoteL();
	FSL();
	std::cout << " Welcome to \"Rabbit's Foot\" Store!";
	std::cout << " What do you want to buy?\n";

    std::vector<Item*> cIt{ new MedicinalHerb(), new BottleHealth(), new HealthScroll(), new Cake() }; // create list
	
	FSL();
	int i = 1;
	for (auto& o : cIt)
	{
        std::cout << " " << i << ") " << std::setw(20) << o->getName() <<
			" (";
		SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
        std::cout << std::setw(4) << o->getPrice() << "G";
		SetColor(ConsoleColor::White, ConsoleColor::Black);

		std::cout << ") " << std::setw(6);

		SetColor(ConsoleColor::Green, ConsoleColor::Black);
        std::cout << o->info() << std::endl;
		SetColor(ConsoleColor::White, ConsoleColor::Black);
		i++;
	}
	FSL();

    for(auto& o : cIt) // clear memory
    {
        delete o;
    }

	std::cout << "\n Enter your choice (0 to exit):\n > ";

	gch = checkInput();
}

void WeaponChoice(short& gch)
{
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
    std::cout << " Iron Fist " << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FootnoteL();

	FSL();
	std::cout << " Welcome to \"Iron Fist\" Store!";
	std::cout << " What do you want to buy?\n";

    std::vector<Weapon*> cWp{ new Sword(), new Gun(), new StaffHealth(), new Cursedbow(), new SnakeBlade(), new DragonSlayer() };

	FSL();
	int i = 1;
	for (auto& o : cWp)
	{
        std::cout << " " << i << ") " << std::setw(12) << o->getName() << " (" << std::setw(4);

		SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
        std::cout << o->getPrice();
		SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << " G) "
			<< "State: Damage = ";
		SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
        std::cout << std::setw(3) << o->getDamage();
		SetColor(ConsoleColor::White, ConsoleColor::Black);

		std::cout << "; Chance = ";
		SetColor(ConsoleColor::Cyan, ConsoleColor::Black);
        std::cout << o->getChance();
		SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << "; SP =";
        SetColor(ConsoleColor::LightGreen, ConsoleColor::Black);
        std::cout << o->shopInfo();
        SetColor(ConsoleColor::White, ConsoleColor::Black);

        std::cout << ";" << std::endl;
		i++;
	}
	FSL();

    for(auto& o : cWp) // clear memory
    {
        delete o;
    }


	std::cout << "\n Enter your choice (0 to exit):\n > ";

	gch = checkInput();
}

void choiceWeapon(Hero& hero, std::shared_ptr<Weapon> weapon)
{
    if (hero.getGold() < weapon->getPrice())
	{
		std::cout << " You don't have enough money";
		Sleep(1000);
	}
	else
	{
        if (hero.getWeaponName() == weapon->getName())
		{
			std::cout << " You already have this weapon";
			Sleep(1000);
		}
		else
		{
            hero.swapWeapon(weapon);
            hero.buy(weapon->getPrice());
			std::cout << " A \"" << weapon->getName() << "\" was purchased!";
			Sleep(1000);
		}
	}
}

void choiceItem(Hero& hero, std::shared_ptr<Item> item)
{
    if (hero.inventory.size() == hero.getMaxSizeInventory())
	{
		std::cout << " Inventory is full =(";
		Sleep(1000);
	}
	else
	{
        if (hero.getGold() < item->getPrice())
		{
			std::cout << " You don't have enough money";
			Sleep(1000);
		}
		else
		{
			hero.inventory.push_back(item);
            hero.buy(item->getPrice());
            std::cout << " A \"" <<  item->getName() << "\" has been added to your inventory!";
			Sleep(1000);
		}
	}
}
