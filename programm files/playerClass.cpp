#include "playerClass.h"

using namespace std;

int Player::getCurrentHp()
{
	return this->currentHp;
}

int Player::getMaxHp() 
{
	return this->maxHp;
}
int Player::getCurrentMp()
{
	return this->currentMp;
}
int Player::getMaxMp()
{
	return this->maxMp;
}

short Player::getLives()
{
	return this->lives;
}

int Player::getIntelligence()
{
	return this->intelligence;
}

int Player::getStrength()
{
	return this->strength;
}

int Player::getLv()
{
	return this->lv;
}

int Player::getExp()
{
	return this->exp;
}

int Player::getExpForNextLv()
{
	return this->expForNextLv;
}

// 플레이어 스폰하는 함수. please no korean comments
void Player::spawnPlayer() 
{
	int randomPosition = rand() % 4; // create a random number from 0 to 3
	enum POSITIONS { //list of possible positions for player spawn
		BOTTOMRIGHT, 
		BOTTTOMLEFT,
		TOPRIGHT,
		TOPLEFT
	};

	switch (randomPosition) // will set the player position based on the random number generated
	{
	case BOTTOMRIGHT:
	{
		this->playerX = 17;
		this->playerY = 17;
		break;
	}
	case BOTTTOMLEFT:
	{
		this->playerX = 17;
		this->playerY = 2;
		break;
	}
	case TOPRIGHT:
	{
		this->playerX = 2;
		this->playerY = 17;
		break;
	}
	case TOPLEFT:
	{
		this->playerX = 2;
		this->playerY = 2;
		break;
	}
	}
}

short Player::getPlayerX()
{
	return this->playerX;
}

short Player::getPlayerY()
{
	return this->playerY;
}

void Player::movePlayer(char input)
{
	const char UP = 'w';
	const char LEFT = 'a';
	const char DOWN = 's';
	const char RIGHT = 'd';

	switch (input)
	{
	case UP:
	{
		if (checkNoWall(this->playerX - 1, this->playerY, this->getPlayerHasTheKeys())) // check if there is a wall where the player is going
		{
			if (thereIsKey(this->playerX - 1, this->playerY)) // check if there is a key where player is going
			{
				givePlayerKeys(); //receive keys
			}
			this->playerX--; //move player
		}
		break;
	}

	case LEFT: //all cases are similar just change the direction of where the player is going
	{
		if (checkNoWall(this->playerX, this->playerY - 1, this->getPlayerHasTheKeys()))
		{
			if (thereIsKey(this->playerX, this->playerY - 1))
			{
				givePlayerKeys();
			}
			this->playerY--;
		}
		break;
	}

	case DOWN:
	{
		if (checkNoWall(this->playerX + 1, this->playerY, this->getPlayerHasTheKeys()))
		{
			if (thereIsKey(this->playerX + 1, this->playerY))
			{
				givePlayerKeys();
			}
			this->playerX++;
		}
		break;
	}

	case RIGHT:
	{
		if (checkNoWall(this->playerX, this->playerY + 1, this->getPlayerHasTheKeys()))
		{
			if (thereIsKey(this->playerX, this->playerY + 1))
			{
				givePlayerKeys();
			}
			this->playerY++;
		}
		break;
	}
	}
	this->passiveRecover(); //player recover HP and MP for moving
}

void Player::givePlayerKeys()
{
	this->playerHasTheKeys = true;
}

bool Player::getPlayerHasTheKeys()
{
	return this->playerHasTheKeys;
}

int Player::attack()
{
	return this->strength;
}

void Player::earnExp(int earnedExp)
{
	this->exp += earnedExp; //player receive exp
	if (this->exp >= this->expForNextLv) //check if player can lv up
	{
		this->lvUp(); //player lv up
	}
}

