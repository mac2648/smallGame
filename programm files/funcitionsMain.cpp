#include "functionsMain.h"
using namespace std;


bool initiateCombat()
{
	int randonChance = rand() % 3;// 1/3 of chance to initiate combat 

	if (randonChance == 0)
	{
		return true; //initiate combat
	}
	else
	{
		return false; //don't iniciate combat
	}
}

void showCombatText(Enemy enemy1, Player player1) 
{
	cout << "<Combat> ==================================================" << endl << endl;
	//cout << enemy1.getName() << endl;
	cout << enemy1.getDescription() << endl;

	if (enemy1.getName() == "Skeleton" || enemy1.getName() == "Hobgoblin" || enemy1.getName() == "Giant Slime")
	{ //these have a big name and need a "\t" less than the other enemies
		cout << "-----------------------------------------------------------" << endl;
		cout << enemy1.getName() << "\t|  HP : " << enemy1.getCurrentHp() << "/" << enemy1.getMaxHp() << endl;
		cout << "\t\t|  Dot Damage : " << enemy1.getDotDamage() << "\tDot Duration : " << enemy1.getDotDuration() << endl;
		cout << "-----------------------------------------------------------" << endl;
	}
	else 
	{ //need two "\t"
		cout << "-----------------------------------------------------------" << endl;
		cout << enemy1.getName() << "\t\t|  HP : " << enemy1.getCurrentHp() << "/" << enemy1.getMaxHp() << endl;
		cout << "\t\t|  Dot Damage : " << enemy1.getDotDamage() << "\tDot Duration : " << enemy1.getDotDuration() << endl;
		cout << "-----------------------------------------------------------" << endl;
	}

	//show player stats
	cout << "-----------------------------------------------------------" << endl;
	cout << "You" << "\t\t|  HP :" << player1.getCurrentHp() << "/" << player1.getMaxHp() << "\t\tMP : " << player1.getCurrentMp() << "/" << player1.getMaxMp() << endl;
	cout << "\t\t|  Hot heal : " << player1.getHotHeal() << "\t\tHot Duration : " << player1.getHotDuration() << endl;
	cout << "-----------------------------------------------------------\n" << endl;

}

void showMenuChoice(Player player1) //show the choices fo the menu
{
	cout << "0 - resume (Go back to Map)" << endl;
	cout << "1 - Stats" << endl;
	cout << "2 - Skills" << endl;
	cout << "3 - Tutorial" << endl;
}

void showMenuStats(Player player1) //show the stats menu
{
	cout << "\n<STATS>==============================================\n" << endl;
	cout << "Level \t\t\t\t" << player1.getLv() << endl;
	cout << "Lives \t\t\t\t" << player1.getLives() << endl;
	cout << "HP \t\t\t\t" << player1.getCurrentHp() << "/" << player1.getMaxHp() << endl;
	cout << "MP \t\t\t\t" << player1.getCurrentMp() << "/" << player1.getMaxMp() << endl;
	cout << "Strength \t\t\t" << player1.getStrength() << endl;
	cout << "Intelligence \t\t\t" << player1.getIntelligence() << endl;
	cout << "Exp \t\t\t\t" << player1.getExp() << " / " << player1.getExpForNextLv() << endl << endl;

	cout << "Your Position : (" << player1.getPlayerX() << ", " << player1.getPlayerY() << ")" << endl;

	if (player1.getPlayerHasTheKeys() == true) 
	{
		cout << "You have a key." << endl;
	}
	else
	{
		cout << "You don't have a key." << endl;
	}

	cout << "If you want to resume, press '0'" << endl;

	int check;
	cin >> check;

	while (check != 0) 
	{
		cin >> check;
	}
}

void showMenuSkills(Player player1) //shows the skills menu
{
	cout << "\n<SKILL> =================================================================================\n" << endl;
	cout << "Skill 1 " << player1.getSkillName(1) << "---------------------------------------------------------------" << endl;
	cout << "\tMP Cost : " << player1.getSkillMpCost(1) << "\tDamage : " << player1.getSkillDamage(1) + player1.getIntelligence() << "\tDamage Over Time : " << player1.getSkillDot(1) << endl;
	cout << "\tLevel : " << player1.getSkillLv(1) << "\tHealing : " << player1.getSkillHeal(1) << "\tHealing Over Time : " << player1.getSkillHot(1) << endl << endl;

	cout << "Skill 2 " << player1.getSkillName(2) << "---------------------------------------------------------------" << endl;
	cout << "\tMP Cost : " << player1.getSkillMpCost(2) << "\tDamage : " << player1.getSkillDamage(2) << "\tDamage Over Time : " << player1.getSkillDot(2) << endl;
	cout << "\tLevel : " << player1.getSkillLv(2) << "\tHealing : " << player1.getSkillHeal(2) + player1.getIntelligence() << "\tHealing Over Time : " << player1.getSkillHot(2) << endl << endl;

	cout << "Skill 3 " << player1.getSkillName(3) << "---------------------------------------------------------------" << endl;
	cout << "\tMP Cost : " << player1.getSkillMpCost(3) << "\tDamage : " << player1.getSkillDamage(3) + player1.getIntelligence() << "\tDamage Over Time : " << player1.getSkillDot(3) + player1.getIntelligence()/2 << endl;
	cout << "\tLevel : " << player1.getSkillLv(3) << "\tHealing : " << player1.getSkillHeal(3) << "\tHealing Over Time : " << player1.getSkillHot(3) << endl << endl;

	cout << "Skill 4 " << player1.getSkillName(4) << "---------------------------------------------------------------" << endl;
	cout << "\tMP Cost : " << player1.getSkillMpCost(4) << "\tDamage : " << player1.getSkillDamage(4) << "\tDamage Over Time : " << player1.getSkillDot(4) << endl;
	cout << "\tLevel : " << player1.getSkillLv(4) << "\tHealing : " << player1.getSkillHeal(4) + player1.getIntelligence() << "\tHealing Over Time : " << player1.getSkillHot(4) + player1.getIntelligence()/2 << endl << endl;


	cout << "If you want to resume, press '0'" << endl;

	int check;
	cin >> check;

	while (check != 0)
	{
		cin >> check;
	}
}

