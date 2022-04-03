#include <Windows.h>
#include "Color.h"

//--------------------------------Color-----------------------------------///

void SetColor(int text, int background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void SetColor(int text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((static_cast<int>(background) << 4) | text));
}

void SetColor(ConsoleColor text, ConsoleColor background)
{
    HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hStdOut, (WORD)((static_cast<int>(background) << 4) | static_cast<int>(text)));
}
///--------------------------------Color-----------------------------------///
