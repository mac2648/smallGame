#pragma once
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "enemyClass.h"
#include "playerClass.h"


bool initiateCombat();
void showCombatText(Enemy enemy1, Player player1);
void showMenuStats(Player player1);
void showMenuChoice(Player player1);
void showMenuSkills(Player player1);
void showTutorial();
char showCombatMenu(Player player1);
void showFinalMessage(float score, int floor);
float updateScore(float oldScore, bool bossfight, int floor, int expReceived);