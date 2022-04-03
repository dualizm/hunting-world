#include "LocationLogic.h"

#include "lpct.hpp"
#include "SupportFunctions.h"
#include "LogicShopFunction.h"
#include "Logic.h"
#include "FightLogic.h"
#include "Listgui.h"
#include "StateMachine.h"
#include "console.hpp"

#include <vector>

void ErrorFindLocation()
{
    Sms(
        lpct::get_colorstr<std::string>(lpct::colors::blue, 
        "You try to find your way, but the magical light takes you off the path."));

    DSTgo();
}

void LocationChoice(short& gch)
{
	FSL();
	FootnoteL();
	std::cout << "\033[41m" << " Locations menu: " << "\033[0m" << std::endl;
	FootnoteL();
	FSL();
	int i = 1;
    for (auto& o : location_collection)
	{
		std::cout << " " << i << ") " << o << std::endl;
		i++;
	}
	FSL();

	std::cout << "\n Enter your choice (0 to exit):\n > ";

	gch = checkInput();
}

void FightChoice(short& gch, Hero& hero, std::string loc, std::vector<std::string> mFch)
{
	FSL();
	FootnoteL();
	std::cout << "\033[41m" << " " << loc << "\033[0m" << std::endl;
    std::cout << "\n";
    std::cout << " Health: ";
    lpct::prcolor<std::string>(lpct::colors::green, std::to_string(hero.getHealth()));

    std::cout << " | " << "Gold: ";
    lpct::prcolor<std::string>(lpct::colors::yellow, std::to_string(hero.getGold()));
    std::cout << "\n\n";

	FSL();
	int i = 1;
	for (auto& o : mFch)
	{
		std::cout << " " << i << ")" << o << std::endl;
		i++;
	}
    FSL();

	std::cout << "\n Enter your choice (0 to exit):\n > ";

	gch = checkInput();
}

void GoOnLoc(Hero& hero, std::string loc, StateMachine* sm)
{
	enum Fchoice
	{
		FENEMY = 1,
		FExit = 0
	};

    std::vector<std::string> mFch{ {"Find the enemy"} };

	bool check{ true };
	short getchoice;
    sm->add(check);

	while (check)
	{
    clrcon();
        FightChoice(getchoice, hero, loc, mFch);

		switch (getchoice)
		{
		case Fchoice::FENEMY:
            Fight(hero, loc, sm);
			break;
		case Fchoice::FExit:
            check = false;
			break;
		default:
			ErrorMessage();
			break;
		}

	}
}
