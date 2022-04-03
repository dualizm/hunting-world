#include "LocationLogic.h"

#include "Color.h"
#include "SupportFunctions.h"
#include "LogicShopFunction.h"
#include "Logic.h"
#include "FightLogic.h"
#include "Listgui.h"
#include "StateMachine.h"

#include <vector>

void ErrorFindLocation()
{
    SetColor(ConsoleColor::LightBlue, ConsoleColor::Black);
    Sms("You try to find your way, but the magical light takes you off the path.");

    DSTgo();
    SetColor(ConsoleColor::White, ConsoleColor::Black);
}

void LocationChoice(short& gch)
{
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
	std::cout << " Locations menu: " << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
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
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
	std::cout << " " << loc << std::endl;
	SetColor(ConsoleColor::White, ConsoleColor::Black);
    std::cout << "\n";
    std::cout << " Health: ";
    SetColor(ConsoleColor::LightGreen, ConsoleColor::Black);
    std::cout << hero.getHealth();
    SetColor(ConsoleColor::White, ConsoleColor::Black);

    std::cout << " | " << "Gold: ";
    SetColor(ConsoleColor::Yellow, ConsoleColor::Black);
    std::cout << hero.getGold() << "\n\n";
    SetColor(ConsoleColor::White, ConsoleColor::Black);

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
		system("cls");
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
