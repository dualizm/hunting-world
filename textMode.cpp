#include "SupportFunctions.h"
#include "Color.h"
#include <conio.h>
#include <vector>
#include <cstring>
#include <random>
#include <ctime>

void Screensaver()
{
    std::vector<std::string> screensaver = {
        {"........                                              /.               ........"},
        {"........   /`     /``   /`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/` ........"},
        {"........   /`     /``                                 /.     /.        ........"},
        {"........   /`     /``     /`        /`       /.       /.     /.        ........"},
        {"........   /`     /``     /``      /``       /./`     /.     /.        ........"},
        {"........   /` /`` /``     /` `    /` `       /. /`    /.     /.        ........"},
        {"........   /```  ````     /`  `  /`  `       /.  /`   /.     /.        ........"},
        {"........   /`     /``      /`  `/`  `        /.   /`  /.     /.        ........"},
        {"........   /`     /``       /`  `  `         /.     /` .     /.        ........"},
        {"........   /`     /``        /`   `          /.      /`.     /.        ........"},
        {"........   /`     /``         /` `           /.              /.        ........"},
        {"........   /`     /``          /`            /.              /.        ........"}
    };

    FootnoteL();
    std::mt19937 mersenne(static_cast<unsigned int>(time(0)));

    for(auto& o : screensaver)
    {
        int chance = 1 + mersenne() % 15;
        SetColor(chance, ConsoleColor::Black);
        std::cout << o << std::endl;
        Sleep(100);
    }
	Sleep(2000);

    SetColor(ConsoleColor::White, ConsoleColor::Black);
    DSTgo();

}

void StoryLine()
{
    system("cls");
    FootnoteL();
    std::string str{" In the era of war between humans and monsters, the great dragon was summoned\n to destroy the world.\n"
                    " But after being drafted, he was weakened. Brave heroes who went to him were\n destroyed by monsters.\n"
                    " Who knows, maybe you can do it ..\n"};
    FSL();
    for(auto& o : str)
    {
        std::cout << o;
        Sleep(100);
    }
    FSL();
    Sleep(700);
    DSTgo();
}

void GameInstructions()
{
    system("cls");
	FSL();
    std::cout << "\n Hi, this is a game instruction\n\n";
    FSL();
    std::cout << " The essence of the game is to destroy the great dragon in 30 days.\n\n"
        << " To get through the day, you need to relax in a tavern.\n The tavern is also a way to restore health.\n\n"
		<< " To get gold you need to enter the arena and fight monsters.\n"
        << " The difficulty of the game increases with the number of playing days that\n have passed.\n\n"
        << " You can meet the dragon only on the 15th and 30th day.." << std::endl;
	FSL();

	DSTgo();
}
