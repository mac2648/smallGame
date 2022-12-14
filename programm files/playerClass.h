#pragma once
#include "skillsClass.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include "map.h"

const char BASICATTACK = '1';
const char SKILL1 = '2';
const char SKILL2 = '3';
const char SKILL3 = '4';
const char SKILL4 = '5';

class Player 
{
	int currentHp;
	int maxHp;
	int currentMp;
	int maxMp;
	short lives;
	int intelligence;
	int strength;
	int lv;
	int exp;
	int expForNextLv;
	short playerX;
	short playerY;
	bool playerHasTheKeys = false;
	Skill skill1;
	Skill skill2;
	Skill skill3;
	Skill skill4;
	int hotHeal = 0;
	int hotDuration = 0;

public:
	Player();
	int getCurrentHp();
	int getMaxHp();
	int getCurrentMp();
	int getMaxMp();
	short getLives();
	int getIntelligence();
	int getStrength();
	int getLv();
	int getExp();
	int getExpForNextLv();
	void spawnPlayer();
	short getPlayerX();
	short getPlayerY();
	void movePlayer(char input);
	void givePlayerKeys();
	bool getPlayerHasTheKeys();
	int attack();
	void earnExp(int earnedExp);
	void lvUp();
	void dead();
	void takeDamage(int damageTaken);
	void passiveRecover();
	void makeSureCurrentHpIsSmallerThanMaxHp();
	void makeSureCurrentMpIsSmallerThanMaxMp();
	void removeKeys();
	void createSkill1(int skillId);
	int useSkill(char skillNumber);
	void createSkill2(int skillId);
	void createSkill3(int skillId);
	void createSkill4(int skillId);
	std::string getSkillName(int skillNumber);
	void heal(int value, int hotValue);
	int apllyDot(int skillNumber);
	bool hasEnoughMana(int manaCost);
	void receiveHot(int hotValue);
	void receiveHotHeal();
	bool hasHot();
	int apllyHot(char input);
	int getHotHeal();
	int getHotDuration();
	int getSkillDamage(int skillNumber);
	int getSkillLv(int skillNumber);
	int getSkillHeal(int skillNumber);
	int getSkillDot(int skillNumber);
	int getSkillHot(int skillNumber);
	int getSkillMpCost(int skillNumber);
};