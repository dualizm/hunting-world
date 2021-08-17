#pragma once
#include <iostream>
#include <Windows.h>

inline void FSL()
{
	std::cout << "+";
	for (size_t i = 0; i < 78; ++i) std::cout << "-";
	std::cout << "+";
	std::cout << "\n";
}

inline void Footnote()
{
	for (size_t i = 0; i < 8; i++) std::cout << "\n";
}

inline void FootnoteL()
{
	for (size_t i = 0; i < 4; i++) std::cout << "\n";
}

inline void FootnoteB()
{
	Footnote();
	FootnoteL();
}

inline void DSTgo()
{
	std::cout << "\n Do something to get out!\n";
	system("pause>nul");
}