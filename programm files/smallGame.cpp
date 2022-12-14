#include <iostream>
#include <ctime>
#include <cstdlib>
#include "playerClass.h"
#include "map.h"
#include "functionsMain.h"
#include "enemyClass.h"

using namespace std;

int main() 
{
	float score = 0.0; //score is a float because we did not have a float which is mandatory

	srand(time(NULL));

	bool mapMode = true;
	bool menuMode = false;
	bool combatMode = false;
	bool bossFight = false;

	showTutorial();
	system("CLS");

	Player player1; //create player
	player1.spawnPlayer(); //set player initial coordinates
	spawnKey(player1.getPlayerX(), player1.getPlayerY()); // spawn key in a diferent place of where player is
	spawnBoss(); //set boss coordinates
	int floor = 1;

	while (player1.getLives() > 0)
	{
		while (mapMode)
		{
			const char CHANGETOMENUMODE = '1';
			printMap(player1.getPlayerX(), player1.getPlayerY(), floor, score, player1.getLives());
			char input;
			cin >> input;
			if (input == CHANGETOMENUMODE) 
			{
				menuMode = true; //change to menu mode
				mapMode = false;
			}
			else
			{
				player1.movePlayer(input);
				if (checkBoss(player1.getPlayerX(), player1.getPlayerY())) //check if the player is in the same place as a boss
				{
					combatMode = true;
					mapMode = false;
					bossFight = true;
				}
				else if (initiateCombat()) //check if random combat start
				{
					mapMode = false;
					combatMode = true;
				}
			}
			system("CLS"); // clean screen
		}

		while (menuMode)
		{
			const char CHANGETOMAPMODE = '0';
			showMenuChoice(player1);
			char input;
			cin >> input;
			switch (input) 
			{
			case '0':
				menuMode = false; //change to map mode
				mapMode = true;
				break;
			case '1':
				showMenuStats(player1);
				break;
			case '2':
				showMenuSkills(player1);
				break;
			case '3':
				showTutorial();
				break;
			}
			system("CLS");
		}
		
		if (combatMode)
		{
			Enemy enemy1(bossFight, rand(), floor); //create a enemy

			while (combatMode)
			{
				
				showCombatText(enemy1, player1);

				char input;
				input = showCombatMenu(player1);
				
				if (input == BASICATTACK) // use basic attack
				{
					enemy1.takeDamage(player1.attack(), 0);
				}
				else if (input == SKILL1 || input == SKILL3) // use ofensive skills
				{
					enemy1.takeDamage(player1.useSkill(input), player1.apllyDot(input));
				}
				else if (input == SKILL2 || input == SKILL4) // use healing skills
				{
					player1.heal(player1.useSkill(input), player1.apllyHot(input));
				}

				if (enemy1.hasDot()) //check if enemy has damage over time
				{
					enemy1.takeDamageFromDot(); //apply damage over time
				}

				if (player1.hasHot()) //check if player has heal over time
				{
					player1.receiveHotHeal(); //apply heal over time
				}

				if (enemy1.getCurrentHp() <= 0) //check if enemy is dead
				{
					combatMode = false;  //go back to map mode
					mapMode = true;
					score = updateScore(score, bossFight, floor, enemy1.getExpReward()); //update score
					player1.earnExp(enemy1.getExpReward()); // give exp to player
					if (bossFight) //if finished the boss fight create a new floor
					{
						floor++;
						map[player1.getPlayerX()][player1.getPlayerY()] = '0'; //player is in the same place as the boss, that is why we use the player position to delete the current boss position.
						player1.spawnPlayer(); //set player coordinates
						player1.removeKeys(); //player loses his key
						spawnKey(player1.getPlayerX(), player1.getPlayerY()); //spaw new key
						spawnBoss(); //set new boss coordinates
					}
					system("cls");
					break;
				}

				player1.takeDamage(enemy1.attack()); //player receive attack from enemy

				if (player1.getCurrentHp() <= 0) // if player dead
				{
					combatMode = false; //go back to map mode
					mapMode = true;
					player1.dead();
				}

				system("cls");
			}
			bossFight = false; // turn of boss fight mode so next fight is normal again, it is here in case player dies
		}
	}
	showFinalMessage(score, floor);
	return 0;
}