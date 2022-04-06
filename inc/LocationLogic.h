#pragma once
#include <string>
#include <vector>
#include "Hero.h"
class StateMachine;

void LocationChoice(short& gch);

void GoOnLoc(Hero& hero, std::string loc, StateMachine* sm);

void ErrorFindLocation();
