#include "SupportFunctions.h"
#include "Color.h"

void WinThisGame()
{
	system("cls");
	Footnote();
	std::cout << " YOU WIN THIS GAMEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEEE!";
	Sleep(1500);
	std::cout << " Bye ;3";

	exit(0);
}

char Menu()
{
	char mode;
	FSL();
	FootnoteL();
	SetColor(ConsoleColor::Black, ConsoleColor::Red);
	std::cout <<" Hunting world\n";
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
    mode = checkInput() + '0';
	system("cls");
	return mode;
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
