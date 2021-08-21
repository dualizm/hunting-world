#include "SupportFunctions.h"
#include "Color.h"
#include "Sms.h"

void WinThisGame()
{
    Sms("You kill the great dragon");
    std::cout << " Bye ;3";
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
	std::cout << "\n > ";

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
