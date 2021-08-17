/*************************************************************************
* Hunting world														     *
* v.1.1	beta															 *
* create 16.06.2021														 *
* last update 02.08.2021												 *
*************************************************************************/

#define _WIN32_WINNT 0x0500
#include <windows.h>
#include "Color.h"
#include "Logic.h" // Includes a file with menu logic
#include "TextMode.h" // Includes a file with the text component of the menu
#include "BattleMenu.h" // Includes a file with game logic

int main()
{
	HWND consoleWindow = GetConsoleWindow(); SetWindowLong(consoleWindow, GWL_STYLE, GetWindowLong(consoleWindow, GWL_STYLE) & ~WS_MAXIMIZEBOX & ~WS_SIZEBOX);
	system("mode con cols=80 lines=25");
    //Screensaver(); // Displays the game splash screen

	bool work{true};
	while (work)
    {
		system("cls");
        short choice;
        Menu(choice); // Displays the game menu and gives you a choice! REALIZED

		switch (choice)
		{
        case static_cast<int>(main_menu::BATTLEMODE):
            BattleMode(); // Starts the battle against monsters! PROCESS
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
