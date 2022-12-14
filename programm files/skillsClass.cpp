#include "skillsClass.h"

int baseSkillStatsList[5][5] = 
{
{3, 4, 0, 0, 0}, // fire ball
{3, 0, 0, 8, 0}, // heal
{5, 2, 2, 0, 0}, // burn
{5, 0, 0, 3, 5}, // regen
{0, 0, 0, 0, 0} // literal nothing used to create empty skills
};

int Skill::getMpCost()
{
	return this->mpCost;
}

int Skill::getDamage()
{
	return this->damage;
}

int Skill::getDamageOverTime()
{
	return this->damageOverTime;
}

int Skill::getHeal()
{
	return this->heal;
}

int Skill::getHealOverTime()
{
	return this->healOverTime;
}

int Skill::getLv()
{
	return this->lv;
}

void Skill::createSkill(int skillId)
{
	//take the values for the skill from the skill stats list 
	this->baseMpCost = baseSkillStatsList[skillId][BASEMPCOST];
	this->baseDamage = baseSkillStatsList[skillId][BASEDAMAGE];
	this->baseDamageOverTime = baseSkillStatsList[skillId][BASEDAMAGEOVERTIME];
	this->baseHeal = baseSkillStatsList[skillId][BASEHEAL];
	this->baseHealOverTime = baseSkillStatsList[skillId][BASEHEALOVERTIME];
	this->mpCost = baseSkillStatsList[skillId][BASEMPCOST];
	this->damage = baseSkillStatsList[skillId][BASEDAMAGE];
	this->damageOverTime = baseSkillStatsList[skillId][BASEDAMAGEOVERTIME];
	this->heal = baseSkillStatsList[skillId][BASEHEAL];
	this->healOverTime = baseSkillStatsList[skillId][BASEHEALOVERTIME];

	switch (skillId) //give a name for the skill based on the Id
	{
	case 0:
	{
		this->name = "fireball";
		break;
	}
	case 1:
	{
		this->name = "heal";
		break;
	}
	case 2:
	{
		this->name = "burn";
		break;
	}
	case 3:
	{
		this->name = "regen";
		break;
	}
	case 4:
	{
		this->name = "nothing";
		break;
	}
	default:
		break;
	}
}

std::string Skill::getName()
{
	return this->name;
}

void Skill::lvUp()
{
	//every time a skill receives a lv up it receive a incrise in all stats (lv is an exception) equal to the base stats
	// to do that we just multiply the base values by the lv
	this->lv++;
	this->mpCost = this->baseMpCost * this->lv;
	this->damage = this->baseDamage * this->lv;
	this->damageOverTime = this->baseDamageOverTime * this->lv;
	this->heal = this->baseHeal * this->lv;
	this->healOverTime = this->baseHealOverTime * this->lv;
}