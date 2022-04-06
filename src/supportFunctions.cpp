#include "SupportFunctions.h"
#include "Logic.h"

short checkInput()
{
    std::string str; std::cin >> str;
    if (str[0] >= '0' || str[0] <= '9') return str[0] - '0';
    else ErrorMessage();

    return 0;
}