void Player::lvUp()
{
	while (this->exp >= this->expForNextLv) //in case player is leveling up more than once in a fight
	{
		const char STRENGTH = '1';
		const char INTELLIGENCE = '2';

		//takes out exp and add in the stats
		this->exp -= this->expForNextLv;
		this->lv++;
		this->expForNextLv += 100;
		this->maxHp += 5;
		this->maxMp += 5;
		this->currentHp += 5;
		this->currentMp += 5;

		if (this->lv == 5) // learn skill 2 at lv 5
		{
			this->createSkill2(1);
		}
		else if (this->lv == 10) //learn skill 3 at lv 10
		{
			this->createSkill3(2);
		}
		else if (this->lv == 15) //learn skill 4 at lv 15
		{
			this->createSkill4(3);
		}

		char choice = '0';
		do
		{
			cout << "you can inprove your strength (1) or your intelligence (2)" << endl << endl;
			cin >> choice;
		} while (choice != STRENGTH && choice != INTELLIGENCE); //make sure player has to choose int or str

		switch (choice) //give stg or int depending on player choice
		{
		case STRENGTH:
		{
			this->strength++;
			break;
		}
		case INTELLIGENCE:
		{
			this->intelligence++;
			break;
		}
		default:
			break;
		}

		if (this->lv % 3 == 0) // every 3 levels player can upgrade a skill
		{
			do
			{
				cout << "you can level up one skill, please enter a number from 1 to 4" << endl << endl;
				cin >> choice;
			} while (choice < '1' || choice > '4');  // make sure one skill is being upgraded

			switch (choice) //lv up the chosen skill
			{
			case '1':
			{
				this->skill1.lvUp();
				break;
			}
			case '2':
			{
				this->skill2.lvUp();
				break;
			}
			case '3':
			{
				this->skill3.lvUp();
				break;
			}
			case '4':
			{
				this->skill4.lvUp();
				break;
			}
			default:
				break;
			}
		}
	}
}

void Player::dead() //player lose a life and recover hp and mp to max
{
	this->lives--;
	this->currentHp = this->maxHp;
	this->currentMp = this->maxMp;
}

void Player::takeDamage(int damageTaken)
{
	this->currentHp -= damageTaken;
}

void Player::passiveRecover() //Hp and Mp recovered every time player move
{
	this->currentHp++;
	this->currentMp++;
	this->makeSureCurrentHpIsSmallerThanMaxHp(); //will not allow player to have more hp than max hp
	this->makeSureCurrentMpIsSmallerThanMaxMp();//will not allow player to have more mp than max mp
}

void Player::makeSureCurrentHpIsSmallerThanMaxHp()
{
	if (this->currentHp > this->maxHp) // if player has more hp than max
	{
		this->currentHp = this->maxHp; // current hp will go back max hp
	}
}

void Player::makeSureCurrentMpIsSmallerThanMaxMp()
{
	if (this->currentMp > this->maxMp) // if player has more mp than max
	{
		this->currentMp = this->maxMp; // current mp will go back max mp
	}
}

void Player::removeKeys()
{
	this->playerHasTheKeys = false;
}

void Player::createSkill1(int skillId)
{
	this->skill1.createSkill(skillId);
}

int Player::useSkill(char skillNumber)
{
	switch (skillNumber)
	{
	case SKILL1:
	{
		if (this->hasEnoughMana(this->skill1.getMpCost())) // make sure that player was enough mp
		{
			this->currentMp -= this->skill1.getMpCost(); //take out mp cost of the skill
			int damage = this->intelligence + this->skill1.getDamage(); //calculate damage
			return damage;
		}
		else
		{
			return 0;
		}
	}
	case SKILL2:
	{
		if (this->hasEnoughMana(this->skill2.getMpCost())) // make sure that player was enough mp
		{
			this->currentMp -= this->skill2.getMpCost(); //take out mp cost of the skill
			int heal = this->intelligence + this->skill2.getHeal(); //calculate healing
			return heal;
		}
		else
		{
			return 0;
		}
	}
	case SKILL3:
	{
		if (this->hasEnoughMana(this->skill3.getMpCost())) // make sure that player was enough mp
		{
			this->currentMp -= this->skill3.getMpCost(); //take out mp cost of the skill
			int damage = this->intelligence + this->skill3.getDamage(); //calculate damage
			return damage;
		}
		else
		{
			return 0;
		}
	}
	case SKILL4:
	{
		if (this->hasEnoughMana(this->skill4.getMpCost())) // make sure that player was enough mp
		{
			this->currentMp -= this->skill4.getMpCost(); //take out mp cost of the skill
			int heal = this->intelligence + this->skill4.getHeal(); //calculate healing
			return heal;
		}
		else
		{
			return 0;
		}
	}
	default:
		break;
	}
}

Player::Player() // player constructor
{
	currentHp = 50;
	maxHp = 50;
	currentMp = 50;
	maxMp = 50;
	lives = 3;
	intelligence = 1;
	strength = 1;
	lv = 1;
	exp = 0;
	expForNextLv = 100;
	playerX = -1;
	playerY = -1;
	playerHasTheKeys = false;
	createSkill1(0);
	createSkill2(4);
	createSkill3(4);
	createSkill4(4);
}

