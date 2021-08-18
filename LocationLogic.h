#pragma once
#include <string>
#include <vector>
#include "Hero.h"

void LocationChoice(short& gch);

void GoOnLoc(Hero& hero, std::string loc);

void ErrorFindLocation();
