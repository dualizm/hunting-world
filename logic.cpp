#include "SupportFunctions.h"
#include "Color.h"
#include "Sms.h"
#include <string>

void WinThisGame()
{
    system("cls");
    FSL();
    Sleep(1500);
    std::cout << "\n\t\t" << "Hunting world\n" << std::endl;
    Sleep(1500);

    std::string finalStory{"\n\t\tFinally, the brave hero defeated the great evil!\n"
                           "\t\tThe remaining monsters fled in fear of the hero.\n"
                           "\t\tA quiet life has come, but who knows,\n"
                           "\t\tevil always finds its way!\n\n"};
    Sleep(1500);
    FSL();
    for(auto& ch : finalStory)
    {
        std::cout << ch;
        Sleep(150);
    }
    FSL();
    Sleep(1500);
    std::cout << "\n\t\t" << "Authors:\n" << std::endl;
    Sleep(1500);
    std::cout << "\t\t" << "Programmer: Notidman;\n" << std::endl;
    Sleep(1500);
    std::cout << "\t\t" << "ASCII artists: Notidman, HollowKaeden, jbs, Ooyamaneko;\n" << std::endl;
    Sleep(1500);
    FSL();
    Sleep(1500);
    std::cout << "\n\t\t" << "Thanks for playing, we hope you enjoyed it!\n" << std::endl;
    FSL();
    Sleep(1500);
    DSTgo();
	exit(0);
}

void BadEnd()
{
    system("cls");
    FootnoteL();
    std::string str{" In the cave of time, the great dragon has amassed strength.\n He destroyed everything. This is entirely your fault."};
    SetColor(ConsoleColor::LightRed, ConsoleColor::Black);

    for(auto& o : str)
    {
        std::cout << o;
        Sleep(250);
    }
    Sleep(700);
    DSTgo();

    exit(0);
}

void Menu(short& mode)
{
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
    std::cout <<" Hunting world \n";
	SetColor(ConsoleColor::White, ConsoleColor::Black);
	FootnoteL();
	FSL();
	std::cout << " Menu:\n";
	FSL();

	std::cout <<
		"\n 1)Battle against monsters\n" <<
		" 2)Story line\n" <<
		" 3)Instructions\n" <<
        " 4)Exit\n\n";

	FSL(); 
    std::cout << "\n Enter the number to select:\n > ";

    mode = checkInput();
}

void Exit(bool& request)
{
	std::string x;
	std::cout << " Do you want to exit? (y/n)" << "\n > ";
	std::cin >> x;
	if (std::tolower(x[0]) == 'y') request = false;
}

void ErrorMessage()
{
	system("cls");
	FootnoteB();
	std::cout << " There is no such command." << std::endl;
	Sleep(2000);
	DSTgo();
}
