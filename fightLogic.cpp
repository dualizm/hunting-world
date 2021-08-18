#include "FightLogic.h"
#include "HeirsOfAnEnemy.h"
#include "LogicShopFunction.h"
#include "Logic.h"
#include "Sms.h"
#include "Color.h"
#include "BattleLogic.h"
#include "Listgui.h"

#include <random>
#include <functional>
#include <ctime>

void ShowBattlelogText()
{
    FSL();
    SetColor(ConsoleColor::Black, ConsoleColor::Red);
    std::cout << " Battlelog: " << std::endl;
    SetColor(ConsoleColor::White, ConsoleColor::Black);
    FSL();
}

void Attack(Hero& hero, Enemy* p_enemy, int damageIn)
{
    ShowBattlelogText();

	Sleep(150);
	hero.AttackEnemy(hero, p_enemy, damageIn);
	if (p_enemy->GetHealth() <= 0 && hero.GetHealth() > 0)
	{
		DSTgo();
		return;
	}
	p_enemy->AttackHero(hero);
	Sleep(150);
	FSL();

	DSTgo();
}


void SignalAttackReset()
{
    ShowBattlelogText();

    std::cout << " Special attack is still on cooldown!";

    Sleep(150);
    DSTgo();
}

void TryEscape(Hero& hero, Enemy* p_enemy, bool& status)
{
    ShowBattlelogText();

    Sleep(150);
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int ch = 1 + mersenne() % 100;

	if (ch >= 95)
	{
        std::cout << " Successful escape!\n";
        DSTgo();
		status = false;
	}
	else
	{
        std::cout << " Escape failed!\n";
		p_enemy->AttackHero(hero);
		DSTgo();
		status = true;
	}
}

Enemy* Notification(Hero& hero, std::string loc)
{
	system("cls");

	std::cout << " The enemy is found!" << std::endl;
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));
	int chance = 0 + mersenne() % 100;

    if(loc == location_collection[0])
    {
        if (chance >= 0 && chance < 40)
        {
            return new FSlime(hero);
        }
        else if (chance >= 40 && chance < 80)
        {
            return new Goblin(hero);
        }
        else if (chance >= 80)
        {
            return new SlimeBoss(hero);
        }
    }
    else if(loc == location_collection[1])
    {
        if (chance >= 0 && chance < 40)
        {
            return new FSlime(hero);
        }
        else if (chance >= 40 && chance < 80)
        {
            return new Goblin(hero);
        }
        else if (chance >= 80)
        {
            return new SlimeBoss(hero);
        }
    }
    else if(loc == location_collection[2])
    {
		return new SlimeBoss(hero);
    }

	return new Goblin(hero);
}

void Solution(short& gch, Enemy* p_enemy, Hero& h)
{
	std::vector<std::string> menu_collection = { {" Attack"}, {" Special attack"}, {" Open inventory"}, {" Try to escape"}};

	FSL();
    SetColor(p_enemy->getColor(), ConsoleColor::Black);
	p_enemy->showSprite();
    SetColor(ConsoleColor::White, ConsoleColor::Black);
	FSL();

	p_enemy->showStatus();
	FSL();
	h.showStatus();
	FSL();

	std::cout << "\n";
	int i = 1;
	for (auto& str : menu_collection)
	{
        if(str == menu_collection[1] && h.resetSp > 0)
        {
            SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
            std::cout << " " << i << ")" << str;
            SetColor(ConsoleColor::White, ConsoleColor::Black);
            std::cout << " |" << (i % 4 == 0 ? "\n" : "  ");
        }
        else
        {
            std::cout << " " << i << ")" << str << " |" << (i % 4 == 0 ? "\n" : "  ");
        }
		i++;
	}

	std::cout << "\n Enter your choice:\n > ";

	gch = checkInput();
}

bool WinFight(Hero& hero, Enemy* p_enemy)
{
	Sms("You won this fight\n Congratulations!");
	hero.AddGold(p_enemy->GetGold());
	hero.LvlUp(p_enemy->GetExp());

	return false;
}

void LoseFight()
{
	Sms("You died in battle!");

    SetColor(ConsoleColor::LightRed, ConsoleColor::Black);
    Sms(" GAME-OVER ");
    SetColor(ConsoleColor::White, ConsoleColor::Black);

	DSTgo();

    exit(0);
}

void Fight(Hero& hero, std::string loc)
{
	enum FightList
	{
		fightATTACK = 1,
		fightSPECIAL = 2,
		fightINV = 3,
		fightRUN = 4,
	};

    Enemy* p_enemy = Notification(hero, loc);

	bool fight = true;
	short getchoice;

	while (fight)
	{
		system("cls");
		Solution(getchoice, p_enemy, hero);

		switch (getchoice)
		{
			case FightList::fightATTACK:
				Attack(hero, p_enemy, hero.GetWeaponAttack());
				break;
			case FightList::fightSPECIAL:
                if(hero.resetSp > 0)
                    SignalAttackReset();
                else
                    Attack(hero, p_enemy, hero.GetWeaponAttackS());
				break;
			case FightList::fightINV:
				Inventory(hero);
				break;
			case FightList::fightRUN:
				TryEscape(hero, p_enemy, fight);
				break;
			default:
				ErrorMessage();
				break;
		}

		if (hero.GetHealth() <= 0)
			LoseFight();

		if (p_enemy->GetHealth() <= 0 && hero.GetHealth() > 0)
        {
			fight = WinFight(hero, p_enemy);
            hero.resetSp = 0;
        }
	}
}
