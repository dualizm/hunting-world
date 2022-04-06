#include "Sms.h"
#include "SupportFunctions.h"
#include "console.hpp"
#include <unistd.h>

void Sms(std::string s)
{
  clrcon();
	Footnote();
	std::cout << " " << s << std::endl;
	sleep(1);
}