void Player::createSkill2(int skillId)
{
	this->skill2.createSkill(skillId);
}

void Player::createSkill3(int skillId)
{
	this->skill3.createSkill(skillId);
}

void Player::createSkill4(int skillId)
{
	this->skill4.createSkill(skillId);
}

std::string Player::getSkillName(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getName();
	}
	case 2:
	{
		return this->skill2.getName();
	}
	case 3:
	{
		return this->skill3.getName();
	}
	case 4:
	{
		return this->skill4.getName();
	}
	}
}

void Player::heal(int value, int hotValue) 
{
	this->currentHp += value; //receive heal
	this->makeSureCurrentHpIsSmallerThanMaxHp(); //don't allow player to have more hp than max hp
	this->receiveHot(hotValue); //will give a heal over time to player if there is a heal over time value
}

int Player::apllyDot(int skillNumber) //return a value used to giving a damage over time for the enemy
{
	if (skillNumber == SKILL3)
	{
		return (this->intelligence/2 + this->skill3.getDamageOverTime()); //dot receive half intelligence bonus
	}
	else
	{
		return 0;
	}
}

bool Player::hasEnoughMana(int manaCost) //check if player has enough mana
{
	if (this->currentMp >= manaCost)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Player::receiveHotHeal()
{
	this->currentHp += this->hotHeal; //heal for the value of the hot
	this->makeSureCurrentHpIsSmallerThanMaxHp(); //don't allow player to have more hp than max hp
	this->hotDuration--;
	if (this->hotDuration <= 0) //if hot has ended make the healing equal to 0
	{
		this->hotHeal = 0;
	}
}

void Player::receiveHot(int value) //create a hot for the player
{
	if (value > 0)
	{
		this->hotDuration = 3; //dots and hots duration are always 3 turns
		this->hotHeal = value; //give the heal over time a value received
	}
}

bool Player::hasHot()
{
	if (this->hotHeal > 0) //if heal over time is bigger than 0 it means that player has a hot
	{
		return true;
	}
	else
	{
		return false;
	}
}

int Player::apllyHot(char input) //returns the value for applying the heal over time
{
	if (input == SKILL4)
	{
		int healvalue = this->skill4.getHealOverTime() + this->getIntelligence() / 2; //hot receive half int bonus
		return healvalue;
	}
	else
	{
		return 0;
	}
}

int Player::getHotHeal()
{
	return this->hotHeal;
}

int Player::getHotDuration()
{
	return this->hotDuration;
}

int Player::getSkillDamage(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getDamage();
	}
	case 2:
	{
		return this->skill2.getDamage();
	}
	case 3:
	{
		return this->skill3.getDamage();
	}
	case 4:
	{
		return this->skill4.getDamage();
	}
	}
}

int Player::getSkillLv(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getLv();
	}
	case 2:
	{
		return this->skill2.getLv();
	}
	case 3:
	{
		return this->skill3.getLv();
	}
	case 4:
	{
		return this->skill4.getLv();
	}
	}
}

int Player::getSkillHeal(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getHeal();
	}
	case 2:
	{
		return this->skill2.getHeal();
	}
	case 3:
	{
		return this->skill3.getHeal();
	}
	case 4:
	{
		return this->skill4.getHeal();
	}
	}
}

int Player::getSkillDot(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getDamageOverTime();
	}
	case 2:
	{
		return this->skill2.getDamageOverTime();
	}
	case 3:
	{
		return this->skill3.getDamageOverTime();
	}
	case 4:
	{
		return this->skill4.getDamageOverTime();
	}
	}
}

int Player::getSkillHot(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getHealOverTime();
	}
	case 2:
	{
		return this->skill2.getHealOverTime();
	}
	case 3:
	{
		return this->skill3.getHealOverTime();
	}
	case 4:
	{
		return this->skill4.getHealOverTime();
	}
	}
}

int Player::getSkillMpCost(int skillNumber)
{
	switch (skillNumber)
	{
	case 1:
	{
		return this->skill1.getMpCost();
	}
	case 2:
	{
		return this->skill2.getMpCost();
	}
	case 3:
	{
		return this->skill3.getMpCost();
	}
	case 4:
	{
		return this->skill4.getMpCost();
	}
	}
}
