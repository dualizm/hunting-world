#ifndef _CONSOLE_HPP_
#define _CONSOLE_HPP_
#include <iostream>

inline void 
clrcon()
{
#if _WIN32
  system("cls");
#else
  system("clear");
#endif
}

#endif // _CONSOLE_HPP_
