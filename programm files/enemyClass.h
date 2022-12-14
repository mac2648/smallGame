#pragma once
#include <iostream>

extern int enemyList[5][5];
extern int bossList[3][5];

class Enemy 
{
private:
	std::string name;
	std::string description;
	int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
	int intelligence;
	int strength;
	int lv;
	int expReward;
	int dotDamage = 0;
	int dotDuration = 0;

public:
	Enemy(bool bossFight, int enemyId, int lv);
	int getCurrentHp();
	int getMaxHp();
	int getCurrentMp();
	int getMaxMp();
	int getIntelligence();
	int getStrength();
	int getLv();
	int getExpReward();
	void takeDamage(int damageTaken, int dotDamage);
	int attack();
	void receiveDot(int value);
	int getDotDamage();
	int getDotDuration();
	void takeDamageFromDot();
	bool hasDot();
	std::string getName();
	std::string getDescription();
};