void showTutorial()
{
	cout << "\n<TUTORIAL> ====================================================================================================\n" << endl;
	cout << "Welcome to the world. It's very great honor to greet you here.\n" << endl;
	cout << "In this world, you can go higher and higher." << endl;
	cout << "Along the way, you can meet some enemies. Such as some goblins, orcs, and slimes..." << endl;
	cout << "The higher you are, the stronger the enemies and boss. You had better be stronger and you can be!" << endl;
	cout << "When you kill the enemies, you can get Exps and it makes you stronger and it gives you a new skill! \n" << endl;
	cout << "To make you excited, some rooms need a key to enter. \nFollow the way and get the key! Key is snow white, it represents the importance!\n" << endl;
	cout << "You know, some bosses are reeeaaaally strong! Be careful, but it is worthy to kill them." << endl;
	cout << "\nPlease enjoy your journey. I hope you can enjoy the world too!" << endl;
	cout << "See you next time. Bye.\n\n" << endl;
	cout << "<GAME RULES> ====================================================================================================\n" << endl;
	cout << "when you are in the map:\n" << endl;
	cout << "enter 'w' 'a' 's' 'd' to move, or '1' to go to the menu" << endl;
	cout << "every time you move you may trigger a random combat" << endl;
	cout << "there is a key every floor indicated in white in the map" << endl;
	cout << "to go through the doors, indicated in light blue, you need to have the key" << endl;
	cout << "the boss of each floor is the yellow marker in the map, killing it will send you to the next floor\n" << endl;
	cout << "when you are in combat:\n" << endl;
	cout << "in combat you will have a few options of actions to make" << endl;
	cout << "be aware that if you enter anything that is not in the actions list you are going to do nothing in that turn" << endl;
	cout << "if you die in combat you will lose a life, the game ends if you have 0 lives\n" << endl;
	cout << "stats:\n" << endl;
	cout << "the damage that you cause with basic attacks is equal to your strength" << endl;
	cout << "1 intelligence gives +1 damage or heal to magics (depending if they have damage or heal)" << endl;
	cout << "2 points of intelligence give +1 for effects over time (DOTs and HOTs)\n" << endl;
	cout << "every level up you will receive 1 point to put between the two" << endl;
	cout << "you will receive new skills at the levels 5, 10 and 15" << endl;
	cout << "every 3 levels you will be able to upgrade one skill that you have by one lv\n" << endl;
	cout << "the score is calculated based on the exp received, the floor and if the enemy was a boss or not\n" << endl;

	cout << "If you want to resume, press '0'" << endl;

	int check;
	cin >> check;

	while (check != 0)
	{
		cin >> check;
	}
}


char showCombatMenu(Player player1) //shows skills options for the player in combat
{
	char input;
	while (1)
	{
		cout << "1 to attack" << endl;
		cout << "2 to use " << player1.getSkillName(1) << "(MP Cost : " << player1.getSkillMpCost(1) << ")" << endl;
		cout << "3 to use " << player1.getSkillName(2) << "(MP Cost : " << player1.getSkillMpCost(2) << ")" << endl;
		cout << "4 to use " << player1.getSkillName(3) << "(MP Cost : " << player1.getSkillMpCost(3) << ")" << endl;
		cout << "5 to use " << player1.getSkillName(4) << "(MP Cost : " << player1.getSkillMpCost(4) << ")" << endl;
		cin >> input;
		switch (input)
		{
		case '1':
		{
			return BASICATTACK;
		}
		case '2':
		{
			return SKILL1;
		}
		case '3':
		{
			return SKILL2;
		}
		case '4':
		{
			return SKILL3;
		}
		case '5':
		{
			return SKILL4;
		}
		}
	}
}

void showFinalMessage(float score, int floor)
{
	cout << "good try, your final score was: " << score << " at the floor: " << floor << endl << endl;
}

float updateScore(float oldScore, bool bossfight, int floor, int expReceived)
{
	const float EXPSCOREMULTIPLIER = 0.15; //modifiers for the score won
	const int BOSSMULTIPLIER = 3;
	float newScore;

	if (!bossfight) // score calculation normal fight
	{
		newScore = oldScore + (expReceived * EXPSCOREMULTIPLIER)*0.5*floor;
	}
	else // score calculation boss fight
	{
		newScore = oldScore + BOSSMULTIPLIER*(expReceived * EXPSCOREMULTIPLIER) * 0.5 * floor;
	}

	return newScore;
}