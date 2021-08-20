#include "SupportFunctions.h"
#include <conio.h>
#include <vector>
#include <cstring>

void Screensaver()
{
    std::vector<std::string> screensaver = {
        {"........                                              /.               ........"},
        {"........   /`     /``   /`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/`/` ........"},
        {"........   /`     /``                                 /.     /.        ........"},
        {"........   /`     /``        /``````         /.       /.     /.        ........"},
        {"........   /`     /``       /`  ``  `        /./`     /.     /.        ........"},
        {"........   /` /`` /``      /`  ` /`  `       /. /`    /.     /.        ........"},
        {"........   /```  ````     /`   /```   `      /.  /`   /.     /.        ........"},
        {"........   /`     /``     /`  /` /`   `      /.   /`  /.     /.        ........"},
        {"........   /`     /``     /` /`   /`  `      /.     /` .     /.        ........"},
        {"........   /`     /``     /`/`     /` `      /.      /`.     /.        ........"},
        {"........   /`     /``     /``       /``      /.              /.        ........"},
        {"........   /`     /``     /`         /`      /.              /.        ........"}
    };

    FootnoteL();

    for(auto& o : screensaver)
    {
        std::cout << o << std::endl;
        Sleep(100);
    }
	Sleep(2000);

    DSTgo();

}

void StoryLine()
{
	system("cls");
	Footnote();
	FSL();
	std::cout << " You must kill all monsters!!!!\n";
	FSL();
	DSTgo();
}

void GameInstructions()
{
    system("cls");
	FSL();
	std::cout << "\n Hi, this is a game instruction\n\n"
		<< " The essence of the game is to destroy the great dragon.\n\n"
		<< " To get through the day, you need to rest in a tavern for the amount of that day and the tavern is a way to restore health.\n"
		<< " To get gold you need to enter the arena and fight monsters.\n"
		<< " The difficulty of the game increases with the number of playing days passed." << std::endl;
	FSL();


	DSTgo();
}
