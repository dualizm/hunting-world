#include "SupportFunctions.h"
#include <vector>
#include <cstring>
#include <random>
#include <ctime>
#include "lpct.hpp"
#include <unistd.h>
#include "console.hpp"

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
    for(auto& o : screensaver)
    {
        std::cout << o << std::endl;
    }
	  sleep(3);

    DSTgo();
}

void StoryLine()
{
    clrcon();
    FootnoteL();
    std::string str{" In the era of war between humans and monsters, the great dragon was summoned\n to destroy the world.\n"
                    " But after being drafted, he was weakened. Brave heroes who challenged him were\n destroyed by monsters.\n"
                    " Who knows, maybe you can do it ..\n"};
    FSL();
    for(auto& o : str)
    {
        std::cout << o;
    }
    FSL();
    sleep(3);
    DSTgo();
}

void GameInstructions()
{
  clrcon();
	FSL();
    std::cout << "\n Hi, this is a game instruction\n\n";
    FSL();
    std::cout << " The essence of the game is to destroy the great dragon in 30 days.\n\n"
        << " To get through the day, you need to relax in a tavern.\n The tavern is also a way to restore health.\n\n"
		<< " To get gold you need to enter the arena and fight monsters.\n"
        << " The difficulty of the game increases with the number of playing days that\n have passed.\n\n"
        << " You can meet the dragon only on the 15th and 30th day.." << std::endl;
	FSL();
  sleep(5);
	DSTgo();
}
