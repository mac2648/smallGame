#pragma once
#include <iostream>

extern int baseSkillStatsList[5][5];
enum SkillBaseStats
{
	BASEMPCOST,
	BASEDAMAGE,
	BASEDAMAGEOVERTIME,
	BASEHEAL,
	BASEHEALOVERTIME
};

class Skill {
private:
	std::string name;
	int baseMpCost = 0;
	int mpCost = 0;
	int baseDamage = 0;
	int damage = 0;
	int baseDamageOverTime = 0;
	int damageOverTime = 0;
	int baseHeal = 0;
	int heal = 0;
	int baseHealOverTime = 0;
	int healOverTime = 0;
	int lv = 1;
public:
	int getMpCost();
	int getDamage();
	int getDamageOverTime();
	int getHeal();
	int getHealOverTime();
	int getLv();
	void createSkill(int skillId);
	std::string getName();
	void lvUp();
};