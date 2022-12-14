#include "enemyClass.h"


int enemyList[5][5] = {
	{ 10 , 0 , 0 , 1 , 100 }, // goblin
	{ 15 , 0 , 0 , 2 , 150}, // skeleton
	{ 12 , 0 , 0 , 2 , 120}, // kobold
	{ 25 , 0 , 0 , 1 , 150}, // slime
	{ 20 , 0 , 0 , 3 , 300} }; // orc
//   hp   mp  int stg expReward
int bossList[3][5] = {
	{ 50 , 0 , 4 , 8 , 2000 }, //hobgoblin
	{ 200 , 0 , 0 , 2 , 2000}, //giant slime
	{ 120, 0 , 0 , 8 , 4000} }; //ogre 

enum stats
{
	MAXHP,
	MAXMP,
	INTELLIGENCE,
	STRENGTH,
	EXPREWARD
};

Enemy::Enemy(bool bossFight, int enemyId, int lv)
{
	if (!bossFight) //create a normal enemy
	{
		enemyId = enemyId % 5; //making the randon number go to the size of the enemy list
		this->lv = lv; // lv will be the floor number
		this->currentHp = lv * enemyList[enemyId][MAXHP];              //uses the list of stats
		this->maxHp = lv * enemyList[enemyId][MAXHP];                  //and the lv to create the 
		this->currentMp = lv * enemyList[enemyId][MAXMP];              //enemy real stats
		this->maxMp = lv * enemyList[enemyId][MAXMP];
		this->intelligence = lv * enemyList[enemyId][INTELLIGENCE];
		this->strength = lv * enemyList[enemyId][STRENGTH];
		this->expReward = lv * enemyList[enemyId][EXPREWARD];
		switch (enemyId) //giving names and descriptions to each enemy by their id
		{
		case 0:
		{
			this->name = "Goblin";
			this->description = "A green goblin is approaching, wielding a small club. \nHe is laughing savagely.\n";
			break;
		}
		case 1:
		{
			this->name = "Skeleton";
			this->description = "A skeleton comes with a rattle.\nHe seems to want to rip you apart.\n";
			break;
		}
		case 2:
		{
			this->name = "Kobold";
			this->description = "A kobold has a spear and a shield. \nHe is looking at you annoyed.\n";
			break;
		}
		case 3:
		{
			this->name = "Slime";
			this->description = "A soft-looking slime is bouncing around his body. \nHe is shuddering a little because he is afraid of being split by you.\n";
			break;
		}
		case 4:
		{
			this->name = "Orc";
			this->description = "An orc smiles meanly and wields a weapon. \n'A coward.' He smirks.\n";
			break;
		}
		default:
			break;
		}
	}
	else //create a boss enemy
	{
		enemyId = enemyId % 3; //making the randon number go to the size of the boss list
		this->lv = lv;  // lv will be the floor number
		this->currentHp = lv * bossList[enemyId][MAXHP];             //uses the list of stats
		this->maxHp = lv * bossList[enemyId][MAXHP];                 //and the lv to create the 
		this->currentMp = lv * bossList[enemyId][MAXMP];             //enemy real stats
		this->maxMp = lv * bossList[enemyId][MAXMP];
		this->intelligence = lv * bossList[enemyId][INTELLIGENCE];
		this->strength = lv * bossList[enemyId][STRENGTH];
		this->expReward = lv * bossList[enemyId][EXPREWARD];
		switch (enemyId) //giving names and descriptions to each boss by their id
		{
		case 0:
		{
			this->name = "Hobgoblin";
			this->description = "A muscular hopgoblin is smirking at you. \nIt doesn't seem like a good match.\n";
			break;
		}
		case 1:
		{
			this->name = "Giant Slime";
			this->description = "A giant slime doesn't shudder anymore. \nHe is preparing to crush and squash you.";
			break;
		}
		case 2:
		{
			this->name = "Ogre";
			this->description = "An ogre is spring out at you and raising his weapon.\n There is blood all over his body and weapons.";
			break;
		}
		default:
			break;
		}
	}
}

int Enemy::getCurrentHp()
{
	return this->currentHp;
}

int Enemy::getMaxHp()
{
	return this->maxHp;
}

int Enemy::getCurrentMp()
{
	return this->currentMp;
}

int Enemy::getMaxMp()
{
	return this->maxMp;
}

int Enemy::getIntelligence()
{
	return this->intelligence;
}

int Enemy::getStrength()
{
	return this->strength;
}

int Enemy::getLv()
{
	return this->lv;
}

int Enemy::getExpReward()
{
	return this->expReward;
}

void Enemy::takeDamage(int damageTaken, int dotDamage)
{
	this->currentHp -= damageTaken; //take damage
	this->receiveDot(dotDamage); //if there is a dot in the attack create a dot in enemy
}

int Enemy::attack()
{
	return this->strength; //damage of the attack is equal to str
}

void Enemy::receiveDot(int value)
{
	if (value > 0) //if dot has damage
	{
		this->dotDuration = 3; //all dots and hots have 3 turns of duration
		this->dotDamage = value; //creates the damage related to the dot
	}
}

int Enemy::getDotDamage()
{
	return this->dotDamage;
}

int Enemy::getDotDuration()
{
	return this->dotDuration;
}

void Enemy::takeDamageFromDot()
{
	this->currentHp -= this->dotDamage; //take dot damage
	this->dotDuration--; //reduce duration of dot
	if (this->dotDuration <= 0) //if the dot has ended 
	{
		this->dotDamage = 0; //no dot damage
	}
}

bool Enemy::hasDot()
{
	if (this->dotDamage > 0) //check of the enemy is affected by a dot
	{
		return true;
	}
	else
	{
		return false;
	}
}

std::string Enemy::getName()
{
	return this->name;
}

std::string Enemy::getDescription()
{
	return this->description;
}