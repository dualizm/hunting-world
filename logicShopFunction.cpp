#include "SupportFunctions.h"
#include "ModulePerson.h"
#include "HeirsOfAnItem.h"
#include "HeirsOfAnWeapon.h"
#include "Logic.h"
#include "Color.h"

#include <iomanip>
#include <memory>

short checkInput()
{
	std::string str; std::cin >> str;
	if (str[0] >= '0' || str[0] <= '9') return str[0] - '0';
	else ErrorMessage();

	return 0;
}

void ItemChoice(short& gch)
{
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
	std::cout << " Rabbit's Foot" << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FootnoteL();
	FSL();
	std::cout << " Welcome to \"Rabbit's Foot\" Store!";
	std::cout << " What do you want to buy?\n";

    std::vector<Item*> cIt{ new MedicinalHerb(), new BottleHealth() }; // create list
	
	FSL();
	int i = 1;
	for (auto& o : cIt)
	{
        std::cout << " " << i << ") " << std::setw(20) << o->GetName() <<
			" (";
		SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
        std::cout << o->GetPrice() << "G";
		SetColor(ConsoleColor::White, ConsoleColor::Black);

		std::cout << ") " << std::setw(6);

		SetColor(ConsoleColor::Green, ConsoleColor::Black);
        std::cout << "+" << o->Info() << std::endl;
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
	std::cout << " Iron Fist" << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FootnoteL();

	FSL();
	std::cout << " Welcome to \"Iron Fist\" Store!";
	std::cout << " What do you want to buy?\n";

    std::vector<Weapon*> cWp{ new Sword(), new Gun(), new BigSword(), new Crossbow() };

	FSL();
	int i = 1;
	for (auto& o : cWp)
	{
        std::cout << " " << i << ") " << std::setw(10) << o->getName() << " (" << std::setw(4);

		SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
        std::cout << o->getPrice();
		SetColor(ConsoleColor::White, ConsoleColor::Black);

		std::cout << " G)\t"
			<< "State: Damage = ";
		SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
        std::cout << o->getDamage();
		SetColor(ConsoleColor::White, ConsoleColor::Black);

		std::cout << "; Chance = ";
		SetColor(ConsoleColor::Cyan, ConsoleColor::Black);
        std::cout << o->getChance();
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
    if (hero.GetGold() < weapon->getPrice())
	{
		std::cout << " You don't have enough money";
		Sleep(1000);
	}
	else
	{
		if (hero.GetWeaponName() == weapon->getName())
		{
			std::cout << " You already have this weapon";
			Sleep(1000);
		}
		else
		{
			hero.SwapWeapon(weapon);
            hero.Buy(weapon->getPrice());
			std::cout << " A \"" << weapon->getName() << "\" was purchased!";
			Sleep(1000);
		}
	}
}

void choiceItem(Hero& hero, std::shared_ptr<Item> item)
{
    if (hero.inventory.size() == hero.sizeInv)
	{
		std::cout << " Inventory is full =(";
		Sleep(1000);
	}
	else
	{
        if (hero.GetGold() < item->GetPrice())
		{
			std::cout << " You don't have enough money";
			Sleep(1000);
		}
		else
		{
			hero.inventory.push_back(item);
            hero.Buy(item->GetPrice());
			std::cout << " A \"" <<  item->GetName() << "\" has been added to your inventory!";
			Sleep(1000);
		}
	}
}
