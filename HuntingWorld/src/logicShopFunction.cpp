#include "SupportFunctions.h"
#include "ModulePerson.h"
#include "HeirsOfAnItem.h"
#include "HeirsOfAnWeapon.h"
#include "Logic.h"
#include "lpct.hpp"
#include "ItemClass.h"

#include <iomanip>
#include <memory>
#include <string>
#include <vector>

void ItemChoice(short& gch)
{
	FSL();
	FootnoteL();
    std::cout << "\033[41m" << " Rabbit's Foot " << "\033[0m" << std::endl;
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
        std::cout << std::setw(4) << lpct::get_colorstr<std::string>(lpct::colors::yellow, std::to_string(o->getPrice())) << "G";

		std::cout << ") " << std::setw(6);

    std::cout << lpct::get_colorstr<std::string>(lpct::colors::green, o->info()) << std::endl;
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
  std::cout << "\033[41m" << " Iron Fist " << "\033[0m" << std::endl;
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

        std::cout << lpct::get_colorstr<std::string>(lpct::colors::yellow, std::to_string(o->getPrice()));

        std::cout << " G) "
			<< "State: Damage = ";
        std::cout << std::setw(3) << lpct::get_colorstr<std::string>(lpct::colors::red, std::to_string(o->getDamage()));

		std::cout << "; Chance = ";
        std::cout << lpct::get_colorstr<std::string>(lpct::colors::cyan, std::to_string(o->getChance()));

        std::cout << "; SP =";
        std::cout << lpct::get_colorstr<std::string>(lpct::colors::green, o->shopInfo());

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
		sleep(1000);
	}
	else
	{
        if (hero.getWeaponName() == weapon->getName())
		{
			std::cout << " You already have this weapon";
			sleep(1000);
		}
		else
		{
            hero.swapWeapon(weapon);
            hero.buy(weapon->getPrice());
			std::cout << " A \"" << weapon->getName() << "\" was purchased!";
			sleep(1000);
		}
	}
}

void choiceItem(Hero& hero, std::shared_ptr<Item> item)
{
    if (hero.inventory.size() == hero.getMaxSizeInventory())
	{
		std::cout << " Inventory is full =(";
		sleep(1000);
	}
	else
	{
        if (hero.getGold() < item->getPrice())
		{
			std::cout << " You don't have enough money";
			sleep(1000);
		}
		else
		{
			hero.inventory.push_back(item);
            hero.buy(item->getPrice());
            std::cout << " A \"" <<  item->getName() << "\" has been added to your inventory!";
			sleep(1000);
		}
	}
}
