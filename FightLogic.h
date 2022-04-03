#pragma once
#include <string>
class Hero;
class StateMachine;

void Fight(Hero& hero, std::string loc, StateMachine* sm);
