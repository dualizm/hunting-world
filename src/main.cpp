
/*|+----------------------------------------------------------------------+|*\
 *|   ProgramName: Hunting world                                           |*
 *|   CreateDate: 16.06.2021                                               |*
 *|   Version: v.1.2 beta                                                  |*
 *|   Author: Ezi                                                          |*
 *|   Language: C++                                                        |*
 *|   Copyright © 2022 Ezi . All Rights Reserved.                          |*
\*|+---------------------------------| HUNTING WORLD |--------------------+|*/

#include <cwchar>
#include "lpct.hpp"
#include "console.hpp"
#include "Logic.h" // Includes a file with menu logic
#include "TextMode.h" // Includes a file with the text component of the menu
#include "BattleMenu.h" // Includes a file with game logic
#include "StateMachine.h" // Includes a file with logic states

int 
main()
{
    Screensaver(); // Displays the game splash screen

    auto sm = new StateMachine();

    bool work{true};
    sm->add(work);

	  while (work)
    {
        clrcon();
        short choice;
        Menu(choice); // Displays the game menu and gives you a choice! REALIZED

		switch (choice)
		{
        case static_cast<int>(main_menu::BATTLEMODE):
            BattleMode(sm); // Starts the battle against monsters! PROCESS
			break;
        case static_cast<int>(main_menu::STORYLINE):
            StoryLine(); // Displays game history! PROCESS
			break;
        case static_cast<int>(main_menu::GAMEINSTRUCTIONS):
            GameInstructions(); // Tells how to play! PROCESS
			break;
        case static_cast<int>(main_menu::EXIT):
            Exit(work); // Make a request to exit! REALIZED
			break;
		    default:
            ErrorMessage(); // Displays a message about a non-existent command! REALIZED
			break;
		}
	}

}
