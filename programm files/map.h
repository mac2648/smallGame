#pragma once
#include "playerClass.h"

extern char map[20][20];
const char FREESPACE = '0';
const char WALL = '1';
const char DOOR = '2';
const char KEY = '3';
const char BOSS = '4';

void printMap(short playerX, short playerY, int floor, float score, short playerLives);
bool checkNoWall(short nextCoordinateX, short nextCoodinateY, bool playerHasTheKeys);
void spawnKey(short playerX, short playerY);
bool thereIsKey(short nextCoordinateX, short nextCoodinateY);
void spawnBoss();
bool checkBoss(short nextCoordinateX, short nextCoodinateY);



