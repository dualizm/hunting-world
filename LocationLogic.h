#pragma once
#include <string>
#include <vector>
#include "Hero.h"

void LocationChoice(short& gch, std::vector<std::string> loclist);

void GoOnLoc(Hero& hero, std::string loc);