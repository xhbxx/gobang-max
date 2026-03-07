#pragma once 
#include"board.h"
#include<vector>
#include<iostream>
#include<climits>
#include<algorithm>
#include<string>
#include<map>
#include <ctime> 

using namespace std;

extern int attack;
extern vector<pair<string, double>> score;
extern int cot;
void aiMove(int depth, int realboard[15][15], int aiColor);
double minmax(int depth, int board[15][15], int Color, int r, int l, double alpha, double beta);
double evaluate(int board[15][15], int Color, int r, int l);
string getchess(int board[15][15], int direction, int r, int l, int Color);
int getpiece(int board[15][15], int direction, int y, int x, int offset);
bool checkposition(string position, vector<string> model);
vector<pair<int, int>> moverange(int board[15][15]);
void show();
double evaluateall();
int countnear(int r, int l);
bool start();