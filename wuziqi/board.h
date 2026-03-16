#pragma once
#include <graphics.h>

using namespace std;

const int BOARD_SIZE = 15;
const int CELL = 30;
const int MARGIN = 40;
const int EMPTY = 0;
const int B = 1;
const int W = 2;

extern int Board[BOARD_SIZE][BOARD_SIZE];
extern bool isGameOver;

extern int playerColor;
extern int aiColor;

void initBoard();
void drawBoard();
void drawPiece(int row, int col, int color);
bool isValidPos(int row, int col);
bool checkWin(int row, int col, int color);
void getMouseRowCol(int& row, int& col);

