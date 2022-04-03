#include "SupportFunctions.h"
#include "lpct.hpp"
#include "Sms.h"
#include "console.hpp"
#include <string>
#include <unistd.h>

void WinThisGame()
{
    clrcon();
    FSL();
    sleep(1500);
    std::cout << "\n\t\t" << "Hunting world\n" << std::endl;
    sleep(1500);

    std::string finalStory{"\n\t\tFinally, the brave hero defeated the great evil!\n"
                           "\t\tThe remaining monsters fled in fear of the hero.\n"
                           "\t\tA quiet life has come, but who knows,\n"
                           "\t\tevil always finds its way!\n\n"};
    sleep(1500);
    FSL();
    for(auto& ch : finalStory)
    {
        std::cout << ch;
        sleep(150);
    }
    FSL();
    sleep(1500);
    std::cout << "\n\t\t" << "Authors:\n" << std::endl;
    sleep(1500);
    std::cout << "\t\t" << "Programmer: Notidman;\n" << std::endl;
    sleep(1500);
    std::cout << "\t\t" << "ASCII artists: Notidman, HollowKaeden, jbs, Ooyamaneko;\n" << std::endl;
    sleep(1500);
    FSL();
    sleep(1500);
    std::cout << "\n\t\t" << "Thanks for playing, we hope you enjoyed it!\n" << std::endl;
    FSL();
    sleep(1500);
    DSTgo();
	exit(0);
}

void BadEnd()
{
    clrcon();
    FootnoteL();
    std::string str{" In the cave of time, the great dragon has amassed strength.\n He destroyed everything. This is entirely your fault."};

    for(auto& o : str)
    {
        lpct::prcolor<char>(lpct::colors::red, o);
        sleep(250);
    }
    sleep(700);
    DSTgo();

    exit(0);
}

void Menu(short& mode)
{
	FSL();
	FootnoteL();
  std::cout << "\033[41m" << " Hunting world" << "\033[0m" << "\n";
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
  clrcon();
	FootnoteB();
	std::cout << " There is no such command." << std::endl;
	sleep(2000);
	DSTgo();
}
